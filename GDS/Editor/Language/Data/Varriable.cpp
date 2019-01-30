#include "stdafx.h"

#include "Varriable.h"

namespace GDS
{

namespace Editor
{

Varriable::Varriable(SimpleType *type)
	: type_(type)
{
	value_ = new char[type->getSize()];
}

Varriable::~Varriable()
{
	delete[] value_;
}

SimpleTypePtr Varriable::getType() const
{
	return type_;
}

void* Varriable::getValue() const
{
	return value_;
}

CharVarriable::CharVarriable()
	: Varriable(new CharType)
{

}

CharVarriable::CharVarriable(CharType::type value)
	: Varriable(new CharType)
{
	setValue(value);
}

CharVarriable::~CharVarriable()
{

}

void CharVarriable::setValue(CharType::type value)
{
	CharType::type *value_ptr = getValue();
	*value_ptr = value;
}

CharType::type* CharVarriable::getValue()
{
	return static_cast<CharType::type*>(Varriable::getValue());
}

UCharVarriable::UCharVarriable()
	: Varriable(new UCharType)
{

}

UCharVarriable::UCharVarriable(UCharType::type value)
	: Varriable(new UCharType)
{
	setValue(value);
}

UCharVarriable::~UCharVarriable()
{

}

void UCharVarriable::setValue(UCharType::type value)
{
	UCharType::type *value_ptr = getValue();
	*value_ptr = value;
}

UCharType::type* UCharVarriable::getValue()
{
	return static_cast<UCharType::type*>(Varriable::getValue());
}

ShortVarriable::ShortVarriable()
	: Varriable(new ShortType)
{

}

ShortVarriable::ShortVarriable(ShortType::type value)
	: Varriable(new ShortType)
{
	setValue(value);
}

ShortVarriable::~ShortVarriable()
{

}

void ShortVarriable::setValue(ShortType::type value)
{
	ShortType::type *value_ptr = getValue();
	*value_ptr = value;
}

ShortType::type* ShortVarriable::getValue()
{
	return static_cast<ShortType::type*>(Varriable::getValue());
}

UShortVarriable::UShortVarriable()
	: Varriable(new UShortType)
{

}

UShortVarriable::UShortVarriable(UShortType::type value)
	: Varriable(new UShortType)
{
	setValue(value);
}

UShortVarriable::~UShortVarriable()
{

}

void UShortVarriable::setValue(UShortType::type value)
{
	UShortType::type *value_ptr = getValue();
	*value_ptr = value;
}

UShortType::type* UShortVarriable::getValue()
{
	return static_cast<UShortType::type*>(Varriable::getValue());
}

IntVarriable::IntVarriable()
	: Varriable(new IntType)
{

}

IntVarriable::IntVarriable(IntType::type value)
	: Varriable(new IntType)
{
	setValue(value);
}

IntVarriable::~IntVarriable()
{

}

void IntVarriable::setValue(IntType::type value)
{
	IntType::type *value_ptr = getValue();
	*value_ptr = value;
}

IntType::type* IntVarriable::getValue()
{
	return static_cast<IntType::type*>(Varriable::getValue());
}

UIntVarriable::UIntVarriable()
	: Varriable(new UIntType)
{

}

UIntVarriable::UIntVarriable(UIntType::type value)
	: Varriable(new UIntType)
{
	setValue(value);
}

UIntVarriable::~UIntVarriable()
{

}

void UIntVarriable::setValue(UIntType::type value)
{
	UIntType::type *value_ptr = getValue();
	*value_ptr = value;
}

UIntType::type* UIntVarriable::getValue()
{
	return static_cast<UIntType::type*>(Varriable::getValue());
}

FloatVarriable::FloatVarriable()
	: Varriable(new FloatType)
{

}

FloatVarriable::FloatVarriable(FloatType::type value)
	: Varriable(new FloatType)
{
	setValue(value);
}

FloatVarriable::~FloatVarriable()
{

}

void FloatVarriable::setValue(FloatType::type value)
{
	FloatType::type *value_ptr = getValue();
	*value_ptr = value;
}

FloatType::type* FloatVarriable::getValue()
{
	return static_cast<FloatType::type*>(Varriable::getValue());
}

DoubleVarriable::DoubleVarriable()
	: Varriable(new DoubleType)
{

}

DoubleVarriable::DoubleVarriable(DoubleType::type value)
	: Varriable(new DoubleType)
{
	setValue(value);
}

DoubleVarriable::~DoubleVarriable()
{

}

void DoubleVarriable::setValue(DoubleType::type value)
{
	DoubleType::type *value_ptr = getValue();
	*value_ptr = value;
}

DoubleType::type* DoubleVarriable::getValue()
{
	return static_cast<DoubleType::type*>(Varriable::getValue());
}

BoolVarriable::BoolVarriable()
	: Varriable(new BoolType)
{

}

BoolVarriable::BoolVarriable(BoolType::type value)
	: Varriable(new BoolType)
{
	setValue(value);
}

BoolVarriable::~BoolVarriable()
{

}

void BoolVarriable::setValue(BoolType::type value)
{
	BoolType::type *value_ptr = getValue();
	*value_ptr = value;
}

BoolType::type* BoolVarriable::getValue()
{
	return static_cast<BoolType::type*>(Varriable::getValue());
}

} // namespace Editor

} // namespace GDS
