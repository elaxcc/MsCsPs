#pragma once

#include "ConstantExpr.h"

namespace GDS
{

namespace Editor
{

class Varriable
{
public:
	Varriable(const ConstantExprPtr &type, const std::string& name);
	~Varriable();
	
	void setName(const std::string &name);

	ConstantExprPtr getConstantExpr();
	const std::string& getName() const;

private:
	ConstantExprPtr constExpr_;
	std::string name_;
};
typedef std::shared_ptr<Varriable> VarriablePtr;

class CharVarriable : public Varriable
{
public:
	CharVarriable(CharType::type value, const std::string &name);
	~CharVarriable();
};

class UCharVarriable : public Varriable
{
public:
	UCharVarriable(UCharType::type value, const std::string &name);
	~UCharVarriable();
};

class ShortVarriable : public Varriable
{
public:
	ShortVarriable(ShortType::type value, const std::string &name);
	~ShortVarriable();
};

class UShortVarriable : public Varriable
{
public:
	UShortVarriable(UShortType::type value, const std::string &name);
	~UShortVarriable();
};

class IntVarriable : public Varriable
{
public:
	IntVarriable(IntType::type value, const std::string &name);
	~IntVarriable();
};

class UIntVarriable : public Varriable
{
public:
	UIntVarriable(UIntType::type value, const std::string &name);
	~UIntVarriable();
};

class FloatVarriable : public Varriable
{
public:
	FloatVarriable(FloatType::type value, const std::string &name);
	~FloatVarriable();
};

class DoubleVarriable : public Varriable
{
public:
	DoubleVarriable(DoubleType::type value, const std::string &name);
	~DoubleVarriable();
};

class BoolVarriable : public Varriable
{
public:
	BoolVarriable(BoolType::type value, const std::string &name);
	~BoolVarriable();
};

} // namespace Editor

} // namespace GDS

