#include "stdafx.h"

#include "LibController.h"

namespace GDS
{

LibController::LibController()
{

}

LibController::~LibController()
{

}

void LibController::setView(LibView* view)
{
	view_ = view;
}

} // namespace GDS
