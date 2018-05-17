#include "stdafx.h"

#include "PinFactory.h"

namespace GDS
{

PinFactory::PinFactory()
{

}

PinFactory::~PinFactory()
{

}

Pin* PinFactory::CreatePin(const std::string& name, Pin::PinType type, const Point& position) const
{
	return new Pin(name, type, position);
}

PinInput* PinFactory::CreatePinInput(const std::string& name, const Point& position) const
{
	return new PinInput(name, position);
}

PinOutput* PinFactory::CreatePinOutput(const std::string& name, const Point& position) const
{
	return new PinOutput(name, position);
}

} // namespace GDS
