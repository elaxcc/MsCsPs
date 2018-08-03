#pragma once

namespace GDS
{

class ILibElement
{
public:
	virtual const std::string& getName() const = 0;
	virtual const std::string& getComment() const = 0;
	virtual const std::vector<unsigned char>& getIcon() const = 0;
};

typedef std::shared_ptr<ILibElement> ILibElementPtr;

} // namespace GDS
