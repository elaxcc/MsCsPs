#pragma once

#include "PinInput.h"
#include "PinOutput.h"

namespace GDS
{

class PinFactory
{
public:
	PinFactory();
	~PinFactory();

	PinPtr CreatePin(const std::string& name, Pin::PinType type, const Point& position) const;
	PinInput* CreatePinInput(const std::string& name, const Point& position) const;
	PinOutput* CreatePinOutput(const std::string& name, const Point& position) const;
};

typedef std::shared_ptr<PinFactory> PinFactoryPtr;

} // namespace GDS
