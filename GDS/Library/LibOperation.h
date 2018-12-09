#pragma once

#include "LibElement.h"
#include "LibPin.h"

namespace GDS
{

class LibOperation : public LibElement
{
public:
	LibOperation(const std::string &name, const std::string &comment,
		const std::vector<uint8_t>& icon, const LibElementPtr &parent);
	~LibOperation();

	void addPin(const LibPinPtr &pin);
	const std::list<LibPinPtr>& getPins() const;

private:
	std::list<LibPinPtr> pins_;
};
typedef std::shared_ptr<LibOperation> LibOperationPtr;

} // namespace GDS
