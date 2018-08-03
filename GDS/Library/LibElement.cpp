#include "stdafx.h"

#include "LibElement.h"

namespace GDS
{

LibElement::LibElement()
{

}

LibElement::~LibElement()
{
	icon_.clear();
}

const std::string& LibElement::getName() const
{
	return name_;
}

const std::string& LibElement::getComment() const
{
	return comment_;
}

const std::vector<unsigned char>& LibElement::getIcon() const
{
	return icon_;
}

} // namespace GDS
