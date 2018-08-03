#include "stdafx.h"

#include "QtEditor.h"

namespace GDS
{

QtEditor::QtEditor(QWidget* wgt)
	: QGraphicsView(wgt)
{
	// set scene
	this->setScene(&scene_);
}

QtEditor::~QtEditor()
{

}

} 
