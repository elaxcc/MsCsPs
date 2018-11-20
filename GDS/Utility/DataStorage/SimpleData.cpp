#include "stdafx.h"

#include "SimpleData.h"

namespace GDS
{

namespace DataStorage
{

SimpleData::SimpleData()
	: IDataStorageObject(std::string())
	, data_size_(0)
	, data_(nullptr)
{

}

SimpleData::SimpleData(const SimpleData &obj)
	: IDataStorageObject(obj.get_name())
	, data_size_(obj.get_data_size())
{
	clean_data();
	copy_data(obj.data_, obj.data_size_);
}

SimpleData::SimpleData(const std::string &name, void *data, unsigned int data_size)
	: IDataStorageObject(name)
	, data_size_(data_size)
{
	copy_data(data, data_size_);
}

SimpleData::~SimpleData()
{
	clean_data();
}

uint8_t SimpleData::get_data_size() const
{
	return data_size_;
}

void SimpleData::serialize_head(std::vector<uint8_t> &bytes)
{
	// type
	bytes.push_back(get_data_size());
	bytes.push_back(cDelimiterStr);

	// name
	for (char c : get_name())
	{
		bytes.push_back(c);
	}
	bytes.push_back(cDelimiterStr);
}

void SimpleData::serialize_body(std::vector<uint8_t> &bytes)
{
	// data
	for (unsigned int i = 0; i < data_size_; ++i)
	{
		bytes.push_back(data_[i]);
	}
}

IDataStorageObjectPtr SimpleData::clone() const
{
	return IDataStorageObjectPtr(new SimpleData(get_name(), data_, data_size_));
}

IDataStorageObject::Type SimpleData::get_type()
{
	return IDataStorageObject::TypeSimple;
}

SimpleData& SimpleData::operator= (const SimpleData &r)
{
	set_name(r.get_name());
	clean_data();
	copy_data(r.data_, r.data_size_);
	return *this;
}

void SimpleData::clean_data()
{
	if (data_ != nullptr)
	{
		delete[] data_;
		data_ = nullptr;
	}
}

void SimpleData::copy_data(void *data, unsigned int data_size)
{
	if (data_ == nullptr)
	{
		data_size_ = data_size;
		data_ = new uint8_t[data_size_];
		memcpy(data_, data, data_size_);
	}
}

} // namespace DataStorage

} // namespace GDS
