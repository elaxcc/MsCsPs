#pragma once

#include "Utility/Geometry.h"

namespace GDS
{

class IElementView
{
public:
	IElementView();
	virtual ~IElementView();

	virtual Point getPosition() = 0;
};

typedef std::shared_ptr<IElementView> IElementViewPtr;

} // namespace GDS
