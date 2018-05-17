#pragma once

#include "Utility/Geometry.h"

namespace GDS
{

class Pin
{
public:
	enum PinType
	{
		PinType_Input,
		PinType_Output
	};

public:
	Pin(const std::string& name, PinType type, const Point& position);
	~Pin();

	void setName(std::string name);
	std::string getName() const;

	void setType(PinType type);
	PinType getType() const;

	void setPosition(Point position);
	Point getPosition() const;

private:
	std::string name_;
	PinType type_;
	Point position_;
};
typedef boost::shared_ptr<Pin> PinPtr;

} // namespace GDS
