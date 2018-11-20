#pragma once

#include "IDataStorageObject.h"

namespace GDS
{

namespace DataStorage
{

class ArrayData : public IDataStorageObject
{
public:
	ArrayData(const std::string &name, unsigned size);
	ArrayData(const std::string& name, IDataStorageObjectPtr* data, unsigned size);
	ArrayData(const std::string& name, const std::vector<IDataStorageObjectPtr>& data);
	virtual ~ArrayData();
	
	template<typename T>
	void set_data(T* data, unsigned data_size);
	void set_data(const std::vector<IDataStorageObjectPtr>& data);
	std::vector<IDataStorageObjectPtr>& get_data();
	unsigned get_size();

	IDataStorageObjectPtr& operator[] (int index);

	// IDataStorageObject
	virtual uint8_t get_data_size() const;
	virtual IDataStorageObject::Type get_type();
	virtual void serialize_head(std::vector<uint8_t>& bytes);
	virtual void serialize_body(std::vector<uint8_t>& bytes);
	virtual IDataStorageObjectPtr clone() const;

private:
	std::vector<IDataStorageObjectPtr> data_;
};

template<typename T>
void ArrayData::set_data(T* data, unsigned data_size)
{
	for (unsigned i = 0; i < data_size; ++i)
	{
		data_[i] = data[i].clone();
	}
}

} // namespace DataStorage

} // namespace GDS
