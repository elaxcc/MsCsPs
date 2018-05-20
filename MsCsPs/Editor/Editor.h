#pragma once

#include "EditorView.h"
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

	ElementFactoryPtr getElementFactory();
	PinFactoryPtr getPinFactory();

private:
	std::list<EditorView> view_list_;

	ElementFactoryPtr element_factory_;
	PinFactoryPtr pin_factory_;
};

} // namespace GDS
