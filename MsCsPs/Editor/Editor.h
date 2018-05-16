#pragma once

#include "EditorView.h"

namespace GDS
{

class Editor
{
public:
	Editor();
	~Editor();

	void setEditorView(EditorView *editor);

private:
	std::list<EditorView> view_list_;
};

} // namespace GDS
