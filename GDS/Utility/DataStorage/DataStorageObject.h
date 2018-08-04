#pragma once

#include "IDataStorageObject.h"

namespace GDS
{

namespace DataStorage
{

template<typename T>
class DataStorageObject : public IDataStorageObject
{
public:
	DataStorageObject(const std::string& name);
	~DataStorageObject();
	
	void set_name(const std::string& name);
	const std::string& get_name() const;
	unsigned get_data_size() const;
	
	// IDataStorageObject
	virtual std::vector<unsigned char> serialize() = 0;

private:
	std::string name_;
};

template<typename T>
DataStorageObject<T>::DataStorageObject(const std::string& name)
	: name_(name)
{

}

template<typename T>
DataStorageObject<T>::~DataStorageObject()
{

}

template<typename T>
void DataStorageObject<T>::set_name(const std::string& name)
{
	name_ = name;
}

template<typename T>
const std::string& DataStorageObject<T>::get_name() const
{
	return name_;
}

template<typename T>
unsigned DataStorageObject<T>::get_data_size() const
{
	return sizeof(T);
}

} // namespace DataStorage

} // namespace GDS

