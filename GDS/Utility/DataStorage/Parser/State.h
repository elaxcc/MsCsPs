#pragma once

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

class StateGetType : public IState
{
public:
	StateGetType(Parser *parser);
	virtual ~StateGetType();

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

class StateBegining : public IState
{
public:
	StateBegining(Parser *parser);
	virtual ~StateBegining();

	// IState
	std::vector<uint8_t>::const_iterator process(
		const std::vector<uint8_t> &binary_data,
		std::vector<uint8_t>::const_iterator &pos);
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
};

class StateComplete : public IState
{
public:
	StateComplete(Parser *parser);
	virtual ~StateComplete();

	// IState
	std::vector<uint8_t>::const_iterator process(
		const std::vector<uint8_t> &binary_data,
		std::vector<uint8_t>::const_iterator &pos);
};


} // namespace DataStorage

} // namespace GDS
