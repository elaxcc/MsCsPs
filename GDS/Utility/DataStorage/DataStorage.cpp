#include "stdafx.h"

#include "DataStorage.h"

namespace GDS
{

namespace DataStorage
{

Serializer::Serializer()
{

}

Serializer::~Serializer()
{
	data_.clear();
}

void Serializer::exec()
{

}

void Serializer::insert(unsigned int data_size, void *data)
{
	
}

const std::vector<unsigned char>& Serializer::get_data() const
{
	return data_;
}

Parser::Parser()
{

}

Parser::~Parser()
{

}

int Parser::exec()
{
	return 0;
}

} // namespace DataStorage

} // namespace GDS
