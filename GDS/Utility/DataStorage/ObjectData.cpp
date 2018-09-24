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
	std::map<std::string, IDataStorageObject*>::iterator iter = fields_.begin();
	for (; iter != fields_.end(); ++iter)
	{
		if (iter->second != nullptr)
		{
			delete iter->second;
		}
	}
	fields_.clear();
}

bool ObjectData::insert(IDataStorageObject* obj)
{
	if (obj == nullptr)
	{
		return false;
	}
	if (obj->get_name().empty())
	{
		return false;
	}

	std::pair<std::map<std::string, IDataStorageObject*>::iterator, bool> result;
	result = fields_.insert(std::make_pair(obj->get_name(), obj));

	return result.second;
}

void ObjectData::remove(const IDataStorageObject& obj)
{
	remove(obj.get_name());
}

void ObjectData::remove(const std::string& name)
{
	std::map<std::string, IDataStorageObject*>::iterator elem = fields_.find(name);
	if (elem != fields_.end())
	{
		if (elem->second != nullptr)
		{
			delete elem->second;
		}
		fields_.erase(elem);
	}
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

IDataStorageObject::Type ObjectData::get_type()
{
	return IDataStorageObject::TypeObject;
}

} // namespace DataStorage

} // namespace GDS

