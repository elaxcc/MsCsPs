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
	~ArrayData();

	void set_data(unsigned data_size, const T* data);
	void set_data(const std::vector<T>& data);
	const std::vector<T>& get_data() const;

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
unsigned ArrayData<T>::get_data_size() const
{
	return sizeof(T);
}

template<typename T>
std::vector<unsigned char> ArrayData<T>::serialize()
{
	//!fixme
	return std::vector<unsigned char>();
}

} // namespace DataStorage

} // namespace GDS

