#include "stdafx.h"

#include "Pin.h"

namespace GDS
{

Pin::Pin(const std::string& name, PinType type, const Point& position)
	: name_(name)
	, type_(type)
	, position_(position)
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

void Pin::setPosition(Point position)
{
	position_ = position;
}

Point Pin::getPosition() const
{
	return position_;
}

} // namespace GDS
