#include "stdafx.h"

#include "LibElement.h"

namespace GDS
{

LibElement::LibElement(const std::string &name, 
	const std::string &comment, const std::vector<uint8_t>& icon,
	const LibElementPtr &parent/* = LibElementPtr(nullptr)*/)
	: name_(name)
	, comment_(comment_)
	, icon_(icon)
	, parent_(parent)
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

const std::vector<uint8_t>& LibElement::getIcon() const
{
	return icon_;
}

const LibElementPtr& LibElement::getParent() const
{
	return parent_;
}

} // namespace GDS
