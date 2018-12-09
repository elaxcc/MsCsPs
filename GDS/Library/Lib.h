#pragma once

#include "LibElement.h"

namespace GDS
{

class Lib : public LibElement
{
public:
	Lib(const std::string &name, const std::string &comment,
		const std::vector<uint8_t>& icon, const LibElementPtr &parent);
	~Lib();

	void addLib(const LibElementPtr &lib);
	const std::list<LibElementPtr>& getLibs() const;

	void addFunction(const LibElementPtr &func);
	const std::list<LibElementPtr>& getFunctions() const;

private:
	std::list<LibElementPtr> internal_libs_;
	std::list<LibElementPtr> internal_operations_;
};
typedef std::shared_ptr<Lib> LibPtr;

} // namespace GDS
