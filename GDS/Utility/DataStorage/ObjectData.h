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

	bool insert(IDataStorageObject* obj);
	void remove(const IDataStorageObject& obj);
	void remove(const std::string& name);
	bool empty();
	void clean();
	template<typename T>
	T* get(const std::string& name);

	// IDataObject
	virtual unsigned get_data_size() const;
	virtual IDataStorageObject::Type get_type();
	virtual void serialize_head(std::vector<unsigned char>& bytes);
	virtual void serialize_data(std::vector<unsigned char>& bytes);

	IDataStorageObject* operator[] (std::string field_name);

private:
	std::map<std::string, IDataStorageObject*> fields_;
};

template<typename T>
T* ObjectData::get(const std::string& name)
{
	std::map<std::string, IDataStorageObject*>::iterator iter = fields_.find(name);
	if (iter != fields_.end())
	{
		return (dynamic_cast<T*>(iter->second));
	}
	return nullptr;
}

} // namespace DataStorage

} // namespace GDS

