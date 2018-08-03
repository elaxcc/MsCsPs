#include "stdafx.h"

#include "PinOutput.h"

namespace GDS
{

PinOutput::PinOutput(const std::string& name, const Point& position)
	: Pin(name, Pin::PinType_Output, position)
{

}

PinOutput::~PinOutput()
{

}

} // namespace GDS
