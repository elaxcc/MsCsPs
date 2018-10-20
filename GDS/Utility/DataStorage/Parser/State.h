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

	virtual std::vector<uint8_t>::const_iterator process(const std::vector<uint8_t> &data) = 0;

private:
	Parser *parser_;
};

class StateBegin : public IState
{
public:
	StateBegin(Parser *parser);
	virtual ~StateBegin();

	// IState
	std::vector<uint8_t>::const_iterator process(const std::vector<uint8_t> &data);
};

class StateGetType : public IState
{
public:
	StateGetType(Parser *parser);
	virtual ~StateGetType();

	// IState
	std::vector<uint8_t>::const_iterator process(const std::vector<uint8_t> &data);
};

class StateGetName : public IState
{
public:
	StateGetName(Parser *parser);
	virtual ~StateGetName();

	// IState
	std::vector<uint8_t>::const_iterator process(const std::vector<uint8_t> &data);
};

class StateGetData : public IState
{
public:
	StateGetData(Parser *parser);
	virtual ~StateGetData();

	// IState
	std::vector<uint8_t>::const_iterator process(const std::vector<uint8_t> &data);
};

class StateCompleted : public IState
{
public:
	StateCompleted(Parser *parser);
	virtual ~StateCompleted();

	// IState
	std::vector<uint8_t>::const_iterator process(const std::vector<uint8_t> &data);
};


} // namespace DataStorage

} // namespace GDS
