#include "stdafx.h"

#include "PinInput.h"

namespace GDS
{

PinInput::PinInput(const std::string& name, const Point& position)
	: Pin(name, Pin::PinType_Input, position)
{

}

PinInput::~PinInput()
{

}

} // namespace GDS
