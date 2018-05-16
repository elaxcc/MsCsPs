#pragma once

namespace GDS
{

class ICommand
{
public:
	ICommand();
	virtual ~ICommand();

	virtual void execute() = 0;
	virtual void unExecute() = 0;
};

typedef boost::shared_ptr<ICommand> ICommandPtr;

} // namespace GDS
