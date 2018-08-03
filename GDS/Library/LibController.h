#pragma once

#include "Lib.h"
#include "LibView.h"

namespace GDS
{

class LibController
{
public:
	LibController();
	~LibController();

	void setView(LibView* view);

private:
	std::list<ILibElementPtr> libs_;
	LibView* view_;
};

} // class GDS
