#pragma once

#include "IDataStorageObject.h"

namespace GDS
{

namespace DataStorage
{

class ObjectData : public IDataStorageObject
{
public:
	ObjectData();
	ObjectData(const std::string& name);
	~ObjectData();

	bool insert(const IDataStorageObjectPtr& obj);
	void remove(const IDataStorageObjectPtr& obj);
	void remove(const std::string& name);
	template<typename T>
	T* get(const std::string& name);

	// IDataObject
	std::vector<unsigned char> serialize();

private:
	std::map<std::string, IDataStorageObjectPtr> fields_;
};

} // namespace DataStorage

} // namespace GDS

