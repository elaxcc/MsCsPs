#include "stdafx.h"

#include "Parser.h"

namespace GDS
{

namespace DataStorage
{

Parser::Parser()
{

}

Parser::Parser(const std::string& str)
{
	exec(str);
}

Parser::~Parser()
{
	data_.clear();
}

int Parser::exec(const std::string& str)
{
	return 0;
}

} // namespace DataStorage

} // namespace GDS
