#include "stdafx.h"

#include "PinInput.h"

namespace GDS
{

PinInput::PinInput(const std::string& name)
	: Pin(name, Pin::PinType_Input)
{

}

PinInput::~PinInput()
{

}

} // namespace GDS
