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
	SimpleData(const SimpleData<T>& obj);
	SimpleData(const std::string& name, T data);
	virtual ~SimpleData();

	void set_data(const T& data);
	T& get_data();
	
	// IDataStorageObject
	virtual std::string get_data_type() const;
	virtual unsigned get_data_size() const;
	virtual IDataStorageObject::Type get_type();
	virtual void serialize_head(std::vector<uint8_t>& bytes);
	virtual void serialize_body(std::vector<uint8_t>& bytes);
	virtual IDataStorageObjectPtr clone() const;

	SimpleData<T>& operator= (const T& l);
	SimpleData<T>& operator= (SimpleData<T>& l);

private:
	T data_;
};

template<typename T>
SimpleData<T>::SimpleData()
	: IDataStorageObject(std::string())
{

}


template<typename T>
SimpleData<T>::SimpleData(const SimpleData<T>& obj)
	: IDataStorageObject(obj.get_name())
	, data_(obj.data_)
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
std::string SimpleData<T>::get_data_type() const
{
	return std::string(typeid(T).name());
}

template<typename T>
unsigned SimpleData<T>::get_data_size() const
{
	return sizeof(T);
}

template<typename T>
void SimpleData<T>::serialize_head(std::vector<uint8_t>& bytes)
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
	bytes.push_back(cDelimiterStr);
}

template<typename T>
void SimpleData<T>::serialize_body(std::vector<uint8_t>& bytes)
{
	// data
	for (unsigned int i = 0; i < sizeof(T); ++i)
	{
		unsigned char tmp = *((unsigned char*)(&data_) + i);
		bytes.push_back(tmp);
	}
}

template<typename T>
IDataStorageObjectPtr SimpleData<T>::clone() const
{
	SimpleData<T> *simple = new SimpleData<T>(get_name(), data_);
	return IDataStorageObjectPtr(simple);
}

template<typename T>
IDataStorageObject::Type SimpleData<T>::get_type()
{
	return IDataStorageObject::TypeSimple;
}

template<typename T>
SimpleData<T>& SimpleData<T>::operator= (const T& l)
{
	this->data_ = l;
	return *this;
}

template<typename T>
SimpleData<T>& SimpleData<T>::operator= (SimpleData<T>& l)
{
	this->data_ = l.get_data();
	this->set_name(l.get_name());
	return *this;
}

} // namespace DataStorage

} // namespace GDS
