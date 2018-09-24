#pragma once

#include "IDataStorageObject.h"

namespace GDS
{

namespace DataStorage
{

template <typename T>
class SimpleData : public IDataStorageObject
{
public:
	SimpleData();
	SimpleData(const std::string& name, T data);
	virtual ~SimpleData();

	void set_data(const T& data);
	T& get_data();
	
	// IDataStorageObject
	virtual unsigned get_data_size() const;
	virtual std::vector<unsigned char> serialize();
	virtual IDataStorageObject::Type get_type();

private:
	T data_;
};

template<typename T>
SimpleData<T>::SimpleData()
	: IDataStorageObject(std::string())
{

}

template<typename T>
SimpleData<T>::SimpleData(const std::string& name, T data)
	: IDataStorageObject(name)
	, data_(data)
{

}

template<typename T>
SimpleData<T>::~SimpleData()
{

}

template<typename T>
void SimpleData<T>::set_data(const T& data)
{
	data_ = data;
}

template<typename T>
T& SimpleData<T>::get_data()
{
	return data_;
}

template<typename T>
unsigned SimpleData<T>::get_data_size() const
{
	return sizeof(T);
}

template<typename T>
std::vector<unsigned char> SimpleData<T>::serialize()
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
	bytes.push_back(cDelimiterStr);
	GDS::DataStorage::cDelimiterStr;
	// data
	for (unsigned int i = 0; i < type_size; ++i)
	{
		unsigned char tmp = *((unsigned char*)(&data_) + i);
		bytes.push_back(tmp);
	}

	return bytes;
}

template<typename T>
IDataStorageObject::Type SimpleData<T>::get_type()
{
	return IDataStorageObject::TypeSimple;
}

} // namespace DataStorage

} // namespace GDS
