#pragma once

#include <QGraphicsPixmapItem>

#include "Library/ILibElement.h"

namespace GDS
{

class QtLibElement : public QGraphicsPixmapItem
{
public:
	QtLibElement(ILibElementPtr lib_element);
	~QtLibElement();

private:
	ILibElementPtr lib_element_;
};

} // namespace GDS
