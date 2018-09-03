#include "stdafx.h"

#include "DataStorageCommon.h"

namespace GDS
{

namespace DataStorage
{

const std::string cDataStorageVersioStr = "1.0.0";
const std::string cDataStorageHeaderStr = "GDS file storage format" + cDataStorageVersioStr;

const unsigned char cDelimiterStr = ':';
const unsigned char cFirstBracketStr = '[';
const unsigned char cLastBracketStr = ']';

} // namespace DataStorage

} // namespace GDS

