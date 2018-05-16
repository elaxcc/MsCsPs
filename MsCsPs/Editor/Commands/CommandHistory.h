#pragma once

#include "ICommand.h"

namespace GDS
{

class CommandHistory
{
public:
	CommandHistory();
	~CommandHistory();

	void insert(const ICommandPtr cmd_ptr);
	void execute();
	void cancel();

private:
	std::list<ICommandPtr> cmd_executed_list_;
	std::list<ICommandPtr> cmd_canceled_list_;
};

} // namespace GDS
