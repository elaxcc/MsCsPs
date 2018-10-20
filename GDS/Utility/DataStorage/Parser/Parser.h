#pragma once

#include "../DataStorageCommon.h"
#include "../IDataStorageObject.h"

namespace GDS
{

namespace DataStorage
{

class Parser
{
public:
	Parser();
	Parser(const std::vector<uint8_t>& data);
	~Parser();

	int exec(const std::vector<uint8_t>& data);
	void clean();
	const std::list<IDataStorageObjectPtr>& get_data() const;

private:
	enum State
	{
		State_Empty,
		State_GotType,
		State_GotName,
		State_GotData
	};

	std::list<IDataStorageObjectPtr> data_;

	State current_state_;
	IDataStorageObject::Type current_obj_type_;
};

} // namespace DataStorage

} // namespace GDS
