#pragma once

#include "IDataStorageObject.h"

namespace GDS
{

namespace DataStorage
{

class File
{
public:
	File();
	File(std::string file_name);
	~File();

	bool exec();
	bool exec(std::string file_name);

private:
	std::list<IDataStorageObjectPtr> records_;
	std::string file_name_;
};

} // namespace DataStorage

} // namespace GDS

