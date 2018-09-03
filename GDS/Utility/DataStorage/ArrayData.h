#pragma once

#include "IDataStorageObject.h"

namespace GDS
{

namespace DataStorage
{

template<typename T>
class ArrayData : public IDataStorageObject
{
public:
	ArrayData();
	ArrayData(std::string name, unsigned data_size, const T* data);
	ArrayData(std::string name, const std::vector<T>& data);
	virtual ~ArrayData();

	void set_data(unsigned data_size, const T* data);
	void set_data(const std::vector<T>& data);
	const std::vector<T>& get_data() const;
	unsigned get_size();

	T& operator [] (int index);

	// IDataStorageObject
	virtual unsigned get_data_size() const;
	virtual std::vector<unsigned char> serialize();

private:
	std::vector<T> data_;
};

template<typename T>
ArrayData<T>::ArrayData()
	: IDataStorageObject(std::string())
{

}

template<typename T>
ArrayData<T>::ArrayData(std::string name, unsigned data_size, const T* data)
	: IDataStorageObject(name)
{
	data_.insert(data_.end(), data, data + data_size);
}

template<typename T>
ArrayData<T>::ArrayData(std::string name, const std::vector<T>& data)
	: IDataStorageObject(name)
{
	data_.insert(data_.end(), data.begin(), data.end());
}

template<typename T>
ArrayData<T>::~ArrayData()
{
	data_.clear();
}

template<typename T>
void ArrayData<T>::set_data(unsigned data_size, const T* data)
{
	data_.insert(data_.end(), data, data + data_size);
}

template<typename T>
void ArrayData<T>::set_data(const std::vector<T>& data)
{
	data_.insert(data_.end(), data.begin(), data.end());
}

template<typename T>
const std::vector<T>& ArrayData<T>::get_data() const
{
	return data_;
}

template<typename T>
unsigned ArrayData<T>::get_size()
{
	return data_.size();
}

template<typename T>
T& ArrayData<T>::operator [] (int index)
{
	return data_[index];
}

template<typename T>
unsigned ArrayData<T>::get_data_size() const
{
	return sizeof(T);
}

template<typename T>
std::vector<unsigned char> ArrayData<T>::serialize()
{
	using namespace GDS::DataStorage;

	std::vector<unsigned char> bytes;

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

	return bytes;
}

} // namespace DataStorage

} // namespace GDS

