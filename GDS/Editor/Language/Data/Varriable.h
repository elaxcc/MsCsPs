#pragma once

#include "SimpleTypes.h"

namespace GDS
{

namespace Editor
{

class Varriable
{
public:
	Varriable(SimpleType *type);
	~Varriable();

	SimpleTypePtr getType() const;

protected:
	void* getValue() const;

private:
	SimpleTypePtr type_;
	void *value_;
};

class CharVarriable : public Varriable
{
public:
	CharVarriable();
	CharVarriable(CharType::type value);
	~CharVarriable();

	void setValue(CharType::type value);
	CharType::type* getValue();
};

class UCharVarriable : public Varriable
{
public:
	UCharVarriable();
	UCharVarriable(UCharType::type value);
	~UCharVarriable();

	void setValue(UCharType::type value);
	UCharType::type* getValue();
};

class ShortVarriable : public Varriable
{
public:
	ShortVarriable();
	ShortVarriable(ShortType::type value);
	~ShortVarriable();

	void setValue(ShortType::type value);
	ShortType::type* getValue();
};

class UShortVarriable : public Varriable
{
public:
	UShortVarriable();
	UShortVarriable(UShortType::type value);
	~UShortVarriable();

	void setValue(UShortType::type value);
	UShortType::type* getValue();
};

class IntVarriable : public Varriable
{
public:
	IntVarriable();
	IntVarriable(IntType::type value);
	~IntVarriable();

	void setValue(IntType::type value);
	IntType::type* getValue();
};

class UIntVarriable : public Varriable
{
public:
	UIntVarriable();
	UIntVarriable(UIntType::type value);
	~UIntVarriable();

	void setValue(UIntType::type value);
	UIntType::type* getValue();
};

class FloatVarriable : public Varriable
{
public:
	FloatVarriable();
	FloatVarriable(FloatType::type value);
	~FloatVarriable();

	void setValue(FloatType::type value);
	FloatType::type* getValue();
};

class DoubleVarriable : public Varriable
{
public:
	DoubleVarriable();
	DoubleVarriable(DoubleType::type value);
	~DoubleVarriable();

	void setValue(DoubleType::type value);
	DoubleType::type* getValue();
};

class BoolVarriable : public Varriable
{
public:
	BoolVarriable();
	BoolVarriable(BoolType::type value);
	~BoolVarriable();

	void setValue(BoolType::type value);
	BoolType::type* getValue();
};

} // namespace Editor

} // namespace GDS

