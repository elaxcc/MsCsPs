#pragma once

#include "IDataStorageObject.h"
#include "StandartTypeBuilder.h"

namespace GDS
{

namespace DataStorage
{

class IDataStorageFactory
{
public:
	virtual ~IDataStorageFactory() {};
	virtual unsigned int needs_bytes() const = 0;
	virtual IDataStorageObjectPtr create(const std::string &name, std::vector<uint8_t> raw_bytes) const = 0;
};
typedef std::shared_ptr<IDataStorageFactory> IDataStorageFactoryPtr;

template<typename T>
class DataStorageFactorySimple : public IDataStorageFactory
{
public:
	DataStorageFactorySimple();
	~DataStorageFactorySimple();

	// IDataStorageFactory
	virtual unsigned int needs_bytes() const;
	virtual IDataStorageObjectPtr create(const std::string &name, std::vector<uint8_t> raw_bytes) const;
};

class DataStorageFactory
{
public:
	DataStorageFactory();
	~DataStorageFactory();

	unsigned int needs_bytes(const std::string &type) const;
	IDataStorageObjectPtr create_simple(const std::string &type,
		const std::string &name, std::vector<uint8_t> raw_bytes) const;

private:
	std::map<std::string, IDataStorageFactoryPtr> simple_factories_;
};

} // namespace DataStorage

} // namespace GDS