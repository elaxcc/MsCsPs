#include "stdafx.h"

#include "DataStorageFactory.h"

#include "SimpleData.h"

namespace GDS
{

namespace DataStorage
{

template<typename T>
DataStorageSimpleFactory<T>::DataStorageSimpleFactory()
{


}

template<typename T>
DataStorageSimpleFactory<T>::~DataStorageSimpleFactory()
{

}

template<typename T>
unsigned int DataStorageSimpleFactory<T>::needs_bytes() const
{
	return sizeof(T);
}

template<typename T>
IDataStorageObjectPtr DataStorageSimpleFactory<T>::create(const std::string &name,
	std::vector<uint8_t> raw_bytes) const
{/*
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
	return IDataStorageObjectPtr(new SimpleData<T>());*/
}

DataStorageArrayFactory::DataStorageArrayFactory(const std::map<std::string,
	IDataStorageSimpleFactoryPtr> &simple_factories)
	: simple_factories_(simple_factories)
{

}

DataStorageArrayFactory::~DataStorageArrayFactory()
{

}

unsigned int DataStorageArrayFactory::needs_bytes(const std::string &type, unsigned int size) const
{
// 	std::map<std::string, IDataStorageSimpleFactoryPtr>::const_iterator iter = simple_factories_.find(type);
// 	if (iter != simple_factories_.end())
// 	{
// 		return iter->second->needs_bytes() * size;
// 	}
	return 0;
}

IDataStorageObjectPtr DataStorageArrayFactory::create(const std::string &type, const std::string &name,
	unsigned int size, std::vector<uint8_t> raw_bytes) const
{
// 	std::map<std::string, IDataStorageSimpleFactoryPtr>::const_iterator iter = simple_factories_.find(type);
// 	if (iter != simple_factories_.end())
// 	{
// 		for (unsigned i = 0; i < size; i++)
// 		{
// 			
// 		}
// 		
// 	}
	return IDataStorageObjectPtr();
}

DataStorageFactory::DataStorageFactory()
	: array_factory_(simple_factories_)
{/*
	// char
	simple_factories_.insert(
		std::pair<std::string, IDataStorageSimpleFactoryPtr>(
			DataStorage::cTypeStr_char, IDataStorageSimpleFactoryPtr(
				new DataStorageSimpleFactory<char>)));

	// unsigned char
	simple_factories_.insert(
		std::pair<std::string, IDataStorageSimpleFactoryPtr>(
			DataStorage::cTypeStr_unsigned_char, IDataStorageSimpleFactoryPtr(
				new DataStorageSimpleFactory<unsigned char>)));

	// short
	simple_factories_.insert(
		std::pair<std::string, IDataStorageSimpleFactoryPtr>(
			DataStorage::cTypeStr_short, IDataStorageSimpleFactoryPtr(
				new DataStorageSimpleFactory<short>)));

	// unsigned short
	simple_factories_.insert(
		std::pair<std::string, IDataStorageSimpleFactoryPtr>(
			DataStorage::cTypeStr_unsigned_char, IDataStorageSimpleFactoryPtr(
				new DataStorageSimpleFactory<unsigned short>)));

	// int
	simple_factories_.insert(
		std::pair<std::string, IDataStorageSimpleFactoryPtr>(
			DataStorage::cTypeStr_int, IDataStorageSimpleFactoryPtr(
				new DataStorageSimpleFactory<int>)));

	// unsigned int
	simple_factories_.insert(
		std::pair<std::string, IDataStorageSimpleFactoryPtr>(
			DataStorage::cTypeStr_unsigned_int, IDataStorageSimpleFactoryPtr(
				new DataStorageSimpleFactory<unsigned int>)));

	// long long
	simple_factories_.insert(
		std::pair<std::string, IDataStorageSimpleFactoryPtr>(
			DataStorage::cTypeStr_long_long, IDataStorageSimpleFactoryPtr(
				new DataStorageSimpleFactory<long long>)));

	// unsigned long long
	simple_factories_.insert(
		std::pair<std::string, IDataStorageSimpleFactoryPtr>(
			DataStorage::cTypeStr_unsigned_long_long, IDataStorageSimpleFactoryPtr(
				new DataStorageSimpleFactory<unsigned long long>)));

	// float
	simple_factories_.insert(
		std::pair<std::string, IDataStorageSimpleFactoryPtr>(
			DataStorage::cTypeStr_float, IDataStorageSimpleFactoryPtr(
				new DataStorageSimpleFactory<float>)));

	// double
	simple_factories_.insert(
		std::pair<std::string, IDataStorageSimpleFactoryPtr>(
			DataStorage::cTypeStr_double, IDataStorageSimpleFactoryPtr(
				new DataStorageSimpleFactory<double>)));

	// int8_t
	simple_factories_.insert(
		std::pair<std::string, IDataStorageSimpleFactoryPtr>(
			DataStorage::cTypeStr_int8_t, IDataStorageSimpleFactoryPtr(
				new DataStorageSimpleFactory<int8_t>)));

	// uint8_t
	simple_factories_.insert(
		std::pair<std::string, IDataStorageSimpleFactoryPtr>(
			DataStorage::cTypeStr_uint8_t, IDataStorageSimpleFactoryPtr(
				new DataStorageSimpleFactory<uint8_t>)));

	// int16_t
	simple_factories_.insert(
		std::pair<std::string, IDataStorageSimpleFactoryPtr>(
			DataStorage::cTypeStr_int16_t, IDataStorageSimpleFactoryPtr(
				new DataStorageSimpleFactory<int16_t>)));

	// uint16_t
	simple_factories_.insert(
		std::pair<std::string, IDataStorageSimpleFactoryPtr>(
			DataStorage::cTypeStr_uint16_t, IDataStorageSimpleFactoryPtr(
				new DataStorageSimpleFactory<uint16_t>)));

	// int32_t
	simple_factories_.insert(
		std::pair<std::string, IDataStorageSimpleFactoryPtr>(
			DataStorage::cTypeStr_int32_t, IDataStorageSimpleFactoryPtr(
				new DataStorageSimpleFactory<int32_t>)));

	// uint32_t
	simple_factories_.insert(
		std::pair<std::string, IDataStorageSimpleFactoryPtr>(
			DataStorage::cTypeStr_uint32_t, IDataStorageSimpleFactoryPtr(
				new DataStorageSimpleFactory<uint32_t>)));

	// int64_t
	simple_factories_.insert(
		std::pair<std::string, IDataStorageSimpleFactoryPtr>(
			DataStorage::cTypeStr_int64_t, IDataStorageSimpleFactoryPtr(
				new DataStorageSimpleFactory<int64_t>)));

	// uint64_t
	simple_factories_.insert(
		std::pair<std::string, IDataStorageSimpleFactoryPtr>(
			DataStorage::cTypeStr_uint64_t, IDataStorageSimpleFactoryPtr(
				new DataStorageSimpleFactory<uint64_t>)));*/
}

DataStorageFactory::~DataStorageFactory()
{
	simple_factories_.clear();
}

unsigned int DataStorageFactory::bytes_needs_for_simple(const std::string &type) const
{
// 	std::map<std::string, IDataStorageSimpleFactoryPtr>::const_iterator iter = simple_factories_.find(type);
// 	if (iter != simple_factories_.end())
// 	{
// 		return iter->second->needs_bytes();
// 	}
	return 0;
}

IDataStorageObjectPtr DataStorageFactory::create_simple(const std::string &type,
	const std::string &name, std::vector<uint8_t> raw_bytes) const
{
// 	std::map<std::string, IDataStorageSimpleFactoryPtr>::const_iterator iter = simple_factories_.find(type);
// 	if (iter != simple_factories_.end())
// 	{
// 		return iter->second->create(name, raw_bytes);
// 	}
	return IDataStorageObjectPtr();
}

} // namespace DataStorage

} // namespace GDS
