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

ObjectData::ObjectData(const ObjectData& obj)
	: IDataStorageObject(obj.get_name())
{
	this->erase();
	for (auto d : obj.fields_)
	{
		std::pair<std::string, IDataStorageObjectPtr> pair(d.first, d.second->clone());
		this->fields_.insert(pair);
	}
}

ObjectData::ObjectData(const std::string& name)
	: IDataStorageObject(name)
{

}

ObjectData::~ObjectData()
{
	erase();
}

void ObjectData::remove(const IDataStorageObject& obj)
{
	remove(obj.get_name());
}

void ObjectData::remove(const std::string& name)
{
	std::map<std::string, IDataStorageObjectPtr>::iterator elem = fields_.find(name);
	if (elem != fields_.end())
	{
		fields_.erase(elem);
	}
}

bool ObjectData::empty()
{
	return fields_.empty();
}

void ObjectData::erase()
{
	fields_.clear();
}

unsigned ObjectData::get_data_size() const
{
	return 0;
}

IDataStorageObject::Type ObjectData::get_type()
{
	return IDataStorageObject::TypeObject;
}

void ObjectData::serialize_head(std::vector<uint8_t>& bytes)
{
	// object has type lenfth == 0
	bytes.push_back(0x00);
	bytes.push_back(cDelimiterStr);

	// name
	for (char c : get_name())
	{
		bytes.push_back(c);
	}
	bytes.push_back(cDelimiterStr);
}

void ObjectData::serialize_body(std::vector<uint8_t>& bytes)
{
	// first bracket
	bytes.push_back(cFirstObjBracketStr);

	for (auto field : fields_)
	{
		std::vector<unsigned char> serial_data = field.second->serialize();
		bytes.insert(bytes.end(), serial_data.begin(), serial_data.end());
	}

	// last bracket
	bytes.push_back(cLastObjBracketStr);
}

IDataStorageObjectPtr ObjectData::clone() const
{
	ObjectData *obj = new ObjectData(get_name());
	for (auto field : fields_)
	{
		obj->insert<IDataStorageObject>(*(field.second));
	}

	return IDataStorageObjectPtr(obj);
}

IDataStorageObjectPtr ObjectData::operator[] (std::string field_name)
{
	auto result = fields_.find(field_name);
	if (result != fields_.end())
	{
		return result->second;
	}
	return IDataStorageObjectPtr();
}

} // namespace DataStorage

} // namespace GDS

