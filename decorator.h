#pragma once
#include <iostream>
#include <string>

using namespace std;
class component
{
public:
	virtual string Operation() const = 0;
};

class concrete_component : public component
{
public:
	string Operation() const override
	{
		return "concrete component ";
	}
};

class decorator : public component
{
protected:
	component* _component;
public:
	decorator(component* _compo) : _component(_compo)
	{
	}
	string Operation() const override
	{
		return this->_component->Operation();//this 안하면?
	}
};

class concrete_decorator_A : public decorator
{
public:
	concrete_decorator_A(component* _compo) : decorator(_compo)
	{
	}
public:
	string Operation() const override
	{
		return "concrete_decorator_A(" + decorator::Operation() + ")";//this 안하면?
	}
};

class concrete_decorator_B : public decorator
{
public:
	concrete_decorator_B(component* _compo) : decorator(_compo)
	{
	}
public:
	string Operation() const override
	{
		return "concrete_decorator_B(" + decorator::Operation() + ")";//this 안하면?
	}
};