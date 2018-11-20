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
	ObjectData(const ObjectData& obj);
	ObjectData(const std::string& name);
	virtual ~ObjectData();

	template<typename T>
	bool insert(const T& obj);
	void remove(const IDataStorageObject& obj);
	void remove(const std::string& name);
	bool empty();
	void erase();
	template<typename T>
	T* get(const std::string& name);

	// IDataObject
	virtual uint8_t get_data_size() const;
	virtual IDataStorageObject::Type get_type();
	virtual void serialize_head(std::vector<uint8_t>& bytes);
	virtual void serialize_body(std::vector<uint8_t>& bytes);
	virtual IDataStorageObjectPtr clone() const;

	IDataStorageObjectPtr operator[] (std::string field_name);

private:
	std::map<std::string, IDataStorageObjectPtr> fields_;
};

template <typename T>
bool ObjectData::insert(const T& obj)
{
	if (obj.get_name().empty())
	{
		return false;
	}

	IDataStorageObjectPtr copied_obj = obj.clone();

	std::pair<std::map<std::string, IDataStorageObjectPtr>::iterator, bool> result;
	result = fields_.insert(
		std::pair<std::string, IDataStorageObjectPtr>(obj.get_name(), copied_obj));

	return result.second;
}

template<typename T>
T* ObjectData::get(const std::string& name)
{
	std::map<std::string, IDataStorageObjectPtr>::iterator iter = fields_.find(name);
	if (iter != fields_.end())
	{
		IDataStorageObjectPtr iptr = iter->second;
		return (static_cast<T*>(iptr.get()));
	}
	return nullptr;
}

} // namespace DataStorage

} // namespace GDS

