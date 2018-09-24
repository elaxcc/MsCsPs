#include "stdafx.h"

#include "GDS/Utility/DataStorage/SimpleData.h"
#include "GDS/Utility/DataStorage/ArrayData.h"
#include "GDS/Utility/DataStorage/ObjectData.h"

TEST(GDS_DataStorage, SimpleData)
{
	using namespace GDS::DataStorage;

	typedef unsigned int TestedType;
	typedef char NotTestedType;

	std::string name("d");
	TestedType data = 0x04030201;
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
	simple_data_2.get_data() = not_data;

	ASSERT_EQ(name, simple_data_2.get_name());
	ASSERT_EQ(sizeof(TestedType), simple_data_2.get_data_size());
	ASSERT_NE(data, simple_data_2.get_data());

	ASSERT_NE(not_name, simple_data_2.get_name());
	ASSERT_NE(sizeof(NotTestedType), simple_data_2.get_data_size());
	ASSERT_EQ(not_data, simple_data_2.get_data());

	std::vector<unsigned char> expected_serialized_data = {0x04, ':', 'd', ':', 0x01, 0x02, 0x03, 0x04};
	std::vector<unsigned char> serialized_data = simple_data_1.serialize();
	bool comparison_result = std::equal(expected_serialized_data.begin(),
		expected_serialized_data.end(), serialized_data.begin());
	ASSERT_EQ(true, comparison_result);
}

TEST(GDS_DataStorage, ArrayData)
{
	// simple data

	using namespace GDS::DataStorage;

	typedef unsigned int TestedType;
	typedef char NotTestedType;

	std::string name("array_data");
	SimpleData<TestedType> *data = new SimpleData<TestedType> [5];
	for (unsigned i = 0; i < 5; ++i)
	{
		data[i].set_data(i);
	}
	std::vector<SimpleData<TestedType>> vec_data(data, data + 5);
	
	std::string not_name("not_array_data");
	SimpleData<TestedType> *not_data = new SimpleData<TestedType> [5];
	for (unsigned i = 0; i < 5; ++i)
	{
		not_data[i].set_data(1);
	}
	std::vector<SimpleData<TestedType>> not_vec_data(not_data, not_data + 5);

	ArrayData array_data_1;
	array_data_1.set_name(name);
	array_data_1.set_data(data, 5);
	ASSERT_EQ(name, array_data_1.get_name());
	ASSERT_EQ(sizeof(TestedType), array_data_1.get_data_size());
	//ASSERT_TRUE(std::equal(array_data_1.get_data().begin(), array_data_1.get_data().end(), data));
	ASSERT_NE(not_name, array_data_1.get_name());
	ASSERT_NE(sizeof(NotTestedType), array_data_1.get_data_size());
	//ASSERT_FALSE(std::equal(array_data_1.get_data().begin(), array_data_1.get_data().end(), not_data));
	/*
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

	char data_2[] = { 0xA1, 0xA2, 0xA3 };
	ArrayData<char> *array_5 = new ArrayData<char>("a", 3, data_2);
	std::vector<unsigned char> expected_serialized_data = { 0x01, ':', 'a', '[', 0x03, 0x00, 0x00, 0x00, ']', ':', 0xA1, 0xA2, 0xA3 };
	std::vector<unsigned char> serialized_data = array_5->serialize();
	bool comparison_result = std::equal(expected_serialized_data.begin(), expected_serialized_data.end(), serialized_data.begin());
	ASSERT_EQ(true, comparison_result);

	int data_3[] = { 0xA1A1A1A1, 0xA2A2A2A2 };
	ArrayData<int> *array_6 = new ArrayData<int>("a", 2, data_3);
	expected_serialized_data = { 0x04, ':', 'a', '[', 0x02, 0x00, 0x00, 0x00, ']', ':', 0xA1, 0xA1, 0xA1, 0xA1, 0xA2, 0xA2, 0xA2, 0xA2, };
	serialized_data = array_6->serialize();
	comparison_result = std::equal(expected_serialized_data.begin(), expected_serialized_data.end(), serialized_data.begin());
	ASSERT_EQ(true, comparison_result);*/

	// Object data

	
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

	// insert element with existing name
	simple_data_1 = new SimpleData<int>(simple_data_name_1, 999);
	bool insert_result = obj_1.insert(simple_data_1);
	ASSERT_EQ(false, insert_result);

	// insert second element
	insert_result = obj_1.insert(simple_data_2);
	ASSERT_EQ(true, insert_result);

	// insert null name element
	insert_result = obj_1.insert(new SimpleData<double>());
	ASSERT_EQ(false, insert_result);

	// remove first and last elements
	obj_1.remove(*simple_data_1);
	ASSERT_EQ(false, obj_1.empty());
	obj_1.remove(*simple_data_2);
	ASSERT_EQ(true, obj_1.empty());

	// array data functionality test
	/*
	std::string array_name = "array_1";
	char array_data[] = {'a', 'b', 'c'};
	ArrayData<char> *array_obj = new ArrayData<char>(array_name, sizeof(array_data) / sizeof(char), array_data);

	ObjectData obj_2("obj_2");
	insert_result = obj_2.insert(array_obj);
	ASSERT_EQ(true, insert_result);

	ArrayData<char> *getted_array_data = obj_2.get<ArrayData<char>>(array_name);
	ASSERT_EQ(array_obj, getted_array_data);
	ASSERT_EQ(array_obj->get_size(), getted_array_data->get_size());
	ASSERT_EQ((*array_obj)[0], (*getted_array_data)[0]);
	ASSERT_EQ((*array_obj)[1], (*getted_array_data)[1]);
	ASSERT_EQ((*array_obj)[2], (*getted_array_data)[2]);*/
}

