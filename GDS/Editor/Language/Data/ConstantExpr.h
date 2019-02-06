#pragma once

#include "SimpleTypes.h"

namespace GDS
{

namespace Editor
{

class ConstantExpr
{
public:
	ConstantExpr(const SimpleTypePtr &type);
	~ConstantExpr();

	SimpleTypePtr getType() const;

protected:
	void* getValue() const;

private:
	SimpleTypePtr type_;
	void *value_;
};
typedef std::shared_ptr<ConstantExpr> ConstantExprPtr;

class CharConstantExpr : public ConstantExpr
{
public:
	CharConstantExpr();
	CharConstantExpr(CharType::type value);
	~CharConstantExpr();

	void setValue(CharType::type value);
	CharType::type* getValue();
};
typedef std::shared_ptr<CharConstantExpr> CharVarriablePtr;

class UCharConstantExpr : public ConstantExpr
{
public:
	UCharConstantExpr();
	UCharConstantExpr(UCharType::type value);
	~UCharConstantExpr();

	void setValue(UCharType::type value);
	UCharType::type* getValue();
};
typedef std::shared_ptr<UCharConstantExpr> UCharVarriablePtr;

class ShortConstantExpr : public ConstantExpr
{
public:
	ShortConstantExpr();
	ShortConstantExpr(ShortType::type value);
	~ShortConstantExpr();

	void setValue(ShortType::type value);
	ShortType::type* getValue();
};
typedef std::shared_ptr<ShortConstantExpr> ShortVarriablePtr;

class UShortConstantExpr : public ConstantExpr
{
public:
	UShortConstantExpr();
	UShortConstantExpr(UShortType::type value);
	~UShortConstantExpr();

	void setValue(UShortType::type value);
	UShortType::type* getValue();
};
typedef std::shared_ptr<UShortConstantExpr> UShortVarriablePtr;

class IntConstantExpr : public ConstantExpr
{
public:
	IntConstantExpr();
	IntConstantExpr(IntType::type value);
	~IntConstantExpr();

	void setValue(IntType::type value);
	IntType::type* getValue();
};
typedef std::shared_ptr<IntConstantExpr> IntVarriablePtr;

class UIntConstantExpr : public ConstantExpr
{
public:
	UIntConstantExpr();
	UIntConstantExpr(UIntType::type value);
	~UIntConstantExpr();

	void setValue(UIntType::type value);
	UIntType::type* getValue();
};
typedef std::shared_ptr<UIntConstantExpr> UIntVarriablePtr;

class FloatConstantExpr : public ConstantExpr
{
public:
	FloatConstantExpr();
	FloatConstantExpr(FloatType::type value);
	~FloatConstantExpr();

	void setValue(FloatType::type value);
	FloatType::type* getValue();
};
typedef std::shared_ptr<FloatConstantExpr> FloatVarriablePtr;

class DoubleConstantExpr : public ConstantExpr
{
public:
	DoubleConstantExpr();
	DoubleConstantExpr(DoubleType::type value);
	~DoubleConstantExpr();

	void setValue(DoubleType::type value);
	DoubleType::type* getValue();
};
typedef std::shared_ptr<DoubleConstantExpr> DoubleVarriablePtr;

class BoolConstantExpr : public ConstantExpr
{
public:
	BoolConstantExpr();
	BoolConstantExpr(BoolType::type value);
	~BoolConstantExpr();

	void setValue(BoolType::type value);
	BoolType::type* getValue();
};
typedef std::shared_ptr<BoolConstantExpr> BoolVarriablePtr;

} // namespace Editor

} // namespace GDS
