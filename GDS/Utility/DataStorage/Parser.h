#pragma once

#include "DataStorageCommon.h"
#include "IDataStorageObject.h"

namespace GDS
{

namespace DataStorage
{

class Parser
{
public:
	Parser();
	Parser(const std::string& str);
	~Parser();

	int exec(const std::string& str);

private:
	std::list<IDataStorageObjectPtr> data_;
};

} // namespace DataStorage

} // namespace GDS
