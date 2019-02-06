#include "stdafx.h"

#include "Varriable.h"

namespace GDS
{

namespace Editor
{

Varriable::Varriable(const ConstantExprPtr &constExpr, const std::string& name)
	: constExpr_(constExpr)
	, name_(name)
{

}

Varriable::~Varriable()
{

}

void Varriable::setName(const std::string &name)
{
	name_ = name;
}

ConstantExprPtr Varriable::getConstantExpr()
{
	return constExpr_;
}

const std::string& Varriable::getName() const
{
	return name_;
}

CharVarriable::CharVarriable(CharType::type value, const std::string &name)
	: Varriable(ConstantExprPtr(new CharConstantExpr(value)), name)
{

}

CharVarriable::~CharVarriable()
{

}

UCharVarriable::UCharVarriable(UCharType::type value, const std::string &name)
	: Varriable(ConstantExprPtr(new UCharConstantExpr(value)), name)
{

}

UCharVarriable::~UCharVarriable()
{

}

ShortVarriable::ShortVarriable(ShortType::type value, const std::string &name)
	: Varriable(ConstantExprPtr(new ShortConstantExpr(value)), name)
{

}

ShortVarriable::~ShortVarriable()
{

}

UShortVarriable::UShortVarriable(UShortType::type value, const std::string &name)
	: Varriable(ConstantExprPtr(new UShortConstantExpr(value)), name)
{

}

UShortVarriable::~UShortVarriable()
{

}

IntVarriable::IntVarriable(IntType::type value, const std::string &name)
	: Varriable(ConstantExprPtr(new IntConstantExpr(value)), name)
{

}

IntVarriable::~IntVarriable()
{

}

UIntVarriable::UIntVarriable(UIntType::type value, const std::string &name)
	: Varriable(ConstantExprPtr(new UIntConstantExpr(value)), name)
{

}

UIntVarriable::~UIntVarriable()
{

}

FloatVarriable::FloatVarriable(FloatType::type value, const std::string &name)
	: Varriable(ConstantExprPtr(new FloatConstantExpr(value)), name)
{

}

FloatVarriable::~FloatVarriable()
{

}

DoubleVarriable::DoubleVarriable(DoubleType::type value, const std::string &name)
	: Varriable(ConstantExprPtr(new DoubleConstantExpr(value)), name)
{

}

DoubleVarriable::~DoubleVarriable()
{

}

BoolVarriable::BoolVarriable(BoolType::type value, const std::string &name)
	: Varriable(ConstantExprPtr(new BoolConstantExpr(value)), name)
{

}

BoolVarriable::~BoolVarriable()
{

}

} // namespace Editor

} // namespace GDS
