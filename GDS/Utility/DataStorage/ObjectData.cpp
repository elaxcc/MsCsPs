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
	erase();
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

void ObjectData::erase()
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

unsigned ObjectData::get_data_size() const
{
	return 0;
}

IDataStorageObject::Type ObjectData::get_type()
{
	return IDataStorageObject::TypeObject;
}

void ObjectData::serialize_head(std::vector<unsigned char>& bytes)
{
	// object has type lenfth == 0
	bytes.push_back(0x00);
	bytes.push_back(cDelimiterStr);

	// name
	for (char c : get_name())
	{
		bytes.push_back(c);
	}
}

void ObjectData::serialize_data(std::vector<unsigned char>& bytes)
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

IDataStorageObject* ObjectData::operator[] (std::string field_name)
{
	auto result = fields_.find(field_name);
	if (result != fields_.end())
	{
		return result->second;
	}
	return nullptr;
}

} // namespace DataStorage

} // namespace GDS

