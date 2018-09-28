#pragma once

#include "IDataStorageObject.h"

namespace GDS
{

namespace DataStorage
{

template <typename T>
class ArrayData : public IDataStorageObject
{
public:
	ArrayData();
	ArrayData(const std::string& name, T* data, unsigned data_size);
	ArrayData(const std::string& name, const std::vector<T>& data);
	virtual ~ArrayData();

	void set_data(T* data, unsigned data_size);
	void set_data(const std::vector<T>& data);
	std::vector<T>& get_data();
	unsigned get_size();

	T& operator[] (int index);

	// IDataStorageObject
	virtual unsigned get_data_size() const;
	virtual IDataStorageObject::Type get_type();
	virtual void serialize_head(std::vector<unsigned char>& bytes);
	virtual void serialize_data(std::vector<unsigned char>& bytes);

private:
	std::vector<T> data_;
};

template <typename T>
ArrayData<T>::ArrayData()
	: IDataStorageObject(std::string())
{

}

template <typename T>
ArrayData<T>::ArrayData(const std::string& name, T* data, unsigned data_size)
	: IDataStorageObject(name)
{
	for (unsigned i = 0; i < data_size; ++i)
	{
		data_.push_back(data[i]);
	}
}

template <typename T>
ArrayData<T>::ArrayData(const std::string& name, const std::vector<T>& data)
	: IDataStorageObject(name)
{
	data_.insert(data_.end(), data.begin(), data.end());
}

template <typename T>
ArrayData<T>::~ArrayData()
{
	data_.clear();
}

template <typename T>
void ArrayData<T>::set_data(T* data, unsigned data_size)
{
	for (unsigned i = 0; i < data_size; ++i)
	{
		data_.push_back(data[i]);
	}
}

template <typename T>
void ArrayData<T>::set_data(const std::vector<T>& data)
{
	data_.insert(data_.end(), data.begin(), data.end());
}

template <typename T>
std::vector<T>& ArrayData<T>::get_data()
{
	return data_;
}

template <typename T>
unsigned ArrayData<T>::get_size()
{
	return data_.size();
}

template <typename T>
T& ArrayData<T>::operator[] (int index)
{
	return data_[index];
}

template <typename T>
unsigned ArrayData<T>::get_data_size() const
{
	if (data_.empty())
	{
		return 0;
	}
	return data_[0].get_data_size();
}

template <typename T>
void ArrayData<T>::serialize_head(std::vector<unsigned char>& bytes)
{
	// type
	unsigned int type_size = data_.empty() ? 0 : data_[0].get_data_size();
	bytes.push_back(type_size);
	bytes.push_back(cDelimiterStr);

	// name
	for (char c : get_name())
	{
		bytes.push_back(c);
	}

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
}

template <typename T>
void ArrayData<T>::serialize_data(std::vector<unsigned char>& bytes)
{
	// data
	for (unsigned int i = 0; i < data_.size(); ++i)
	{
		data_[i].serialize_data(bytes);
	}
}

template <typename T>
IDataStorageObject::Type ArrayData<T>::get_type()
{
	return IDataStorageObject::TypeArray;
}

} // namespace DataStorage

} // namespace GDS

