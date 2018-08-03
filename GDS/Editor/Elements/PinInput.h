#pragma once

#include "Pin.h"

namespace GDS
{

class PinInput : public Pin
{
public:
	PinInput(const std::string& name, const Point& position);
	~PinInput();
};

} // namespace GDS
