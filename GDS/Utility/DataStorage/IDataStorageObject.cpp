#include "stdafx.h"

#include "IDataStorageObject.h"

namespace GDS
{

namespace DataStorage
{

IDataStorageObject::IDataStorageObject(const std::string& name)
	: name_(name)
{

}

IDataStorageObject::~IDataStorageObject()
{

}

void IDataStorageObject::set_name(const std::string& name)
{
	name_ = name;
}

const std::string& IDataStorageObject::get_name() const
{
	return name_;
}

std::vector<unsigned char> IDataStorageObject::serialize()
{
	std::vector<unsigned char> bytes;

	serialize_head(bytes);
	serialize_data(bytes);

	return bytes;
}

} // namespace DataStorage

} // namespace GDS