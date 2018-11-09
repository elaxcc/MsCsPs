#pragma once

#include "DataStorageCommon.h"

namespace GDS
{

namespace DataStorage
{

class IDataStorageObject;
typedef std::shared_ptr<IDataStorageObject> IDataStorageObjectPtr;

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

	virtual std::string get_data_type() const = 0;
	virtual unsigned get_data_size() const = 0;
	virtual Type get_type() = 0;
	std::vector<uint8_t> serialize();
	virtual void serialize_head(std::vector<uint8_t>& bytes) = 0;
	virtual void serialize_body(std::vector<uint8_t>& bytes) = 0;
	virtual IDataStorageObjectPtr clone() const = 0;

private:
	std::string name_;
};

} // namespace DataStorage

} // namespace GDS

