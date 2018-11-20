#include "stdafx.h"

#include "ArrayData.h"

namespace GDS
{

namespace DataStorage
{

ArrayData::ArrayData(const std::string &name, unsigned size)
	: IDataStorageObject(name)
	, data_(size)
{
	for (auto d : data_)
	{
		d = nullptr;
	}
}

ArrayData::ArrayData(const std::string& name, IDataStorageObjectPtr* data, unsigned size)
	: IDataStorageObject(name)
	, data_(size)
{
	for (unsigned i = 0; i < size; ++i)
	{
		data_[i] = data[i];
	}
}

ArrayData::ArrayData(const std::string& name, const std::vector<IDataStorageObjectPtr>& data)
	: IDataStorageObject(name)
	, data_(data.size())
{
	for (unsigned i = 0; i < data_.size(); ++i)
	{
		data_[i] = data[i];
	}
}

ArrayData::~ArrayData()
{
	data_.clear();
}

void ArrayData::set_data(const std::vector<IDataStorageObjectPtr>& data)
{
	for (unsigned i = 0; i < data_.size(); ++i)
	{
		data_[i] = data[i];
	}
}

std::vector<IDataStorageObjectPtr>& ArrayData::get_data()
{
	return data_;
}

unsigned ArrayData::get_size()
{
	return data_.size();
}

IDataStorageObjectPtr& ArrayData::operator[] (int index)
{
	return data_[index];
}

uint8_t  ArrayData::get_data_size() const
{
	if (data_.empty())
	{
		return 0;
	}
	return data_[0]->get_data_size();
}

void ArrayData::serialize_head(std::vector<uint8_t>& bytes)
{
	if (data_.empty())
	{
		return;
	}
	for (auto d : data_)
	{
		if (d == nullptr)
		{
			return;
		}
	}

	// type
	bytes.push_back(data_.empty() ? 0 : data_[0]->get_data_size());
	bytes.push_back(cDelimiterStr);

	// name
	for (char c : get_name())
	{
		bytes.push_back(c);
	}

	// array size
	bytes.push_back(cOpenSquareBracketStr);
	unsigned int data_cnt = data_.size();
	for (unsigned int i = 0; i < sizeof(unsigned int); ++i)
	{
		unsigned char tmp = *((unsigned char*)(&data_cnt) + i);
		bytes.push_back(tmp);
	}
	bytes.push_back(cCloseSquareBracketStr);
	bytes.push_back(cDelimiterStr);
}

void ArrayData::serialize_body(std::vector<uint8_t>& bytes)
{
	// data
	for (unsigned int i = 0; i < data_.size(); ++i)
	{
		data_[i]->serialize_body(bytes);
	}
}

IDataStorageObjectPtr ArrayData::clone() const
{
	ArrayData *data = new ArrayData(get_name(), data_);
	return IDataStorageObjectPtr(data);
}

IDataStorageObject::Type ArrayData::get_type()
{
	return IDataStorageObject::TypeArray;
}

} // namespace DataStorage

} // namespace GDS
