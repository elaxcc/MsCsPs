#include "stdafx.h"

#include "ObjectData.h"

namespace GDS
{

namespace DataStorage
{

ObjectData::ObjectData()
{

}

ObjectData::ObjectData(const std::string& name)
	: name_(name)
{

}

ObjectData::~ObjectData()
{

}

void ObjectData::set_name(const std::string& name)
{
	name_ = name;
}

const std::string& ObjectData::get_name() const
{
	return name_;
}

// IDataObject
std::vector<unsigned char> ObjectData::serialize()
{
	//!fixme
	return std::vector<unsigned char>();
}

} // namespace DataStorage

} // namespace GDS

