#pragma once

#include <QGraphicsPixmapItem>

#include "Library/LibElement.h"

namespace GDS
{

class QtLibElement : public QGraphicsPixmapItem
{
public:
	QtLibElement(LibElementPtr lib_element, QWidget *wgt = nullptr);
	~QtLibElement();

private:
	LibElementPtr lib_element_;
};

} // namespace GDS
