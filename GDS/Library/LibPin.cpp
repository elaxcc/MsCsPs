#include "stdafx.h"

#include "LibPin.h"

namespace GDS
{

LibPin::LibPin(const std::string &name, const std::string &comment,
	const std::vector<uint8_t>& icon, const LibElementPtr &parent)
	: LibElement(name, comment, icon, parent)
{

}

LibPin::~LibPin()
{

}

} // namespace GDS
