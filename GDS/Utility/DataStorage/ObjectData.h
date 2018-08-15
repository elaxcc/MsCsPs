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
	virtual ~ObjectData();

	bool insert(const IDataStorageObjectPtr& obj);
	void remove(const IDataStorageObject& obj);
	void remove(const std::string& name);
	bool empty();
	template<typename T>
	T* get(const std::string& name);

	// IDataObject
	virtual unsigned get_data_size() const;
	virtual std::vector<unsigned char> serialize();

private:
	std::map<std::string, IDataStorageObjectPtr> fields_;
};

template<typename T>
T* ObjectData::get(const std::string& name)
{
	std::map<std::string, IDataStorageObjectPtr>::iterator iter = fields_.find(name);
	if (iter != fields_.end())
	{
		return (dynamic_cast<T*>(iter->second.get()));
	}
	return nullptr;
}

} // namespace DataStorage

} // namespace GDS

