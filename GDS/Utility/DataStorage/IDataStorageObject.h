#pragma once

#include "DataStorageCommon.h"

namespace GDS
{

namespace DataStorage
{

class IDataStorageObject
{
public:
	enum Type
	{
		TypeSimple,
		TypeArray,
		TypeObject
	};

	IDataStorageObject(const std::string& name);
	virtual ~IDataStorageObject();
	
	void set_name(const std::string& name);
	const std::string& get_name() const;

	virtual unsigned get_data_size() const = 0;
	virtual Type get_type() = 0;
	std::vector<unsigned char> serialize();
	virtual void serialize_head(std::vector<unsigned char>& bytes) = 0;
	virtual void serialize_data(std::vector<unsigned char>& bytes) = 0;

private:
	std::string name_;
};
typedef std::shared_ptr<IDataStorageObject> IDataStorageObjectPtr;

} // namespace DataStorage

} // namespace GDS

