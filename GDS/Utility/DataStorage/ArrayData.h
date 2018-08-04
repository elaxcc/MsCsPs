#pragma once

#include "DataStorageObject.h"

namespace GDS
{

namespace DataStorage
{

template<typename T>
class ArrayData : public DataStorageObject<T>
{
public:
	ArrayData();
	ArrayData(std::string name, unsigned data_size, const T* data);
	ArrayData(std::string name, const std::vector<T>& data);
	~ArrayData();

	void set_data(unsigned data_size, const T* data);
	void set_data(const std::vector<T>& data);
	const std::vector<T>& get_data() const;

	// IDataStorageObject
	std::vector<unsigned char> serialize();

private:
	std::vector<T> data_;
};

template<typename T>
ArrayData<T>::ArrayData()
	: DataStorageObject(std::string())
{

}

template<typename T>
ArrayData<T>::ArrayData(std::string name, unsigned data_size, const T* data)
	: DataStorageObject(name)
{
	data_.insert(data_.end(), data, data + data_size);
}

template<typename T>
ArrayData<T>::ArrayData(std::string name, const std::vector<T>& data)
	: DataStorageObject(name)
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
std::vector<unsigned char> ArrayData<T>::serialize()
{
	//!fixme
	return std::vector<unsigned char>();
}

} // namespace DataStorage

} // namespace GDS

