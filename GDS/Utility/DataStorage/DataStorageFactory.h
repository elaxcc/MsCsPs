#pragma once

#include "IDataStorageObject.h"

namespace GDS
{

namespace DataStorage
{

class IDataStorageSimpleFactory
{
public:
	virtual ~IDataStorageSimpleFactory() {};
	virtual unsigned int needs_bytes() const = 0;
	virtual IDataStorageObjectPtr create(const std::string &name, std::vector<uint8_t> raw_bytes) const = 0;
};
typedef std::shared_ptr<IDataStorageSimpleFactory> IDataStorageSimpleFactoryPtr;

template<typename T>
class DataStorageSimpleFactory : public IDataStorageSimpleFactory
{
public:
	DataStorageSimpleFactory();
	virtual ~DataStorageSimpleFactory();

	// IDataStorageFactory
	virtual unsigned int needs_bytes() const;
	virtual IDataStorageObjectPtr create(const std::string &name, std::vector<uint8_t> raw_bytes) const;
};

class DataStorageArrayFactory
{
public:
	DataStorageArrayFactory(const std::map<std::string, IDataStorageSimpleFactoryPtr> &simple_factories);
	~DataStorageArrayFactory();

	unsigned int needs_bytes(const std::string &type, unsigned int size) const;
	IDataStorageObjectPtr create(const std::string &type, const std::string &name,
		unsigned int size, std::vector<uint8_t> raw_bytes) const;

private:
	const std::map<std::string, IDataStorageSimpleFactoryPtr> &simple_factories_;
};

class DataStorageFactory
{
public:
	DataStorageFactory();
	~DataStorageFactory();

	unsigned int bytes_needs_for_simple(const std::string &type) const;
	IDataStorageObjectPtr create_simple(const std::string &type,
		const std::string &name, std::vector<uint8_t> raw_bytes) const;

private:
	std::map<std::string, IDataStorageSimpleFactoryPtr> simple_factories_;
	DataStorageArrayFactory array_factory_;
};

} // namespace DataStorage

} // namespace GDS