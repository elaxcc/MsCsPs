#include "stdafx.h"

namespace GDS
{

Lib::Lib()
{

}

Lib::~Lib()
{
	elements_.erase();
}

const std::vector<ILibElementPtr>& Lib::getElements() const
{
	return elements_;
}

const ILibElementPtr Lib::getParent() const
{
	return parent_;
}

} // namespace GDS
