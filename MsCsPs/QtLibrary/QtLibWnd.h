#pragma once

#include <QGraphicsView>
#include <QGraphicsScene>

#include "Library/LibView.h"

namespace GDS
{

class QtLibWnd
	: public QGraphicsView
	, public LibView
{
public:
	QtLibWnd(QWidget* wgt = 0);
	~QtLibWnd();

	// LibView

private:
	QGraphicsScene* scene_;
};

} // namespace GDS
