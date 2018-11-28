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
	enum State
	{
		State_GetDataLength,
		State_GetName,
		State_GetData,
		State_Complete
	};

	IState(Parser *parser);
	virtual ~IState();

	Parser* get_parser();

	virtual std::vector<uint8_t>::const_iterator process(
		const std::vector<uint8_t> &binary_data,
		std::vector<uint8_t>::const_iterator &pos) = 0;
	virtual State get_id() = 0;

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
	virtual std::vector<uint8_t>::const_iterator process(
		const std::vector<uint8_t> &binary_data,
		std::vector<uint8_t>::const_iterator &pos);
	virtual IState::State get_id();
};

class StateGetName : public IState
{
public:
	StateGetName(Parser *parser);
	virtual ~StateGetName();

	// IState
	virtual std::vector<uint8_t>::const_iterator process(
		const std::vector<uint8_t> &binary_data,
		std::vector<uint8_t>::const_iterator &pos);
	virtual IState::State get_id();

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
	virtual std::vector<uint8_t>::const_iterator process(
		const std::vector<uint8_t> &binary_data,
		std::vector<uint8_t>::const_iterator &pos);
	virtual IState::State get_id();
private:
	unsigned int cnt_;
	uint8_t current_elem_num_;
	std::vector<IDataStorageObjectPtr> vec_data_;
};

class StateComplete : public IState
{
public:
	StateComplete(Parser *parser);
	virtual ~StateComplete();

	// IState
	virtual std::vector<uint8_t>::const_iterator process(
		const std::vector<uint8_t> &binary_data,
		std::vector<uint8_t>::const_iterator &pos);
	virtual IState::State get_id();
};

} // namespace DataStorage

} // namespace GDS
