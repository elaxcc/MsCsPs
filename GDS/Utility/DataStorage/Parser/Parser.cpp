#include "stdafx.h"

#include "Parser.h"

#include "../SimpleData.h"
#include "../ArrayData.h"
#include "../ObjectData.h"

namespace GDS
{

namespace DataStorage
{

Parser::Parser()
{
	reset();
}

Parser::Parser(const std::vector<uint8_t>& data)
{
	reset();
	exec(data);
}

Parser::~Parser()
{
	clean();
}

int Parser::exec(const std::vector<uint8_t>& binary_data)
{
	if (!raw_data_.empty() && error_ == ErrorNoEnoughData)
	{
		error_ = ErrorOk;
	}

	// check stored raw data
	raw_data_.insert(raw_data_.end(), binary_data.begin(), binary_data.end());

	std::vector<uint8_t>::const_iterator iter = raw_data_.begin();
	while (iter != raw_data_.end())
	{
		iter = current_state_->process(raw_data_, iter);
		raw_data_.erase(raw_data_.begin(), iter);
		iter = raw_data_.begin();

		// if no enough raw data, store that left
		if (error_ == ErrorNoEnoughData)
		{
			break;
		}
	}

	return 0;
}

void Parser::reset()
{
	current_state_.reset(new StateGetDataLength(this));
	data_length_ = 0;
	current_data_name_.clear();
	current_data_is_array_ = false;
	current_data_array_size_ = 0;
	error_ = ErrorOk;
}

void Parser::clean()
{
	reset();
	data_.clear();
	raw_data_.clear();
}

void Parser::insert(IDataStorageObjectPtr data)
{
	data_.push_back(data);
}

const std::list<IDataStorageObjectPtr>& Parser::get_data() const
{
	return data_;
}

void Parser::set_state(const IStatePtr &state)
{
	current_state_ = state;
}

IStatePtr Parser::get_state()
{
	return current_state_;
}

void Parser::set_error(Parser::Error error)
{
	error_ = error;
}

Parser::Error Parser::get_error() const
{
	return error_;
}

void Parser::set_data_length(uint8_t data_length)
{
	data_length_ = data_length;
}
uint8_t Parser::get_data_length() const
{
	return data_length_;
}

void Parser::set_data_name(const std::string &data_name)
{
	current_data_name_ = data_name;
}

std::string Parser::get_data_name() const
{
	return current_data_name_;
}

void Parser::set_obj_array_type(unsigned int array_size)
{
	current_data_is_array_ = true;
	current_data_array_size_ = array_size;
}

bool Parser::obj_is_array()
{
	return current_data_is_array_;
}

unsigned int Parser::get_array_size()
{
	return current_data_array_size_;
}

} // namespace DataStorage

} // namespace GDS
