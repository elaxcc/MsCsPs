#include "stdafx.h"

#include "State.h"

#include "Parser.h"
#include "../SimpleData.h"
#include "../ArrayData.h"
#include "../ObjectData.h"

namespace GDS
{

namespace DataStorage
{

IState::IState(Parser *parser)
	: parser_(parser)
{

}

IState::~IState()
{

}

Parser* IState::get_parser()
{
	return parser_;
}

StateGetDataLength::StateGetDataLength(Parser *parser)
	: IState(parser)
{

}

StateGetDataLength::~StateGetDataLength()
{

}

std::vector<uint8_t>::const_iterator StateGetDataLength::process(
	const std::vector<uint8_t> &binary_data,
	std::vector<uint8_t>::const_iterator &pos)
{
	// first byte is data length, that also define data type
	parser_->set_data_type(*pos++);
	
	// next byte must be delimiter
	if (pos == binary_data.end()) //!fixme ������� ��� �������� �� �����!!! ������!!!
	{
		// can't find delimiter
		parser_->set_error(Parser::ErrorNoEnoughData);
		return ++pos;
	}

	// go to GetName state
	parser_->set_state(IStatePtr(new StateGetName(parser_)));

	return ++pos;
}

StateGetName::StateGetName(Parser *parser)
	: IState(parser)
	, is_array_(false)
	, array_size_(0)
{

}

StateGetName::~StateGetName()
{
	data_name_only_.clear();
}

std::vector<uint8_t>::const_iterator StateGetName::process(
	const std::vector<uint8_t> &binary_data,
	std::vector<uint8_t>::const_iterator &pos)
{
	// find delimiter between name and data
	std::vector<uint8_t>::const_iterator iter = pos;
	while (*iter != DataStorage::cDelimiterStr)
	{
		if (iter == binary_data.end())
		{
			// no enough data in name part of binary data
			parser_->set_error(Parser::ErrorNoEnoughData);
			return pos;
		}
		iter++;
	}

	// prepare data for name
	std::vector<uint8_t> name_whith_array_part(pos, iter);

	// check data for array
	if (check_name_for_array(name_whith_array_part))
	{
		if (parser_->get_error() == Parser::ErrorOk)
		{
			parser_->set_obj_array_type(array_size_);
		}
	}

	// check name
	if (check_name(data_name_only_))
	{
		if (parser_->get_error() == Parser::ErrorOk)
		{
			parser_->set_data_name(std::string(data_name_only_.begin(), data_name_only_.end()));
		}
	}

	// go to GetData state
	parser_->set_state(IStatePtr(new StateGetData(parser_)));

	return iter + 1; // return next byte after delimiter
}

bool StateGetName::check_name(const std::vector<uint8_t> &name)
{
	// first symbol in name can be '_' or alphabetic character
	if (!(isalpha(name[0]) || name[0] == '_'))
	{
		parser_->set_error(Parser::ErrorNameWrongFirstSymbol);
		return false;
	}

	// the over characters can be '_', alphabetic character or digit
	for (auto c : name)
	{
		if (!isalnum(c) && c != '_')
		{
			return false;
		}
	}

	return true;
}

bool StateGetName::check_name_for_array(const std::vector<uint8_t> &name)
{
	// find opening squared bracket
	bool find_open_bracket = false;
	std::vector<uint8_t>::const_iterator open_bracket_pos = name.begin();
	while (open_bracket_pos != name.end())
	{
		if (*open_bracket_pos == DataStorage::cOpenSquareBracketStr)
		{
			find_open_bracket = true;
			break;
		}
		open_bracket_pos++;
	}

	// check last byte in name for the matching closing squared bracket
	bool find_closing_bracket = false;
	if (*(name.end() - 1) == DataStorage::cCloseSquareBracketStr)
	{
		find_closing_bracket = true;
	}

	// check than both brackets exist
	if (find_open_bracket && !find_closing_bracket)
	{
		parser_->set_error(Parser::ErrorArrayAbsentCloseSquaredBracket);
	}
	if (!find_open_bracket && find_closing_bracket)
	{
		parser_->set_error(Parser::ErrorArrayAbsentOpenSquaredBracket);
	}
	is_array_ = find_open_bracket && find_closing_bracket;

	// get array size
	if (is_array_)
	{
		// check that between opening and closing brackets 4 bytes
		if ((name.end() - 2) - open_bracket_pos != 4)
		{
			parser_->set_error(Parser::ErrorArrayBytesBetweenBracketsWrong);
		}
		else
		{
			array_size_ = static_cast<unsigned int>(*(open_bracket_pos + 1));
			array_size_ |= static_cast<unsigned int>(*(open_bracket_pos + 2)) << 8;
			array_size_ |= static_cast<unsigned int>(*(open_bracket_pos + 3)) << 16;
			array_size_ |= static_cast<unsigned int>(*(open_bracket_pos + 4)) << 24;
		}
	}

	data_name_only_.insert(data_name_only_.end(), name.begin(), open_bracket_pos);
	
	return is_array_;
}

StateGetData::StateGetData(Parser *parser)
	: IState(parser)
{

}

StateGetData::~StateGetData()
{

}

std::vector<uint8_t>::const_iterator StateGetData::process(
	const std::vector<uint8_t> &binary_data,
	std::vector<uint8_t>::const_iterator &pos)
{
	unsigned cnt = parser_->obj_is_array() ? parser_->get_array_size() : 1;

	//!fixme ���� ����� ��������� �������� �� ������� ������������ ���������� ����, ����� ��� �� �������� � ��� ��������, � �� ������ ��� ������� �����
	if (parser_->get_data_length() != 0x00)
	{
		// simple data

		// check raw bytes amount, if it to less then need
		// set parser error, break and wait other raw bytes
		if (pos + cnt*parser_->get_data_length() > binary_data.end())
		{
			// no enough data in name part of binary data
			parser_->set_error(Parser::ErrorNoEnoughData);
			return binary_data.end();
		}
	}

	std::vector<IDataStorageObjectPtr> vec_data;
	for (unsigned int i = 0; i < cnt; ++i)
	{
		if (parser_->get_data_length() != 0x00) // simple data
		{
			IDataStorageObjectPtr data_ptr(
				new SimpleData(
					parser_->get_data_name(),
					(void *) &(*pos),
					parser_->get_data_length()));
			vec_data.push_back(data_ptr);
			pos += parser_->get_data_length();
		}
		else // object data
		{
			// object data stored in figure brackets, check it

			// try to find open figure bracket
			std::vector<uint8_t>::const_iterator open_fig_bracket = pos;
			if (*open_fig_bracket != DataStorage::cOpenFigureBracketStr)
			{
				// can't find open figure bracket
				parser_->set_error(Parser::ErrorObjectAbsentOpenFigureBracket);
				return pos;
			}

			// try to find close figure bracket
			std::vector<uint8_t>::const_iterator close_fig_bracket;
			for (; pos != binary_data.end(); ++pos)
			{
				if (*pos == DataStorage::cCloseFigureBracketStr)
				{
					close_fig_bracket = pos;
					break;
				}
			}

			// check existing close figure bracket
			if (pos == binary_data.end())
			{
				// absence of close figure bracket means a lack of sufficient data
				parser_->set_error(Parser::ErrorNoEnoughData);
				return pos;
			}

			// object data stored between figure brackets
			Parser internal_parser(std::vector<uint8_t>(++open_fig_bracket, close_fig_bracket));
			pos = close_fig_bracket + 1;
			
			// if object data parsed save it
			if (internal_parser.get_error() == Parser::ErrorOk)
			{
				IDataStorageObjectPtr object_ptr(
					new ObjectData(parser_->get_data_name()));
				std::list<IDataStorageObjectPtr>::const_iterator object_data_iter =
					internal_parser.get_data().begin();
				for (; object_data_iter != internal_parser.get_data().end(); ++object_data_iter)
				{
					object_ptr->to<ObjectData>()->insert(*(*object_data_iter));
				}
				vec_data.push_back(object_ptr);
			}
		}
	}

	// if array is parsing
	if (parser_->obj_is_array())
	{
		IDataStorageObjectPtr array_obj(new ArrayData(parser_->get_data_name(), vec_data));
		parser_->insert(array_obj);
	}
	else
	{
		parser_->insert(vec_data.front());
	}

	parser_->reset();
	
	return pos;
}

} // namespace DataStorage

} // namespace GDS
