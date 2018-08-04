#pragma once

#include "SimpleData.h"
#include "ArrayData.h"

namespace GDS
{

namespace DataStorage
{

class ObjectData : public IDataObject
{
public:
	ObjectData();
	ObjectData(const std::string& name);
	~ObjectData();

	void set_name(const std::string& name);
	const std::string& get_name() const;

	bool insert_field();


	// IDataObject
	std::vector<unsigned char> serialize();

private:
	std::string name_;
};

} // namespace DataStorage

} // namespace GDS

