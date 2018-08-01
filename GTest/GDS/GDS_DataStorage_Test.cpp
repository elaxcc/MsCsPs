#include "stdafx.h"

#include "MsCsPs/Utility/DataStorage/DataStorage.h"

TEST(GDS_DataStorage, Serializer)
{
	GDS::DataStorage::Serializer serializer;

	unsigned val = 0x01020304;
	serializer.insert(sizeof(unsigned), &val);
}
