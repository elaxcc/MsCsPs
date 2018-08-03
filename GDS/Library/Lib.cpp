#include "stdafx.h"

#include "Lib.h"

namespace GDS
{

Lib::Lib()
{

}

Lib::~Lib()
{
	elements_.clear();
}

const std::list<ILibElementPtr>& Lib::getElements() const
{
	return elements_;
}

const ILibElementPtr Lib::getParent() const
{
	return parent_;
}

} // namespace GDS
