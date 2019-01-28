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
		char_Type,
		uchar_Type,
		short_Type,
		ushort_Type,
		int_Type,
		uint_Type,
		float_Type,
		double_Type
	};

	SimpleType(Type type);
	~SimpleType();

	Type get_type() const;

	virtual int get_size() = 0;

private:
	Type type_;
};

class CharType : public SimpleType
{
public:
	typedef int8_t type;

	CharType();
	~CharType();

	// SimpleType
	virtual int get_size();
};

class UCharType : public SimpleType
{
public:
	typedef uint8_t type;

	UCharType();
	~UCharType();

	// SimpleType
	virtual int get_size();
};

class ShortType : public SimpleType
{
public:
	typedef int16_t type;

	ShortType();
	~ShortType();

	// SimpleType
	virtual int get_size();
};

class UShortType : public SimpleType
{
public:
	typedef uint16_t type;

	UShortType();
	~UShortType();

	// SimpleType
	virtual int get_size();
};

class IntType : public SimpleType
{
public:
	typedef int32_t type;

	IntType();
	~IntType();

	// SimpleType
	virtual int get_size();
};

class UIntType : public SimpleType
{
public:
	typedef uint32_t type;

	UIntType();
	~UIntType();

	// SimpleType
	virtual int get_size();
};

class FloatType : public SimpleType
{
public:
	typedef float type;

	FloatType();
	~FloatType();

	// SimpleType
	virtual int get_size();
};

class DoubleType : public SimpleType
{
public:
	typedef double type;

	DoubleType();
	~DoubleType();

	// SimpleType
	virtual int get_size();
};

} // namespace Editor

} // namespace GDS
