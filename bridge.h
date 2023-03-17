#pragma once
#include <iostream>
#include <string>

using namespace std;

class Implemmentation
{
public:
	virtual string OperationImplementation() const = 0;
};

class Concrete_Implementation_A : public Implemmentation
{
public:
	string OperationImplementation() const override
	{
		return "Concrete_Implementation_A : result plaform A.\n" ;
	}
};

class Concrete_Implementation_B : public Implemmentation
{
public:
	string OperationImplementation() const override
	{
		return "Concrete_Implementation_B: result plaform B.\n" ;
	}
};

class Abstraction
{
protected:
	Implemmentation* _implementation;
public:
	Abstraction(Implemmentation* implementation) : _implementation(implementation)
	{
	}
	virtual string Operation() const
	{
		return "Abstraction : base operation with \n" + this->_implementation->OperationImplementation();
	}
};

class ExtendedAbstraction : public Abstraction
{
public:
	ExtendedAbstraction(Implemmentation* implementation) : Abstraction(implementation)
	{
	}
	string Operation() const override
	{
		return "ExtendedAbstraction : operation with \n" + this->_implementation->OperationImplementation();
	}



};