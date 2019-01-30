#pragma once

#include "Editor/Language/Data/Varriable.h"

namespace GDS
{

namespace Editor
{

class Operator
{
public:
	void setResult(VarriablePtr result) { result_ = result; }
	VarriablePtr getResult() { return result_; }

	virtual void exec() = 0;

private:
	VarriablePtr result_;
};

class UnaryOperator : public Operator
{
public:
	UnaryOperator(VarriablePtr operand)
		: operand_(operand)
	{

	}

private:
	VarriablePtr operand_;
};

class BinaryOperator : public Operator
{
public:
	BinaryOperator(VarriablePtr operand1, VarriablePtr operand2)
		: operand1_(operand1)
		, operand2_(operand2)
	{

	}

private:
	VarriablePtr operand1_;
	VarriablePtr operand2_;
};

class TernaryOperator : public Operator
{
public:
	TernaryOperator(VarriablePtr operand1, VarriablePtr operand2, VarriablePtr operand3)
		: operand1_(operand1)
		, operand2_(operand2)
		, operand3_(operand3)
	{

	}

private:
	VarriablePtr operand1_;
	VarriablePtr operand2_;
	VarriablePtr operand3_;
};

} // namespace Editor

} // namespace GDS
