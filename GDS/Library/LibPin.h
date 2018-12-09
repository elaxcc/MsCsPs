#pragma once

#include "LibElement.h"

namespace GDS
{

class LibPin : public LibElement
{
public:
	LibPin(const std::string &name, const std::string &comment,
		const std::vector<uint8_t>& icon, const LibElementPtr &parent);
	~LibPin();
};
typedef std::shared_ptr<LibPin> LibPinPtr;

} // namespace GDS
