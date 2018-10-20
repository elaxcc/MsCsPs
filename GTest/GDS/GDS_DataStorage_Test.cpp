#include "stdafx.h"

#include "GDS/Utility/DataStorage/SimpleData.h"
#include "GDS/Utility/DataStorage/ArrayData.h"
#include "GDS/Utility/DataStorage/ObjectData.h"
#include "GDS/Utility/DataStorage/Parser/Parser.h"

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

	// check operator=
	SimpleData<int> simple_1("a", 1);
	SimpleData<int> simple_2("b", 2);

	simple_1 = 10;
	ASSERT_EQ(10, simple_1.get_data());

	simple_1 = simple_2;
	ASSERT_EQ(simple_2.get_name(), simple_1.get_name());
	ASSERT_EQ(simple_2.get_data(), simple_1.get_data());

	IDataStorageObjectPtr iptr = simple_1.clone();
	SimpleData<int> *ptr = static_cast<SimpleData<int>*>(iptr.get());
	ptr->set_name("new name");
	ASSERT_NE(ptr->get_name(), simple_1.get_name());
	ASSERT_EQ(ptr->get_data(), simple_1.get_data());
}

TEST(GDS_DataStorage, ArrayData)
{
	// simple data
	
	using namespace GDS::DataStorage;

	typedef unsigned int TestedType;
	typedef char NotTestedType;

	std::string name("array_data");
	SimpleData<TestedType> data[5];
	for (unsigned i = 0; i < 5; ++i)
	{
		data[i].set_data(i + 1);
	}
	std::vector<SimpleData<TestedType>> vec_data(data, data + 5);
	
	std::string not_name("not_array_data");
	SimpleData<TestedType> not_data[5];
	for (unsigned i = 0; i < 5; ++i)
	{
		not_data[i].set_data(1);
	}
	std::vector<SimpleData<TestedType>> not_vec_data(not_data, not_data + 5);
	
	ArrayData<SimpleData<TestedType>> array_data_1(5);
	array_data_1.set_name(name);
	array_data_1.set_data(data, 5);
	ASSERT_EQ(name, array_data_1.get_name());
	ASSERT_EQ(sizeof(TestedType), array_data_1.get_data_size());
	bool result = false;
	for (unsigned i = 0; i < array_data_1.get_size(); ++i)
	{
		result = array_data_1[i].get_data() == data[i].get_data();
	}
	ASSERT_TRUE(result);
	ASSERT_NE(not_name, array_data_1.get_name());
	ASSERT_NE(sizeof(NotTestedType), array_data_1.get_data_size());
	for (unsigned i = 0; i < array_data_1.get_size(); ++i)
	{
		result = array_data_1[i].get_data() == not_data[i].get_data();
	}
	ASSERT_FALSE(result);
	
	ArrayData<SimpleData<TestedType>> array_data_2(vec_data.size());
	array_data_2.set_name(name);
	array_data_2.set_data(vec_data);
	for (unsigned i = 0; i < array_data_2.get_size(); ++i)
	{
		result = array_data_2[i].get_data() == data[i].get_data();
	}
	ASSERT_TRUE(result);
	for (unsigned i = 0; i < array_data_2.get_size(); ++i)
	{
		result = array_data_2[i].get_data() == not_data[i].get_data();
	}
	ASSERT_FALSE(result);
	
	ArrayData<SimpleData<TestedType>> array_data_3(name, data, 5);
	ASSERT_EQ(name, array_data_3.get_name());
	ASSERT_EQ(sizeof(TestedType), array_data_3.get_data_size());
	for (unsigned i = 0; i < array_data_3.get_size(); ++i)
	{
		result = array_data_3[i].get_data() == data[i].get_data();
	}
	ASSERT_TRUE(result);
	ASSERT_NE(not_name, array_data_3.get_name());
	ASSERT_NE(sizeof(NotTestedType), array_data_3.get_data_size());
	for (unsigned i = 0; i < array_data_3.get_size(); ++i)
	{
		result = array_data_3[i].get_data() == not_data[i].get_data();
	}
	ASSERT_FALSE(result);
	
	ArrayData<SimpleData<TestedType>> array_data_4(name, vec_data);
	for (unsigned i = 0; i < array_data_4.get_size(); ++i)
	{
		result = array_data_4[i].get_data() == data[i].get_data();
	}
	ASSERT_TRUE(result);
	for (unsigned i = 0; i < array_data_4.get_size(); ++i)
	{
		result = array_data_4[i].get_data() == not_data[i].get_data();
	}
	ASSERT_FALSE(result);
	
	SimpleData<char> data_2[3];
	data_2[0].set_data(0xA1);
	data_2[1].set_data(0xA2);
	data_2[2].set_data(0xA3);
	ArrayData<SimpleData<char>> array_5("a",data_2, 3);
	std::vector<unsigned char> expected_serialized_data = { 0x01, ':', 'a', '[', 0x03, 0x00, 0x00, 0x00, ']', ':', 0xA1, 0xA2, 0xA3 };
	std::vector<unsigned char> serialized_data = array_5.serialize();
	bool comparison_result = std::equal(expected_serialized_data.begin(), expected_serialized_data.end(), serialized_data.begin());
	ASSERT_EQ(true, comparison_result);
	
	SimpleData<int> data_3[2];
	data_3[0] = 0xA1A1A1A1;
	data_3[1] = 0xA2A2A2A2;
	ArrayData<SimpleData<int>> array_6("a", data_3, 2);
	expected_serialized_data = { 0x04, ':', 'a', '[', 0x02, 0x00, 0x00, 0x00, ']', ':', 0xA1, 0xA1, 0xA1, 0xA1, 0xA2, 0xA2, 0xA2, 0xA2, };
	serialized_data = array_6.serialize();
	comparison_result = std::equal(expected_serialized_data.begin(), expected_serialized_data.end(), serialized_data.begin());
	ASSERT_EQ(true, comparison_result);
	
	// Object data	
	ObjectData obj[3];
	obj[0].insert<SimpleData<char>>(SimpleData<char>("s1", 'a'));
	obj[1].insert<SimpleData<char>>(SimpleData<char>("s2", 'b'));
	obj[2].insert<SimpleData<char>>(SimpleData<char>("s3", 'c'));
	ArrayData<ObjectData> obj_arr("obj_arr", obj, 3);
	serialized_data = obj_arr.serialize();

	std::vector<unsigned char> expected_arr_str =
		{ 0x00, ':', 'o', 'b', 'j', '_', 'a', 'r', 'r', '[', 0x03, 0x00, 0x00, 0x00, ']', ':'
		, '{'
		, 0x01, ':', 's', '1', ':', 'a'
		, '}'
		, '{'
		, 0x01, ':', 's', '2', ':', 'b'
		, '}'
		, '{'
		, 0x01, ':', 's', '3', ':', 'c'
		, '}' };
	comparison_result = std::equal(expected_arr_str.begin(), expected_arr_str.end(), serialized_data.begin());
	ASSERT_EQ(true, comparison_result);
}

TEST(GDS_DataStorage, ObjectData)
{
	using namespace GDS::DataStorage;

	// simple data functionality test
	
	std::string simple_data_name_1 = "simple_data_1";
	int simple_data_val_1 = 12345;
	SimpleData<int> simple_data_1(simple_data_name_1, simple_data_val_1);

	std::string simple_data_name_2 = "simple_data_2";
	char simple_data_val_2 = 'D';
	SimpleData<char> simple_data_2(simple_data_name_2, simple_data_val_2);

	ObjectData obj_1;
	obj_1.insert<SimpleData<int>>(simple_data_1);
	
	SimpleData<int> *getted_simple_data = obj_1.get<SimpleData<int>>(simple_data_name_1);
	ASSERT_EQ(simple_data_name_1, getted_simple_data->get_name());
	ASSERT_EQ(simple_data_val_1, getted_simple_data->get_data());
	
	// insert element with existing name
	simple_data_1.set_data(999);
	bool insert_result = obj_1.insert(simple_data_1);
	ASSERT_EQ(false, insert_result);
	
	// insert second element
	insert_result = obj_1.insert(simple_data_2);
	ASSERT_EQ(true, insert_result);
	
	// insert null name element
	SimpleData<double> empty_ddata;
	insert_result = obj_1.insert(empty_ddata);
	ASSERT_EQ(false, insert_result);
	
	// remove first and last elements
	obj_1.remove(simple_data_1);
	ASSERT_EQ(false, obj_1.empty());
	obj_1.remove(simple_data_2);
	ASSERT_EQ(true, obj_1.empty());

	// array data functionality test
	
	std::string array_name = "array_1";
	SimpleData<char> array_data[3];
	array_data[0] = 'a';
	array_data[1] = 'b';
	array_data[2] = 'c';
	ArrayData<SimpleData<char>> array_obj(array_name, array_data, 3);
	
	ObjectData obj_2("obj_2");
	insert_result = obj_2.insert(array_obj);
	ASSERT_EQ(true, insert_result);
	
	ArrayData<SimpleData<char>> *getted_array_data = obj_2.get<ArrayData<SimpleData<char>>>(array_name);
	ASSERT_EQ(array_obj.get_size(), getted_array_data->get_size());
	ASSERT_EQ(array_obj[0].get_data(), (*getted_array_data)[0].get_data());
	ASSERT_EQ(array_obj[1].get_data(), (*getted_array_data)[1].get_data());
	ASSERT_EQ(array_obj[2].get_data(), (*getted_array_data)[2].get_data());
	
	obj_2.erase();
	ASSERT_EQ(true, obj_2.empty());

	SimpleData<char> simp_char(std::string("smpl"), 'D');
	obj_2.insert(simp_char);
	SimpleData<char> arr_data[1];
	arr_data[0] = 'a';
	ArrayData<SimpleData<char>> arr_char("arr", arr_data, 1);
	obj_2.insert(arr_char);

	std::vector<unsigned char> expected_serialized_data = 
		{ 0x00, ':', 'o', 'b', 'j', '_', '2', 
		'{', 
			0x01, ':', 'a', 'r', 'r', '[', 0x01, 0x00, 0x00, 0x00, ']', ':', 'a',
			0x01, ':', 's', 'm', 'p', 'l', ':', 'D',
		'}' };
	std::vector<unsigned char> serialized_data = obj_2.serialize();
	bool comparison_result = std::equal(expected_serialized_data.begin(),
		expected_serialized_data.end(), serialized_data.begin());
	ASSERT_EQ(true, comparison_result);

	// clone
	IDataStorageObjectPtr iptr = obj_2.clone();
	std::vector<unsigned char> iptr_serialized_data = iptr->serialize();
	comparison_result = std::equal(expected_serialized_data.begin(),
		expected_serialized_data.end(), iptr_serialized_data.begin());
	ASSERT_EQ(true, comparison_result);

	// check operator[]
	
	IDataStorageObjectPtr simple_ptr = obj_2["arr"];
	ASSERT_EQ(arr_char.get_name(), simple_ptr->get_name());
}

TEST(GDS_DataStorage, Parser)
{
	using namespace GDS::DataStorage;

	ObjectData obj("obj_2");
	SimpleData<char> simp_char(std::string("smpl"), 'D');
	obj.insert(simp_char);
	SimpleData<char> arr_data[1];
	arr_data[0] = 'a';
	ArrayData<SimpleData<char>> arr_char("arr", arr_data, 1);
	obj.insert(arr_char);
	std::vector<uint8_t> serial_data = obj.serialize();

	Parser parser(serial_data);
}
