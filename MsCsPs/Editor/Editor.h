#pragma once

#include "EditorView.h"
#include "Commands/CommandHistory.h"
#include "Elements/ElementFactory.h"
#include "Elements/PinFactory.h"

namespace GDS
{

class Editor
{
public:
	Editor();
	~Editor();

	void setEditorView(EditorView *editor);

	CommandHistoryPtr getCommandHistory() const;

	ElementFactoryPtr getElementFactory() const;
	PinFactoryPtr getPinFactory() const;

private:
	std::list<EditorView> view_list_;

	CommandHistoryPtr command_history_;

	ElementFactoryPtr element_factory_;
	PinFactoryPtr pin_factory_;
};

} // namespace GDS
