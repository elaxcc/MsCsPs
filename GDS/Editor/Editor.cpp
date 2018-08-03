#include "stdafx.h"

#include "Editor.h"

namespace GDS
{

Editor::Editor()
{
	// create command history
	command_history_.reset(new CommandHistory());

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

CommandHistoryPtr Editor::getCommandHistory() const
{
	return command_history_;
}

ElementFactoryPtr Editor::getElementFactory() const
{
	return element_factory_;
}

PinFactoryPtr Editor::getPinFactory() const
{
	return pin_factory_;
}

} // namespace GDS
