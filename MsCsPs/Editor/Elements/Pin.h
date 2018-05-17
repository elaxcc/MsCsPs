#pragma once

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
	Pin(const std::string& name, PinType type);
	~Pin();

	void setName(std::string name);
	std::string getName() const;

	void setType(PinType type);
	PinType getType() const;

private:
	std::string name_;
	PinType type_;
};
typedef boost::shared_ptr<Pin> PinPtr;

} // namespace GDS
