#pragma once

#include "Pin.h"

namespace GDS
{

class PinOutput : public Pin
{
public:
	PinOutput(const std::string& name);
	~PinOutput();
};

} // namespace GDS
