#pragma once

#include "IDataStorageObject.h"

namespace GDS
{

namespace DataStorage
{

class ArrayData : public IDataStorageObject
{
public:
	ArrayData();
	ArrayData(const std::string& name, IDataStorageObject* data, unsigned data_size);
	ArrayData(const std::string& name, const std::vector<IDataStorageObject*>& data);
	virtual ~ArrayData();

	void set_data(IDataStorageObject* data, unsigned data_size);
	void set_data(const std::vector<IDataStorageObject*>& data);
	std::vector<IDataStorageObject*>& get_data();
	unsigned get_size();

	IDataStorageObject* operator [] (int index);

	// IDataStorageObject
	virtual unsigned get_data_size() const;
	virtual std::vector<unsigned char> serialize();
	virtual IDataStorageObject::Type get_type();

private:
	std::vector<IDataStorageObject*> data_;
};

} // namespace DataStorage

} // namespace GDS

