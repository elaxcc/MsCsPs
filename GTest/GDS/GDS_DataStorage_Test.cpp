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
	SimpleData simple_data_1;
	simple_data_1.set_name(name);
	simple_data_1.set_data<TestedType>(data);
	
	ASSERT_EQ(name, simple_data_1.get_name());
	ASSERT_EQ(sizeof(TestedType), simple_data_1.get_data_size());
	ASSERT_EQ(data, simple_data_1.get_data<TestedType>());

	ASSERT_NE(not_name, simple_data_1.get_name());
	ASSERT_NE(sizeof(NotTestedType), simple_data_1.get_data_size());
	ASSERT_NE(not_data, simple_data_1.get_data<TestedType>());
	
	SimpleData simple_data_2(name, (void *) &data, sizeof(TestedType));
	simple_data_2.get_data<TestedType>() = not_data;

	ASSERT_EQ(name, simple_data_2.get_name());
	ASSERT_EQ(sizeof(TestedType), simple_data_2.get_data_size());
	ASSERT_NE(data, simple_data_2.get_data<TestedType>());

	ASSERT_NE(not_name, simple_data_2.get_name());
	ASSERT_NE(sizeof(NotTestedType), simple_data_2.get_data_size());
	ASSERT_EQ(not_data, simple_data_2.get_data<TestedType>());
	
	std::vector<uint8_t> expected_serialized_data =
		{
			0x04,
			':',
			'd',
			':',
			0x01, 0x02, 0x03, 0x04
		};
	std::vector<uint8_t> serialized_data = simple_data_1.serialize();
	bool comparison_result = std::equal(expected_serialized_data.begin(),
		expected_serialized_data.end(), serialized_data.begin());
	ASSERT_EQ(true, comparison_result);
	
	// check operator=
	SimpleData simple_1;
	SimpleData simple_2;
	simple_1.set_name("a");
	simple_1.set_data(1);
	simple_2.set_name("b");
	simple_2.set_data(2);

	simple_1 = 10;

	ASSERT_EQ(10, simple_1.get_data<int>());

	simple_1 = simple_2;
	ASSERT_EQ(simple_2.get_name(), simple_1.get_name());
	ASSERT_EQ(simple_2.get_data<int>(), simple_1.get_data<int>());
	
	IDataStorageObjectPtr iptr = simple_1.clone();
	SimpleData *ptr = static_cast<SimpleData*>(iptr.get());
	ptr->set_name("new name");
	ASSERT_NE(ptr->get_name(), simple_1.get_name());
	ASSERT_EQ(ptr->get_data<int>(), simple_1.get_data<int>());
	
}

TEST(GDS_DataStorage, ArrayData)
{
	// simple data
	
	using namespace GDS::DataStorage;

	typedef unsigned int TestedType;
	typedef char NotTestedType;

	std::string name("array_data");
	SimpleData data[5];
	std::vector<IDataStorageObjectPtr> vec_data;
	for (unsigned i = 0; i < 5; ++i)
	{
		data[i].set_data(i + 1);
		vec_data.push_back(data[i].clone());
	}
	
	std::string not_name("not_array_data");
	SimpleData not_data[5];
	std::vector<IDataStorageObjectPtr> not_vec_data;
	for (unsigned i = 0; i < 5; ++i)
	{
		not_data[i].set_data(1);
		not_vec_data.push_back(not_data[i].clone());
	}
	
	ArrayData array_data_1(name, 5);
	array_data_1.set_data(data, 5);
	ASSERT_EQ(name, array_data_1.get_name());
	ASSERT_EQ(sizeof(TestedType), array_data_1.get_data_size());
	bool result = false;
	for (unsigned i = 0; i < array_data_1.get_size(); ++i)
	{
		result = array_data_1[i]->to<SimpleData>()->get_data<TestedType>() == data[i].get_data<TestedType>();
	}
	ASSERT_TRUE(result);
	ASSERT_NE(not_name, array_data_1.get_name());
	ASSERT_NE(sizeof(NotTestedType), array_data_1.get_data_size());
	for (unsigned i = 0; i < array_data_1.get_size(); ++i)
	{
		result = array_data_1[i]->to<SimpleData>()->get_data<TestedType>() == not_data[i].get_data<TestedType>();
	}
	ASSERT_FALSE(result);
	
	ArrayData array_data_2(name, vec_data.size());
	array_data_2.set_data(vec_data);
	for (unsigned i = 0; i < array_data_2.get_size(); ++i)
	{
		result = array_data_2[i]->to<SimpleData>()->get_data<TestedType>() == data[i].get_data<TestedType>();
	}
	ASSERT_TRUE(result);
	for (unsigned i = 0; i < array_data_2.get_size(); ++i)
	{
		result = array_data_2[i]->to<SimpleData>()->get_data<TestedType>() == not_data[i].get_data<TestedType>();
	}
	ASSERT_FALSE(result);
	
	IDataStorageObjectPtr idata[5];
	for (unsigned i = 0; i < 5; ++i)
	{
		idata[i] = data[i].clone();
	}
	ArrayData array_data_3(name, idata, 5);
	ASSERT_EQ(name, array_data_3.get_name());
	ASSERT_EQ(sizeof(TestedType), array_data_3.get_data_size());
	for (unsigned i = 0; i < array_data_3.get_size(); ++i)
	{
		result = array_data_3[i]->to<SimpleData>()->get_data<TestedType>() == idata[i]->to<SimpleData>()->get_data<TestedType>();
	}
	ASSERT_TRUE(result);
	ASSERT_NE(not_name, array_data_3.get_name());
	ASSERT_NE(sizeof(NotTestedType), array_data_3.get_data_size());
	for (unsigned i = 0; i < array_data_3.get_size(); ++i)
	{
		result = array_data_3[i]->to<SimpleData>()->get_data<TestedType>() == not_data[i].get_data<TestedType>();
	}
	ASSERT_FALSE(result);
	
	ArrayData array_data_4(name, vec_data);
	for (unsigned i = 0; i < array_data_4.get_size(); ++i)
	{
		result = array_data_4[i]->to<SimpleData>()->get_data<TestedType>() == data[i].get_data<TestedType>();
	}
	ASSERT_TRUE(result);
	for (unsigned i = 0; i < array_data_4.get_size(); ++i)
	{
		result = array_data_4[i]->to<SimpleData>()->get_data<TestedType>() == not_data[i].get_data<TestedType>();
	}
	ASSERT_FALSE(result);
	
	SimpleData simpl_arr_data[3];
	simpl_arr_data[0].set_data<uint8_t>(0xA1);
	simpl_arr_data[1].set_data<uint8_t>(0xA2);
	simpl_arr_data[2].set_data<uint8_t>(0xA3);
	ArrayData array_5("a", 3);
	array_5.set_data(simpl_arr_data, 3);
	std::vector<unsigned char> expected_serialized_data =
		{
			0x01,
			':',
			'a', '[', 0x03, 0x00, 0x00, 0x00, ']',
			':',
			0xA1, 0xA2, 0xA3
		};
	std::vector<unsigned char> serialized_data = array_5.serialize();
	bool comparison_result = std::equal(expected_serialized_data.begin(), expected_serialized_data.end(), serialized_data.begin());
	ASSERT_EQ(true, comparison_result);
	
	SimpleData s_d[2];
	s_d[0].set_data(0xA1A1A1A1);
	s_d[1].set_data(0xA2A2A2A2);
	ArrayData array_6("a", 2);
	array_6.set_data(s_d, 2);

	expected_serialized_data =
		{
			0x04,
			':',
			'a', '[', 0x02, 0x00, 0x00, 0x00, ']',
			':',
			0xA1, 0xA1, 0xA1, 0xA1, 0xA2, 0xA2, 0xA2, 0xA2,
		};
	serialized_data = array_6.serialize();
	comparison_result = std::equal(expected_serialized_data.begin(), expected_serialized_data.end(), serialized_data.begin());
	ASSERT_EQ(true, comparison_result);
	
	// Object data
	SimpleData simple_obj_data[3];
	simple_obj_data[0].set_name("s1"); simple_obj_data[0].set_data('a');
	simple_obj_data[1].set_name("s2"); simple_obj_data[1].set_data('b');
	simple_obj_data[2].set_name("s3"); simple_obj_data[2].set_data('c');
	ObjectData obj[3];
	obj[0].insert<SimpleData>(simple_obj_data[0]);
	obj[1].insert<SimpleData>(simple_obj_data[1]);
	obj[2].insert<SimpleData>(simple_obj_data[2]);
	ArrayData obj_arr("obj_arr", 3);
	obj_arr[0] = obj[0].clone();
	obj_arr[1] = obj[1].clone();
	obj_arr[2] = obj[2].clone();
	serialized_data = obj_arr.serialize();

	std::vector<unsigned char> expected_arr_str =
		{
			0x00,
			':',
			'o', 'b', 'j', '_', 'a', 'r', 'r', '[', 0x03, 0x00, 0x00, 0x00, ']',
			':',
			'{',
				0x01, ':', 's', '1', ':', 'a',
			'}',
			'{',
				0x01, ':', 's', '2', ':', 'b',
			'}',
			'{',
				0x01, ':', 's', '3', ':', 'c',
			'}'
		};
	comparison_result = std::equal(expected_arr_str.begin(), expected_arr_str.end(), serialized_data.begin());
	ASSERT_EQ(true, comparison_result);
}

TEST(GDS_DataStorage, ObjectData)
{
	
	using namespace GDS::DataStorage;

	// simple data functionality test
	
	std::string simple_data_name_1 = "simple_data_1";
	int simple_data_val_1 = 12345;
	SimpleData simple_data_1(simple_data_name_1, (void *) &simple_data_val_1, sizeof(int));

	std::string simple_data_name_2 = "simple_data_2";
	char simple_data_val_2 = 'D';
	SimpleData simple_data_2(simple_data_name_2, (void *) &simple_data_val_2, sizeof(char));

	ObjectData obj_1;
	obj_1.insert<SimpleData>(simple_data_1);
	
	SimpleData *getted_simple_data = obj_1.get<SimpleData>(simple_data_name_1);
	ASSERT_EQ(simple_data_name_1, getted_simple_data->get_name());
	ASSERT_EQ(simple_data_val_1, getted_simple_data->get_data<int>());
	
	// insert element with existing name
	simple_data_1.set_data(999);
	bool insert_result = obj_1.insert(simple_data_1);
	ASSERT_EQ(false, insert_result);
	
	// insert second element
	insert_result = obj_1.insert(simple_data_2);
	ASSERT_EQ(true, insert_result);
	
	// insert null name element
	SimpleData empty_ddata;
	insert_result = obj_1.insert(empty_ddata);
	ASSERT_EQ(false, insert_result);
	
	// remove first and last elements
	obj_1.remove(simple_data_1);
	ASSERT_EQ(false, obj_1.empty());
	obj_1.remove(simple_data_2);
	ASSERT_EQ(true, obj_1.empty());
	
	// array data functionality test
	
	std::string array_name = "array_1";
	SimpleData array_data[3];
	array_data[0] = 'a';
	array_data[1] = 'b';
	array_data[2] = 'c';
	IDataStorageObjectPtr array_data_ptr[3];
	array_data_ptr[0] = array_data[0].clone();
	array_data_ptr[1] = array_data[1].clone();
	array_data_ptr[2] = array_data[2].clone();
	ArrayData array_obj(array_name, array_data_ptr, 3);
	
	ObjectData obj_2("obj_2");
	insert_result = obj_2.insert(array_obj);
	ASSERT_EQ(true, insert_result);
	
	ArrayData *getted_array_data = obj_2.get<ArrayData>(array_name);
	ASSERT_EQ(array_obj.get_size(), getted_array_data->get_size());
	ASSERT_EQ(array_obj[0]->to<SimpleData>()->get_data<char>(), (*getted_array_data)[0]->to<SimpleData>()->get_data<char>());
	ASSERT_EQ(array_obj[1]->to<SimpleData>()->get_data<char>(), (*getted_array_data)[1]->to<SimpleData>()->get_data<char>());
	ASSERT_EQ(array_obj[2]->to<SimpleData>()->get_data<char>(), (*getted_array_data)[2]->to<SimpleData>()->get_data<char>());
	
	obj_2.erase();
	ASSERT_EQ(true, obj_2.empty());
	
	
	SimpleData simp_char(std::string("smpl"), 'D');
	obj_2.insert(simp_char);
	SimpleData arr_data[1];
	arr_data[0] = 'a'; 
	ArrayData arr_char("arr", 1);
	arr_char.set_data(arr_data, 1);
	obj_2.insert(arr_char);

	std::vector<unsigned char> expected_serialized_data = 
		{
			0x00,
			':',
			'o', 'b', 'j', '_', '2',
			':',
			'{',
				0x01,
				':',
				'a', 'r', 'r', '[', 0x01, 0x00, 0x00, 0x00, ']',
				':',
				'a',
				0x01,
				':',
				's', 'm', 'p', 'l',
				':',
				'D',
			'}'
		};
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
	/*using namespace GDS::DataStorage;

	ObjectData obj("obj_2");

	SimpleData<char> simp_char(std::string("smpl"), 'D');
	obj.insert(simp_char);

	SimpleData<char> arr_data[1];
	arr_data[0] = 'Q';
	ArrayData<SimpleData<char>> arr_char("arr", arr_data, 1);
	obj.insert(arr_char);

	std::vector<uint8_t> serial_data = obj.serialize();

	Parser parser(simp_char.serialize());*/
}
