#include "stdafx.h"

#include "ElementFactory.h"

namespace GDS
{

ElementFactory::ElementFactory()
{

}

ElementFactory::~ElementFactory()
{

}

IElementPtr ElementFactory::createElement()
{
	return IElementPtr(nullptr);
}

} // namespace GDS
