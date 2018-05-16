#include "stdafx.h"

#include "Pin.h"

namespace GDS
{

Pin::Pin(const std::string& name, PinType type)
	: name_(name)
	, type_(type)
{

}

Pin::~Pin()
{

}

void Pin::setName(std::string name)
{
	name_ = name;
}

std::string Pin::getName() const
{
	return name_;
}

void Pin::setType(Pin::PinType type)
{
	type_ = type;
}

Pin::PinType Pin::getType() const
{
	return type_;
}

} // namespace GDS
