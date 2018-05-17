#pragma once

#include "Pin.h"

namespace GDS
{

class PinOutput : public Pin
{
public:
	PinOutput(const std::string& name, const Point& position);
	~PinOutput();
};

} // namespace GDS
