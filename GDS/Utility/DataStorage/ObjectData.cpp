#include "stdafx.h"

#include "ObjectData.h"

namespace GDS
{

namespace DataStorage
{

ObjectData::ObjectData()
	: IDataStorageObject(std::string())
{

}

ObjectData::ObjectData(const std::string& name)
	: IDataStorageObject(name)
{

}

ObjectData::~ObjectData()
{
	fields_.clear();
}

bool ObjectData::insert(const IDataStorageObjectPtr& obj)
{
	std::pair<std::map<std::string, IDataStorageObjectPtr>::iterator, bool> result;
	result = fields_.insert(std::pair<std::string, IDataStorageObjectPtr>(obj->get_name(), obj));

	return result.second;
}

void ObjectData::remove(const IDataStorageObject& obj)
{
	remove(obj.get_name());
}

void ObjectData::remove(const std::string& name)
{
	fields_.erase(name);
}

bool ObjectData::empty()
{
	return fields_.empty();
}

unsigned ObjectData::get_data_size() const
{
	return 0;
}

std::vector<unsigned char> ObjectData::serialize()
{
	//!fixme
	return std::vector<unsigned char>();
}

} // namespace DataStorage

} // namespace GDS

