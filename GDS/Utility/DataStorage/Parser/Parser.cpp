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
	: current_state_(new StateGetType(this))
	, current_data_type_(0)
	, current_data_is_array_(false)
	, current_data_array_size_(0)
{

}

Parser::Parser(const std::vector<uint8_t>& data)
	: current_state_(new StateGetType(this))
	, current_data_type_(0)
	, current_data_is_array_(false)
	, current_data_array_size_(0)
{
	exec(data);
}

Parser::~Parser()
{
	clean();
}

int Parser::exec(const std::vector<uint8_t>& binary_data)
{
	std::vector<uint8_t>::const_iterator iter = binary_data.begin();

	while (iter != binary_data.end())
	{
		current_state_->process(binary_data, iter);
	}

	return 0;
}

void Parser::reset()
{
	current_state_.reset(new StateGetType(this));
	current_data_type_ = 0;
	current_data_name_.clear();
	current_data_is_array_ = false;
	current_data_array_size_ = 0;
	error_ = ErrorOk;
}

void Parser::clean()
{
	reset();
	data_.clear();
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

void Parser::set_data_type(uint8_t obj_type)
{
	current_data_type_ = obj_type;
}

void Parser::set_data_name(const std::string &data_name)
{
	current_data_name_ = data_name;
}

std::string Parser::get_data_name() const
{
	return current_data_name_;
}

uint8_t Parser::get_data_type() const
{
	return current_data_type_;
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
