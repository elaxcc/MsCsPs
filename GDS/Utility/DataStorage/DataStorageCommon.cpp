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

extern const std::string cObjectTypeStr = "obj";

} // namespace DataStorage

} // namespace GDS

