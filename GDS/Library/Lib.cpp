#include "stdafx.h"

#include "Lib.h"

namespace GDS
{

Lib::Lib(const std::string &name, const std::string &comment,
	const std::vector<uint8_t>& icon, const LibElementPtr &parent)
	: LibElement(name, comment, icon, parent)
{

}

Lib::~Lib()
{
	internal_libs_.clear();
	internal_operations_.clear();
}

void Lib::addLib(const LibElementPtr &lib)
{
	internal_libs_.push_back(lib);
}

const std::list<LibElementPtr>& Lib::getLibs() const
{
	return internal_libs_;
}

void Lib::addFunction(const LibElementPtr &func)
{
	internal_operations_.push_back(func);
}

const std::list<LibElementPtr>& Lib::getFunctions() const
{
	return internal_operations_;
}

} // namespace GDS
