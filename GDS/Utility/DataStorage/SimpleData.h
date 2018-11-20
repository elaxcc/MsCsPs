#pragma once

#include "IDataStorageObject.h"

namespace GDS
{

namespace DataStorage
{

class SimpleData : public IDataStorageObject
{
public:
	SimpleData();
	SimpleData(const SimpleData &obj);
	template<typename T>
	SimpleData(const std::string &name, T data);
	SimpleData(const std::string &name, void *data, unsigned int data_size);
	virtual ~SimpleData();

	template<typename T>
	void set_data(T data);
	template<typename T>
	T& get_data();
	
	// IDataStorageObject
	virtual unsigned char get_data_size() const;
	virtual IDataStorageObject::Type get_type();
	virtual void serialize_head(std::vector<uint8_t> &bytes);
	virtual void serialize_body(std::vector<uint8_t> &bytes);
	virtual IDataStorageObjectPtr clone() const;

	template <typename T>
	SimpleData& operator= (const T &r);
	SimpleData& operator= (const SimpleData &r);

private:
	void clean_data();
	void copy_data(void *data, unsigned int data_size);

	unsigned int data_size_;
	uint8_t *data_;
};

template<typename T>
SimpleData::SimpleData(const std::string &name, T data)
	: IDataStorageObject(name)
	, data_size_(sizeof(T))
{
	copy_data((void *)&data, data_size_);
}

template<typename T>
void SimpleData::set_data(T data)
{
	clean_data();
	copy_data((void *) &data, sizeof(T));
}

template<typename T>
T& SimpleData::get_data()
{
	return *((T *) data_);
}

template <typename T>
SimpleData& SimpleData::operator= (const T &r)
{
	clean_data();
	copy_data((void *)&r, sizeof(T));
	return *this;
}

} // namespace DataStorage

} // namespace GDS
