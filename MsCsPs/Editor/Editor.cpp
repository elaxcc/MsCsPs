#include "stdafx.h"

#include "Editor.h"

namespace GDS
{

Editor::Editor()
{
	// create PinFactory
	pin_factory_.reset(new PinFactory());

	// create ElementFactory
	element_factory_.reset(new ElementFactory());
}

Editor::~Editor()
{

}

void Editor::setEditorView(EditorView *editor)
{

}

ElementFactoryPtr Editor::getElementFactory()
{
	return element_factory_;
}

PinFactoryPtr Editor::getPinFactory()
{
	return pin_factory_;
}

} // namespace GDS
