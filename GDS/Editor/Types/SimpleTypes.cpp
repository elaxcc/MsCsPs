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

SimpleType::Type SimpleType::get_type() const
{
	return type_;
}

CharType::CharType()
	: SimpleType(SimpleType::char_Type)
{

}

CharType::~CharType()
{

}

int CharType::get_size()
{
	return sizeof(CharType::type);
}

UCharType::UCharType()
	: SimpleType(SimpleType::uchar_Type)
{

}

UCharType::~UCharType()
{

}

int UCharType::get_size()
{
	return sizeof(UCharType::type);
}

ShortType::ShortType()
	: SimpleType(SimpleType::short_Type)
{

}

ShortType::~ShortType()
{

}

int ShortType::get_size()
{
	return sizeof(ShortType::type);
}

UShortType::UShortType()
	: SimpleType(SimpleType::ushort_Type)
{

}

UShortType::~UShortType()
{

}

int UShortType::get_size()
{
	return sizeof(UShortType::type);
}

IntType::IntType()
	: SimpleType(SimpleType::int_Type)
{

}

IntType::~IntType()
{

}

int IntType::get_size()
{
	return sizeof(IntType::type);
}

UIntType::UIntType()
	: SimpleType(SimpleType::uint_Type)
{

}

UIntType::~UIntType()
{

}

int UIntType::get_size()
{
	return sizeof(UIntType::type);
}

FloatType::FloatType()
	: SimpleType(SimpleType::float_Type)
{

}

FloatType::~FloatType()
{

}

int FloatType::get_size()
{
	return sizeof(FloatType::type);
}

DoubleType::DoubleType()
	: SimpleType(SimpleType::double_Type)
{

}

DoubleType::~DoubleType()
{

}

int DoubleType::get_size()
{
	return sizeof(DoubleType::type);
}

} // namespace Editor

} // namespace GDS
