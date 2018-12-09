#include "stdafx.h"

#include "LibOperation.h"
namespace GDS
{

LibOperation::LibOperation(const std::string &name, const std::string &comment,
	const std::vector<uint8_t>& icon, const LibElementPtr &parent)
	: LibElement(name, comment, icon, parent)
{

}

LibOperation::~LibOperation()
{
	pins_.clear();
}

void LibOperation::addPin(const LibPinPtr &pin)
{
	pins_.push_back(pin);
}

const std::list<LibPinPtr>& LibOperation::getPins() const
{
	return pins_;
}

} // namespace GDS
