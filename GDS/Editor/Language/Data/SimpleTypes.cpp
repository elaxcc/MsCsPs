#include "stdafx.h"

#include "SimpleTypes.h"

namespace GDS
{

namespace Editor
{

SimpleType::SimpleType(Type type)
	: type_(type)
{

}

SimpleType::~SimpleType()
{

}

SimpleType::Type SimpleType::getType() const
{
	return type_;
}

CharType::CharType()
	: SimpleType(SimpleType::charType)
{

}

CharType::~CharType()
{

}

int CharType::getSize()
{
	return sizeof(CharType::type);
}

UCharType::UCharType()
	: SimpleType(SimpleType::ucharType)
{

}

UCharType::~UCharType()
{

}

int UCharType::getSize()
{
	return sizeof(UCharType::type);
}

ShortType::ShortType()
	: SimpleType(SimpleType::shortType)
{

}

ShortType::~ShortType()
{

}

int ShortType::getSize()
{
	return sizeof(ShortType::type);
}

UShortType::UShortType()
	: SimpleType(SimpleType::ushortType)
{

}

UShortType::~UShortType()
{

}

int UShortType::getSize()
{
	return sizeof(UShortType::type);
}

IntType::IntType()
	: SimpleType(SimpleType::intType)
{

}

IntType::~IntType()
{

}

int IntType::getSize()
{
	return sizeof(IntType::type);
}

UIntType::UIntType()
	: SimpleType(SimpleType::uintType)
{

}

UIntType::~UIntType()
{

}

int UIntType::getSize()
{
	return sizeof(UIntType::type);
}

FloatType::FloatType()
	: SimpleType(SimpleType::floatType)
{

}

FloatType::~FloatType()
{

}

int FloatType::getSize()
{
	return sizeof(FloatType::type);
}

DoubleType::DoubleType()
	: SimpleType(SimpleType::doubleType)
{

}

DoubleType::~DoubleType()
{

}

int DoubleType::getSize()
{
	return sizeof(DoubleType::type);
}

BoolType::BoolType()
	: SimpleType(SimpleType::boolType)
{

}

BoolType::~BoolType()
{

}

int BoolType::getSize()
{
	return sizeof(BoolType::type);
}

} // namespace Editor

} // namespace GDS
