#pragma once

#include <QGraphicsView>
#include <QGraphicsScene>

#include "Editor/EditorView.h"

namespace GDS
{

class QtEditor 
	: public QGraphicsView
	, public EditorView
{
public:
	QtEditor(QWidget* wgt = 0);
	~QtEditor();

private:
	QGraphicsScene scene_;
};

} // namespace GDS
