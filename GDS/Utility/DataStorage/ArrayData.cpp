#include <stdafx.h>

#include "ArrayData.h"

namespace GDS
{

namespace DataStorage
{

ArrayData::ArrayData()
	: IDataStorageObject(std::string())
{

}

ArrayData::ArrayData(const std::string& name, IDataStorageObject* data, unsigned data_size)
	: IDataStorageObject(name)
{
	data_.insert(data_.end(), data, data + data_size);
}

ArrayData::ArrayData(const std::string& name, const std::vector<IDataStorageObject*>& data)
	: IDataStorageObject(name)
{
	data_.insert(data_.end(), data.begin(), data.end());
}

ArrayData::~ArrayData()
{
	for (IDataStorageObject* d : data_)
	{
		if (d)
		{
			delete d;
		}
	}
	data_.clear();
}

void ArrayData::set_data(IDataStorageObject* data, unsigned data_size)
{
	data_.insert(data_.end(), data, data + data_size);
}

void ArrayData::set_data(const std::vector<IDataStorageObject*>& data)
{
	data_.insert(data_.end(), data.begin(), data.end());
}

std::vector<IDataStorageObject*>& ArrayData::get_data()
{
	return data_;
}

unsigned ArrayData::get_size()
{
	return data_.size();
}

IDataStorageObject* ArrayData::operator [] (int index)
{
	return data_[index];
}

unsigned ArrayData::get_data_size() const
{
	if (data_.empty())
	{
		return 0;
	}
	return data_[0]->get_data_size();
}

std::vector<unsigned char> ArrayData::serialize()
{
	using namespace GDS::DataStorage;

	std::vector<unsigned char> bytes;
	/*
	// size
	unsigned int type_size = sizeof(T);
	bytes.push_back(type_size);
	bytes.push_back(cDelimiterStr);

	// name
	for (char c : get_name())
	bytes.push_back(c);

	// array size
	bytes.push_back(cFirstBracketStr);
	unsigned int data_cnt = data_.size();
	for (unsigned int i = 0; i < sizeof(unsigned int); ++i)
	{
	unsigned char tmp = *((unsigned char*)(&data_cnt) + i);
	bytes.push_back(tmp);
	}
	bytes.push_back(cLastBracketStr);
	bytes.push_back(cDelimiterStr);

	// data
	for (unsigned int j = 0; j < data_cnt; ++j)
	{
	T element = data_[j];
	for (unsigned int i = 0; i < type_size; ++i)
	{
	unsigned char tmp = *((unsigned char*)(&element) + i);
	bytes.push_back(tmp);
	}
	}
	*/
	return bytes;
}

IDataStorageObject::Type ArrayData::get_type()
{
	return IDataStorageObject::TypeArray;
}

} // namespace DataStorage

} // namespace GDS
