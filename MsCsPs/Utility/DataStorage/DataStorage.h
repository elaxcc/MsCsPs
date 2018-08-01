#pragma once

#include "Utility/DataStorage/DataStorageCommon.h"

namespace GDS
{

namespace DataStorage
{

class Serializer
{
public:
	Serializer();
	~Serializer();

	void exec();
	void insert(unsigned int data_size, void *data);
	const std::vector<unsigned char>& get_data() const;

private:
	std::vector<unsigned char> data_;
};

class Parser
{
public:
	Parser();
	~Parser();

	int exec();

private:

};

} // namespace DataStorage

} // namespace GDS
