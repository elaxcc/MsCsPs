#include "stdafx.h"

#include "DataStorageFactory.h"

#include "SimpleData.h"

namespace GDS
{

namespace DataStorage
{

template<typename T>
DataStorageFactorySimple<T>::DataStorageFactorySimple()
{


}

template<typename T>
DataStorageFactorySimple<T>::~DataStorageFactorySimple()
{

}

template<typename T>
unsigned int DataStorageFactorySimple<T>::needs_bytes() const
{
	return sizeof(T);
}

template<typename T>
IDataStorageObjectPtr DataStorageFactorySimple<T>::create(const std::string &name, std::vector<uint8_t> raw_bytes) const
{
	unsigned int data_size = sizeof(T);

	assert(data_size == raw_bytes.size());

	if (data_size == raw_bytes.size())
	{
		// create temporary buffer because we use here float and double too,
		// binary operations with this types are invalid
		uint64_t data = 0;
		for (unsigned int i = 0; i < data_size; ++i)
		{
			data |= raw_bytes[i] << 8 * i;
		}
		return IDataStorageObjectPtr(new SimpleData<T>(name, static_cast<T>(data)));
	}
	return IDataStorageObjectPtr(new SimpleData<T>());
}

DataStorageFactory::DataStorageFactory()
{
	// int8_t
	simple_factories_.insert(
		std::pair<std::string, IDataStorageFactoryPtr>(
			DataStorage::cTypeStr_char, IDataStorageFactoryPtr(new DataStorageFactorySimple<int8_t>)));

	// uint8_t
	simple_factories_.insert(
		std::pair<std::string, IDataStorageFactoryPtr>(
			DataStorage::cTypeStr_unsigned_char, IDataStorageFactoryPtr(new DataStorageFactorySimple<uint8_t>)));

	// int16_t
	simple_factories_.insert(
		std::pair<std::string, IDataStorageFactoryPtr>(
			DataStorage::cTypeStr_short, IDataStorageFactoryPtr(new DataStorageFactorySimple<int16_t>)));

	// uint16_t
	simple_factories_.insert(
		std::pair<std::string, IDataStorageFactoryPtr>(
			DataStorage::cTypeStr_unsigned_char, IDataStorageFactoryPtr(new DataStorageFactorySimple<uint16_t>)));

	// int32_t
	simple_factories_.insert(
		std::pair<std::string, IDataStorageFactoryPtr>(
			DataStorage::cTypeStr_int, IDataStorageFactoryPtr(new DataStorageFactorySimple<int32_t>)));

	// uint32_t
	simple_factories_.insert(
		std::pair<std::string, IDataStorageFactoryPtr>(
			DataStorage::cTypeStr_unsigned_int, IDataStorageFactoryPtr(new DataStorageFactorySimple<uint32_t>)));

	// int64_t
	simple_factories_.insert(
		std::pair<std::string, IDataStorageFactoryPtr>(
			DataStorage::cTypeStr_long_long, IDataStorageFactoryPtr(new DataStorageFactorySimple<int64_t>)));

	// uint64_t
	simple_factories_.insert(
		std::pair<std::string, IDataStorageFactoryPtr>(
			DataStorage::cTypeStr_unsigned_long_long, IDataStorageFactoryPtr(new DataStorageFactorySimple<uint64_t>)));

	// float
	simple_factories_.insert(
		std::pair<std::string, IDataStorageFactoryPtr>(
			DataStorage::cTypeStr_float, IDataStorageFactoryPtr(new DataStorageFactorySimple<float>)));

	// double
	simple_factories_.insert(
		std::pair<std::string, IDataStorageFactoryPtr>(
			DataStorage::cTypeStr_double, IDataStorageFactoryPtr(new DataStorageFactorySimple<double>)));
}

DataStorageFactory::~DataStorageFactory()
{
	simple_factories_.clear();
}

unsigned int DataStorageFactory::needs_bytes(const std::string &type) const
{
	std::map<std::string, IDataStorageFactoryPtr>::const_iterator iter = simple_factories_.find(type);
	if (iter != simple_factories_.end())
	{
		return iter->second->needs_bytes();
	}
	return 0;
}

IDataStorageObjectPtr DataStorageFactory::create_simple(const std::string &type,
	const std::string &name, std::vector<uint8_t> raw_bytes) const
{
	std::map<std::string, IDataStorageFactoryPtr>::const_iterator iter = simple_factories_.find(type);
	if (iter != simple_factories_.end())
	{
		return iter->second->create(name, raw_bytes);
	}
	return IDataStorageObjectPtr();
}

} // namespace DataStorage

} // namespace GDS
