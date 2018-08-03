#include "stdafx.h"

#include "QtLibWnd.h"

namespace GDS
{

QtLibWnd::QtLibWnd(QWidget* wgt /* = 0 */)
	: QGraphicsView(wgt)
{
	scene_ = new QGraphicsScene();
	this->setScene(scene_);
}

QtLibWnd::~QtLibWnd()
{
	delete scene_;
}

} // namespace GDS
