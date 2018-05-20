#pragma once

#include "IElementView.h"

namespace GDS
{

class IElement
{
public:
	IElement();
	virtual ~IElement();

	virtual void setView(const IElementViewPtr& view) = 0;
};

typedef boost::shared_ptr<IElement> IElementPtr;

} // namespace GDS
