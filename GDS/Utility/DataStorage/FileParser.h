#pragma once

#include "IDataStorageObject.h"
#include "Parser/Parser.h"

namespace GDS
{

namespace DataStorage
{

class FileParser
{
public:
	FileParser();
	~FileParser();

	bool write(const std::string& file_name, const std::vector<uint8_t> &data);

	bool read(const std::string &file_name);
	bool is_parse_complete();
	void clean_parse_data();
	std::list<IDataStorageObjectPtr>& get_parsed_data();

private:
	Parser parser_;
};

} // namespace DataStorage

} // namespace GDS

