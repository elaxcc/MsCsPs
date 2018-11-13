#include "stdafx.h"

#include "DataStorageCommon.h"

namespace GDS
{

namespace DataStorage
{

const std::string cDataStorageVersioStr = "1.0.0";
const std::string cDataStorageHeaderStr = "GDS file storage format" + cDataStorageVersioStr;

const unsigned char cDelimiterStr = ':';
const unsigned char cOpenSquareBracketStr = '[';
const unsigned char cCloseSquareBracketStr = ']';
const unsigned char cOpenFigureBracketStr = '{';
const unsigned char cCloseFigureBracketStr = '}';

const std::string cTypeStr_Object = "obj";
const std::string cTypeStr_char = typeid(char).name();
const std::string cTypeStr_unsigned_char = typeid(unsigned char).name();
const std::string cTypeStr_short = typeid(short).name();
const std::string cTypeStr_unsigned_short = typeid(unsigned short).name();
const std::string cTypeStr_int = typeid(int).name();
const std::string cTypeStr_unsigned_int = typeid(unsigned int).name();
const std::string cTypeStr_long_long = typeid(long long).name();
const std::string cTypeStr_unsigned_long_long = typeid(unsigned long long).name();
const std::string cTypeStr_float = typeid(float).name();
const std::string cTypeStr_double = typeid(double).name();
const std::string cTypeStr_int8_t = typeid(int8_t).name();
const std::string cTypeStr_uint8_t = typeid(uint8_t).name();
const std::string cTypeStr_int16_t = typeid(int16_t).name();
const std::string cTypeStr_uint16_t = typeid(uint16_t).name();
const std::string cTypeStr_int32_t = typeid(int32_t).name();
const std::string cTypeStr_uint32_t = typeid(uint32_t).name();
const std::string cTypeStr_int64_t = typeid(int64_t).name();
const std::string cTypeStr_uint64_t = typeid(uint64_t).name();

} // namespace DataStorage

} // namespace GDS

