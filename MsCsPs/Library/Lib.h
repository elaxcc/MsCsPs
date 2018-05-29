#pragma once

#include "LibElement.h"

namespace GDS
{

class Lib : public LibElement
{
public:
	Lib();
	~Lib();

	const std::vector<ILibElementPtr>& getElements() const;
	const ILibElementPtr getParent() const;

private:
	std::list<ILibElementPtr> elements_;
	ILibElementPtr parent_;
};

} // namespace GDS
