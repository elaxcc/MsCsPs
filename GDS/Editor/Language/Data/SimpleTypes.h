#pragma once

namespace GDS
{

namespace Editor
{

class SimpleType
{
public:
	enum Type
	{
		charType,
		ucharType,
		shortType,
		ushortType,
		intType,
		uintType,
		floatType,
		doubleType,
		boolType
	};

	SimpleType(Type type);
	~SimpleType();

	Type getType() const;

	virtual int getSize() = 0;

private:
	Type type_;
};
typedef std::shared_ptr<SimpleType> SimpleTypePtr;

class CharType : public SimpleType
{
public:
	typedef int8_t type;

	CharType();
	~CharType();

	// SimpleType
	virtual int getSize();
};

class UCharType : public SimpleType
{
public:
	typedef uint8_t type;

	UCharType();
	~UCharType();

	// SimpleType
	virtual int getSize();
};

class ShortType : public SimpleType
{
public:
	typedef int16_t type;

	ShortType();
	~ShortType();

	// SimpleType
	virtual int getSize();
};

class UShortType : public SimpleType
{
public:
	typedef uint16_t type;

	UShortType();
	~UShortType();

	// SimpleType
	virtual int getSize();
};

class IntType : public SimpleType
{
public:
	typedef int32_t type;

	IntType();
	~IntType();

	// SimpleType
	virtual int getSize();
};

class UIntType : public SimpleType
{
public:
	typedef uint32_t type;

	UIntType();
	~UIntType();

	// SimpleType
	virtual int getSize();
};

class FloatType : public SimpleType
{
public:
	typedef float type;

	FloatType();
	~FloatType();

	// SimpleType
	virtual int getSize();
};

class DoubleType : public SimpleType
{
public:
	typedef double type;

	DoubleType();
	~DoubleType();

	// SimpleType
	virtual int getSize();
};

class BoolType : public SimpleType
{
public:
	typedef bool type;

	BoolType();
	~BoolType();

	// SimpleType
	virtual int getSize();
};


} // namespace Editor

} // namespace GDS
