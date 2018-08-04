#pragma once

namespace GDS
{

namespace DataStorage
{

class IDataStorageObject
{
public:
	virtual std::vector<unsigned char> serialize() = 0;
};

} // namespace DataStorage

} // namespace GDS

