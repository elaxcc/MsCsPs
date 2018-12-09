#pragma once

#include <QGraphicsPixmapItem>

#include "Library/LibElement.h"

namespace GDS
{

class QtLibElement : public QGraphicsPixmapItem
{
public:
	QtLibElement(LibElementPtr lib_element);
	~QtLibElement();

private:
	LibElementPtr lib_element_;
};

} // namespace GDS
