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

StateBegin::StateBegin(Parser *parser)
	: IState(parser)
{

}

StateBegin::~StateBegin()
{

}

std::vector<uint8_t>::const_iterator StateBegin::process(const std::vector<uint8_t> &data)
{
	return std::vector<uint8_t>::const_iterator();
}

StateGetType::StateGetType(Parser *parser)
	: IState(parser)
{

}

StateGetType::~StateGetType()
{

}

std::vector<uint8_t>::const_iterator StateGetType::process(const std::vector<uint8_t> &data)
{
	return std::vector<uint8_t>::const_iterator();
}

StateGetName::StateGetName(Parser *parser)
	: IState(parser)
{

}

StateGetName::~StateGetName()
{

}

std::vector<uint8_t>::const_iterator StateGetName::process(const std::vector<uint8_t> &data)
{
	return std::vector<uint8_t>::const_iterator();
}

StateGetData::StateGetData(Parser *parser)
	: IState(parser)
{

}

StateGetData::~StateGetData()
{

}

std::vector<uint8_t>::const_iterator StateGetData::process(const std::vector<uint8_t> &data)
{
	return std::vector<uint8_t>::const_iterator();
}

StateCompleted::StateCompleted(Parser *parser)
	: IState(parser)
{

}

StateCompleted::~StateCompleted()
{

}

std::vector<uint8_t>::const_iterator StateCompleted::process(const std::vector<uint8_t> &data)
{
	return std::vector<uint8_t>::const_iterator();
}

} // namespace DataStorage

} // namespace GDS
