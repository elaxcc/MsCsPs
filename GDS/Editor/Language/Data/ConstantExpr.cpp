#include "stdafx.h"

#include "ConstantExpr.h"

namespace GDS
{

namespace Editor
{

ConstantExpr::ConstantExpr(const SimpleTypePtr &type)
	: type_(type.get())
{
	value_ = new char[type->getSize()];
}

ConstantExpr::~ConstantExpr()
{
	delete[] value_;
}

SimpleTypePtr ConstantExpr::getType() const
{
	return type_;
}

void* ConstantExpr::getValue() const
{
	return value_;
}

CharConstantExpr::CharConstantExpr()
	: ConstantExpr(SimpleTypePtr(new CharType))
{

}

CharConstantExpr::CharConstantExpr(CharType::type value)
	: ConstantExpr(SimpleTypePtr(new CharType))
{
	setValue(value);
}

CharConstantExpr::~CharConstantExpr()
{

}

void CharConstantExpr::setValue(CharType::type value)
{
	CharType::type *value_ptr = getValue();
	*value_ptr = value;
}

CharType::type* CharConstantExpr::getValue()
{
	return static_cast<CharType::type*>(ConstantExpr::getValue());
}

UCharConstantExpr::UCharConstantExpr()
	: ConstantExpr(SimpleTypePtr(new UCharType))
{

}

UCharConstantExpr::UCharConstantExpr(UCharType::type value)
	: ConstantExpr(SimpleTypePtr(new UCharType))
{
	setValue(value);
}

UCharConstantExpr::~UCharConstantExpr()
{

}

void UCharConstantExpr::setValue(UCharType::type value)
{
	UCharType::type *value_ptr = getValue();
	*value_ptr = value;
}

UCharType::type* UCharConstantExpr::getValue()
{
	return static_cast<UCharType::type*>(ConstantExpr::getValue());
}

ShortConstantExpr::ShortConstantExpr()
	: ConstantExpr(SimpleTypePtr(new ShortType))
{

}

ShortConstantExpr::ShortConstantExpr(ShortType::type value)
	: ConstantExpr(SimpleTypePtr(new ShortType))
{
	setValue(value);
}

ShortConstantExpr::~ShortConstantExpr()
{

}

void ShortConstantExpr::setValue(ShortType::type value)
{
	ShortType::type *value_ptr = getValue();
	*value_ptr = value;
}

ShortType::type* ShortConstantExpr::getValue()
{
	return static_cast<ShortType::type*>(ConstantExpr::getValue());
}

UShortConstantExpr::UShortConstantExpr()
	: ConstantExpr(SimpleTypePtr(new UShortType))
{

}

UShortConstantExpr::UShortConstantExpr(UShortType::type value)
	: ConstantExpr(SimpleTypePtr(new UShortType))
{
	setValue(value);
}

UShortConstantExpr::~UShortConstantExpr()
{

}

void UShortConstantExpr::setValue(UShortType::type value)
{
	UShortType::type *value_ptr = getValue();
	*value_ptr = value;
}

UShortType::type* UShortConstantExpr::getValue()
{
	return static_cast<UShortType::type*>(ConstantExpr::getValue());
}

IntConstantExpr::IntConstantExpr()
	: ConstantExpr(SimpleTypePtr(new IntType))
{

}

IntConstantExpr::IntConstantExpr(IntType::type value)
	: ConstantExpr(SimpleTypePtr(new IntType))
{
	setValue(value);
}

IntConstantExpr::~IntConstantExpr()
{

}

void IntConstantExpr::setValue(IntType::type value)
{
	IntType::type *value_ptr = getValue();
	*value_ptr = value;
}

IntType::type* IntConstantExpr::getValue()
{
	return static_cast<IntType::type*>(ConstantExpr::getValue());
}

UIntConstantExpr::UIntConstantExpr()
	: ConstantExpr(SimpleTypePtr(new UIntType))
{

}

UIntConstantExpr::UIntConstantExpr(UIntType::type value)
	: ConstantExpr(SimpleTypePtr(new UIntType))
{
	setValue(value);
}

UIntConstantExpr::~UIntConstantExpr()
{

}

void UIntConstantExpr::setValue(UIntType::type value)
{
	UIntType::type *value_ptr = getValue();
	*value_ptr = value;
}

UIntType::type* UIntConstantExpr::getValue()
{
	return static_cast<UIntType::type*>(ConstantExpr::getValue());
}

FloatConstantExpr::FloatConstantExpr()
	: ConstantExpr(SimpleTypePtr(new FloatType))
{

}

FloatConstantExpr::FloatConstantExpr(FloatType::type value)
	: ConstantExpr(SimpleTypePtr(new FloatType))
{
	setValue(value);
}

FloatConstantExpr::~FloatConstantExpr()
{

}

void FloatConstantExpr::setValue(FloatType::type value)
{
	FloatType::type *value_ptr = getValue();
	*value_ptr = value;
}

FloatType::type* FloatConstantExpr::getValue()
{
	return static_cast<FloatType::type*>(ConstantExpr::getValue());
}

DoubleConstantExpr::DoubleConstantExpr()
	: ConstantExpr(SimpleTypePtr(new DoubleType))
{

}

DoubleConstantExpr::DoubleConstantExpr(DoubleType::type value)
	: ConstantExpr(SimpleTypePtr(new DoubleType))
{
	setValue(value);
}

DoubleConstantExpr::~DoubleConstantExpr()
{

}

void DoubleConstantExpr::setValue(DoubleType::type value)
{
	DoubleType::type *value_ptr = getValue();
	*value_ptr = value;
}

DoubleType::type* DoubleConstantExpr::getValue()
{
	return static_cast<DoubleType::type*>(ConstantExpr::getValue());
}

BoolConstantExpr::BoolConstantExpr()
	: ConstantExpr(SimpleTypePtr(new BoolType))
{

}

BoolConstantExpr::BoolConstantExpr(BoolType::type value)
	: ConstantExpr(SimpleTypePtr(new BoolType))
{
	setValue(value);
}

BoolConstantExpr::~BoolConstantExpr()
{

}

void BoolConstantExpr::setValue(BoolType::type value)
{
	BoolType::type *value_ptr = getValue();
	*value_ptr = value;
}

BoolType::type* BoolConstantExpr::getValue()
{
	return static_cast<BoolType::type*>(ConstantExpr::getValue());
}

} // namespace Editor

} // namespace GDS
