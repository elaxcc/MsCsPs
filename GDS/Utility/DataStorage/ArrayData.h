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
	ArrayData(unsigned data_size);
	ArrayData(const std::string& name, T* data, unsigned data_size);
	ArrayData(const std::string& name, const std::vector<T>& data);
	virtual ~ArrayData();

	void set_data(T* data, unsigned data_size);
	void set_data(const std::vector<T>& data);
	const std::vector<T>& get_data() const;
	unsigned get_size();

	T& operator[] (int index);

	// IDataStorageObject
	virtual std::string get_data_type() const;
	virtual unsigned get_data_size() const;
	virtual IDataStorageObject::Type get_type();
	virtual void serialize_head(std::vector<uint8_t>& bytes);
	virtual void serialize_body(std::vector<uint8_t>& bytes);
	virtual IDataStorageObjectPtr clone() const;

private:
	std::vector<T> data_;
};

template <typename T>
ArrayData<T>::ArrayData(unsigned data_size)
	: IDataStorageObject(std::string())
	, data_(data_size)
{

}

template <typename T>
ArrayData<T>::ArrayData(const std::string& name, T* data, unsigned data_size)
	: IDataStorageObject(name)
	, data_(data_size)
{
	for (unsigned i = 0; i < data_size; ++i)
	{
		data_[i] = data[i];
	}
}

template <typename T>
ArrayData<T>::ArrayData(const std::string& name, const std::vector<T>& data)
	: IDataStorageObject(name)
	, data_(data.size())
{
	for (unsigned i = 0; i < data_.size(); ++i)
	{
		T tmp = data[i];
		data_[i] = tmp;
	}
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
		data_[i] = data[i];
	}
}

template <typename T>
void ArrayData<T>::set_data(const std::vector<T>& data)
{
	for (unsigned i = 0; i < data_.size(); ++i)
	{
		T tmp = data[i]; // if not create tmp then get error when execute
		data_[i] = tmp;
	}
}

template <typename T>
const std::vector<T>& ArrayData<T>::get_data() const
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
std::string ArrayData<T>::get_data_type() const
{
	return T().get_data_type();
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
void ArrayData<T>::serialize_head(std::vector<uint8_t>& bytes)
{
	// type
	std::string type_name = get_data_type();
	bytes.insert(bytes.end(), type_name.begin(), type_name.end());

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

template <typename T>
void ArrayData<T>::serialize_body(std::vector<uint8_t>& bytes)
{
	// data
	for (unsigned int i = 0; i < data_.size(); ++i)
	{
		data_[i].serialize_body(bytes);
	}
}

template<typename T>
IDataStorageObjectPtr ArrayData<T>::clone() const
{
	ArrayData<T> *ptr = new ArrayData<T>(get_name(), data_);
	return IDataStorageObjectPtr(ptr);
}

template <typename T>
IDataStorageObject::Type ArrayData<T>::get_type()
{
	return IDataStorageObject::TypeArray;
}

} // namespace DataStorage

} // namespace GDS

