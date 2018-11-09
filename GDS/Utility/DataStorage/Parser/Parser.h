#pragma once

#include "../DataStorageCommon.h"
#include "../IDataStorageObject.h"
#include "State.h"

namespace GDS
{

namespace DataStorage
{

class Parser
{
public:
	enum Error
	{
		ErrorOk,
		ErrorNoEnoughData,
		ErrorWronDelimeterAfterType,
		ErrorArrayAbsentOpeningSquaredBracket,
		ErrorArrayAbsentClosingSquaredBracket,
		ErrorArrayBytesBetweenBracketsWrong,
		ErrorNameWrongFirstSymbol
	};


	Parser();
	Parser(const std::vector<uint8_t>& data);
	~Parser();

	int exec(const std::vector<uint8_t>& binary_data);
	void reset();
	void clean();
	const std::list<IDataStorageObjectPtr>& get_data() const;

	void set_state(const IStatePtr &state);
	IStatePtr Parser::get_state();

	void set_error(Error error);
	Error get_error() const;

	void set_data_type(const std::string &obj_type);
	const std::string& get_data_type() const;

	void set_data_name(const std::string &data_name);
	std::string get_data_name() const;

	void set_obj_array_type(unsigned int array_size);
	bool obj_is_array();
	unsigned int  get_array_size();

private:
	std::list<IDataStorageObjectPtr> data_;

	IStatePtr current_state_;
	std::string current_data_type_;
	std::string current_data_name_;
	bool current_data_is_array_;
	unsigned int current_data_array_size_;

	Error error_;
};

} // namespace DataStorage

} // namespace GDS
