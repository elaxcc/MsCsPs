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
	: current_state_(State_Empty)
{

}

Parser::Parser(const std::vector<uint8_t>& data)
	: current_state_(State_Empty)
{
	exec(data);
}

Parser::~Parser()
{
	data_.clear();
}

int Parser::exec(const std::vector<uint8_t>& data)
{
	// divide input to tokens
	std::vector<uint8_t>::const_iterator iter = data.begin();

	return 0;
}

void Parser::clean()
{
	current_state_ = State_Empty;
	data_.clear();
}

const std::list<IDataStorageObjectPtr>& Parser::get_data() const
{
	return data_;
}

} // namespace DataStorage

} // namespace GDS
