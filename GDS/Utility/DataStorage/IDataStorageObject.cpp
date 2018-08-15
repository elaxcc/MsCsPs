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

} // namespace DataStorage

} // namespace GDS