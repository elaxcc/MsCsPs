#pragma once

#include "IElement.h"

namespace GDS
{

class ElementFactory
{
public:
	ElementFactory();
	~ElementFactory();

	IElementPtr createElement();

private:

};

typedef std::shared_ptr<ElementFactory> ElementFactoryPtr;

} // namespace GDS
