#include "stdafx.h"

#include "PinOutput.h"

namespace GDS
{

PinOutput::PinOutput(const std::string& name)
	: Pin(name, Pin::PinType_Output)
{

}

PinOutput::~PinOutput()
{

}

} // namespace GDS
