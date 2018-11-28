#include "stdafx.h"

#include "FileParser.h"

namespace GDS
{
namespace
{

const unsigned int cBufferSize = 1000;

} // namespace

namespace DataStorage
{

FileParser::FileParser()
{

}

FileParser::~FileParser()
{
	clean_parse_data();
}

bool FileParser::write(const std::string& file_name, const std::vector<uint8_t> &data)
{
	std::fstream file;
	file.open(file_name, std::fstream::out | std::fstream::binary);
	if (!file.is_open())
	{
		return false;
	}

	file.write((char *) data.data(), data.size());
	file.close();

	return true;
}

bool FileParser::read(const std::string &file_name)
{
	std::fstream file;
	file.open(file_name, std::fstream::binary | std::fstream::in);

	if (!file.is_open())
	{
		return false;
	}
	
	// get file size
	file.seekg(0, std::fstream::end);
	uint64_t file_size = file.tellg();
	// return to begining of file
	file.seekg(0, std::fstream::beg);
	// read and parse file
	for (uint64_t pos = 0; pos < file_size; )
	{
		// allocate buffer for data
		std::vector<uint8_t> vec_data;
		if (file_size - pos > cBufferSize)
		{
			vec_data.resize(cBufferSize);
		}
		else
		{
			vec_data.resize(file_size - pos);
		}

		file.read((char *) vec_data.data(), vec_data.size());
		pos += vec_data.size();

		parser_.exec(vec_data);
	}

	file.close();

	if (parser_.get_state()->get_id() == IState::State_Complete
		&& parser_.get_error() == Parser::ErrorOk)
	{
		return true;
	}

	return false;
}

bool FileParser::is_parse_complete()
{
	return parser_.get_state()->get_id() == IState::State_Complete
		&& parser_.get_error() == Parser::ErrorOk;
}

void FileParser::clean_parse_data()
{
	parser_.clean();
}

std::list<IDataStorageObjectPtr>& FileParser::get_parsed_data()
{
	return parser_.get_data();
}

} // namespace DataStorage

} // namespace GDS
