#include "stdafx.h"

#include "State.h"

#include "Parser.h"

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

StateBegining::StateBegining(Parser *parser)
	: IState(parser)
{

}

StateBegining::~StateBegining()
{

}

std::vector<uint8_t>::const_iterator StateBegining::process(
	const std::vector<uint8_t> &binary_data,
	std::vector<uint8_t>::const_iterator &pos)
{
	// reset parser and go to StateGetType
	parser_->reset();
	parser_->set_state(IStatePtr(new StateGetType(parser_)));

	return pos;
}

StateGetType::StateGetType(Parser *parser)
	: IState(parser)
{

}

StateGetType::~StateGetType()
{

}

std::vector<uint8_t>::const_iterator StateGetType::process(
	const std::vector<uint8_t> &binary_data,
	std::vector<uint8_t>::const_iterator &pos)
{
	// try to find open square bracket
	std::vector<uint8_t>::const_iterator iter = pos;
	for (; iter != binary_data.end(); ++iter)
	{
		if (*iter == DataStorage::cDelimiterStr)
		{
			break;
		}
	}

	if (iter == binary_data.end()) // can't find open square bracket
	{
		parser_->set_error(Parser::ErrorNoEnoughData);
		return iter;
	}

	parser_->set_data_type(std::string(pos, iter));

	// go to GetName state
	parser_->set_state(IStatePtr(new StateGetName(parser_)));

	return ++iter;
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
		parser_->set_error(Parser::ErrorArrayAbsentClosingSquaredBracket);
	}
	if (!find_open_bracket && find_closing_bracket)
	{
		parser_->set_error(Parser::ErrorArrayAbsentOpeningSquaredBracket);
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
	for (unsigned int i = 0; i < cnt; ++i)
	{
		if (parser_->get_data_type() != DataStorage::cObjectTypeStr) // simple data
		{
			for (unsigned int cur_byte = 0; cur_byte < parser_->get_data_type(); ++cur_byte)
			{
				
			}
		}
		else // object data
		{

		}
	}

	return pos;
}

StateComplete::StateComplete(Parser *parser)
	: IState(parser)
{

}

StateComplete::~StateComplete()
{

}

std::vector<uint8_t>::const_iterator StateComplete::process(
	const std::vector<uint8_t> &binary_data,
	std::vector<uint8_t>::const_iterator &pos)
{
	return pos;
}

} // namespace DataStorage

} // namespace GDS
