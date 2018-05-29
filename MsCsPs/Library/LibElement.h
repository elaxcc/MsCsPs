#pragma once

#include "ILibElement.h"

namespace GDS
{

class LibElement : public ILibElement
{
public:
	LibElement();
	~LibElement();

	// IlibElement
	virtual const std::string& getName() const;
	virtual const std::string& getComment() const;
	virtual std::vector<unsigned char> getIcon() const;

private:
	std::string name_;
	std::string comment_;
	std::vector<unsigned char> icon_;
};

} // namespace GDS
