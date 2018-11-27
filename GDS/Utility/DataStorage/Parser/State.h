#pragma once

#include "../IDataStorageObject.h"

namespace GDS
{

namespace DataStorage
{

class Parser;

class IState
{
public:
	IState(Parser *parser);
	virtual ~IState();

	Parser* get_parser();

	virtual std::vector<uint8_t>::const_iterator process(
		const std::vector<uint8_t> &binary_data,
		std::vector<uint8_t>::const_iterator &pos) = 0;

protected:
	Parser *parser_;
};
typedef std::shared_ptr<IState> IStatePtr;

class StateGetDataLength : public IState
{
public:
	StateGetDataLength(Parser *parser);
	virtual ~StateGetDataLength();

	// IState
	std::vector<uint8_t>::const_iterator process(
		const std::vector<uint8_t> &binary_data,
		std::vector<uint8_t>::const_iterator &pos);
};

class StateGetName : public IState
{
public:
	StateGetName(Parser *parser);
	virtual ~StateGetName();

	// IState
	std::vector<uint8_t>::const_iterator process(
		const std::vector<uint8_t> &binary_data,
		std::vector<uint8_t>::const_iterator &pos);

private:
	bool check_name(const std::vector<uint8_t> &name);
	bool check_name_for_array(const std::vector<uint8_t> &name);

	std::vector<uint8_t> data_name_only_;
	bool is_array_;
	unsigned int array_size_;
};

class StateGetData : public IState
{
public:
	StateGetData(Parser *parser);
	virtual ~StateGetData();

	// IState
	std::vector<uint8_t>::const_iterator process(
		const std::vector<uint8_t> &binary_data,
		std::vector<uint8_t>::const_iterator &pos);
private:
	unsigned int cnt_;
	uint8_t current_elem_num_;
	std::vector<IDataStorageObjectPtr> vec_data_;
};

} // namespace DataStorage

} // namespace GDS
