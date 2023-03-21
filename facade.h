#pragma once
#include <iostream>
#include <string>

using namespace std;

class subsystem1
{
public:
	string Operation1()
	{
		return "subsystem1 : ready!\n";
	}
	string Operation2()
	{
		return "subsystem1 : go!\n";
	}
};

class subsystem2
{
public:
	string Operation1()
	{
		return "subsystem2 : ready!\n";
	}
	string Operation3()
	{
		return "subsystem2 : fire!\n";
	}
};

class facade
{
protected:
	subsystem1* sys1;
	subsystem2* sys2;
public:
	facade(subsystem1* _sys1 = nullptr, subsystem2* _sys2 = nullptr)
	{
		this->sys1 = _sys1? _sys1 : new subsystem1;
		this->sys2 = _sys2? _sys2 : new subsystem2;
	}
	~facade()
	{
		delete sys1;
		delete sys2;
	}
	string Operation()
	{
		string result = "facade initialize system : \n";
		result += this->sys1->Operation1();
		result += this->sys2->Operation1();
		result += "facade other system action: \n";
		result += this->sys1->Operation2();
		result += this->sys2->Operation3();
		return result;
	}
};

