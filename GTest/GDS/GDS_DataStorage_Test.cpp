#include "stdafx.h"

#include "GDS/Utility/DataStorage/SimpleData.h"
#include "GDS/Utility/DataStorage/ArrayData.h"
#include "GDS/Utility/DataStorage/ObjectData.h"

TEST(GDS_DataStorage, SimpleData)
{
	using namespace GDS::DataStorage;

	typedef unsigned int TestedType;
	typedef char NotTestedType;

	std::string name("simple_data");
	TestedType data = 12345;
	std::string not_name("not_simple_data");
	TestedType not_data = 1;
	SimpleData<TestedType> simple_data_1;
	simple_data_1.set_name(name);
	simple_data_1.set_data(data);

	ASSERT_EQ(name, simple_data_1.get_name());
	ASSERT_EQ(sizeof(TestedType), simple_data_1.get_data_size());
	ASSERT_EQ(data, simple_data_1.get_data());

	ASSERT_NE(not_name, simple_data_1.get_name());
	ASSERT_NE(sizeof(NotTestedType), simple_data_1.get_data_size());
	ASSERT_NE(not_data, simple_data_1.get_data());

	SimpleData<TestedType> simple_data_2(name, data);

	ASSERT_EQ(name, simple_data_2.get_name());
	ASSERT_EQ(sizeof(TestedType), simple_data_2.get_data_size());
	ASSERT_EQ(data, simple_data_2.get_data());

	ASSERT_NE(not_name, simple_data_2.get_name());
	ASSERT_NE(sizeof(NotTestedType), simple_data_2.get_data_size());
	ASSERT_NE(not_data, simple_data_2.get_data());
}

TEST(GDS_DataStorage, ArrayData)
{
	using namespace GDS::DataStorage;

	typedef unsigned int TestedType;
	typedef char NotTestedType;

	std::string name("array_data");
	TestedType data[5] = {1, 2, 3, 4, 5};
	std::vector<TestedType> vec_data(data, data + sizeof(data)/sizeof(TestedType));
	std::string not_name("not_array_data");
	TestedType not_data[5] = { 1, 1, 1, 1, 1 };
	std::vector<TestedType> not_vec_data(data, data + sizeof(data) / sizeof(TestedType));

	ArrayData<TestedType> array_data_1;
	array_data_1.set_name(name);
	array_data_1.set_data(sizeof(data) / sizeof(TestedType), data);
	ASSERT_EQ(name, array_data_1.get_name());
	ASSERT_EQ(sizeof(TestedType), array_data_1.get_data_size());
	ASSERT_TRUE(std::equal(array_data_1.get_data().begin(), array_data_1.get_data().end(), data));
	ASSERT_NE(not_name, array_data_1.get_name());
	ASSERT_NE(sizeof(NotTestedType), array_data_1.get_data_size());
	ASSERT_FALSE(std::equal(array_data_1.get_data().begin(), array_data_1.get_data().end(), not_data));

	ArrayData<TestedType> array_data_2;
	array_data_2.set_name(name);
	array_data_2.set_data(vec_data);
	ASSERT_TRUE(std::equal(array_data_2.get_data().begin(), array_data_2.get_data().end(), data));
	ASSERT_FALSE(std::equal(array_data_2.get_data().begin(), array_data_2.get_data().end(), not_data));

	ArrayData<TestedType> array_data_3(name, sizeof(data) / sizeof(TestedType), data);
	ASSERT_EQ(name, array_data_3.get_name());
	ASSERT_EQ(sizeof(TestedType), array_data_3.get_data_size());
	ASSERT_TRUE(std::equal(array_data_3.get_data().begin(), array_data_3.get_data().end(), data));
	ASSERT_NE(not_name, array_data_3.get_name());
	ASSERT_NE(sizeof(NotTestedType), array_data_3.get_data_size());
	ASSERT_FALSE(std::equal(array_data_3.get_data().begin(), array_data_3.get_data().end(), not_data));

	ArrayData<TestedType> array_data_4(name, vec_data);
	ASSERT_TRUE(std::equal(array_data_4.get_data().begin(), array_data_4.get_data().end(), data));
	ASSERT_FALSE(std::equal(array_data_4.get_data().begin(), array_data_4.get_data().end(), not_data));
}

TEST(GDS_DataStorage, ObjectData)
{
	using namespace GDS::DataStorage;

	// simple data functionality test

	std::string simple_data_name_1 = "simple_data_1";
	int simple_data_val_1 = 12345;
	SimpleData<int> *simple_data_1 = new SimpleData<int>(simple_data_name_1, simple_data_val_1);

	std::string simple_data_name_2 = "simple_data_2";
	char simple_data_val_2 = 'D';
	SimpleData<char> *simple_data_2 = new SimpleData<char>(simple_data_name_2, simple_data_val_2);

	ObjectData obj_1;
	obj_1.insert(simple_data_1);
	
	SimpleData<int>* getted_simple_data = obj_1.get<SimpleData<int>>(simple_data_name_1);
	ASSERT_EQ(simple_data_name_1, getted_simple_data->get_name());
	ASSERT_EQ(simple_data_val_1, getted_simple_data->get_data());

	simple_data_1 = new SimpleData<int>(simple_data_name_1, simple_data_val_1);
	bool insert_result = obj_1.insert(new SimpleData<char>());
	ASSERT_EQ(true, insert_result);

	insert_result = obj_1.insert(simple_data_2);
	ASSERT_EQ(true, insert_result);

	obj_1.remove(*simple_data_1);
	obj_1.remove(*simple_data_2);
	ASSERT_EQ(false, obj_1.empty());
}

