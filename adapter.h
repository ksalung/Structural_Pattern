#pragma once
#include <iostream>
#include <string>

using namespace std;

class Target
{
public:
	virtual string request() const
	{
		return "Target : defualt target's behavior.";
	}
};

class adaptee
{
public:
	string specific_request() 
	{
		return "run.\n" ;
	}
};

class adapter : public Target
{
private:
	adaptee* _adaptee;
public:
	adapter(adaptee* __adaptee) : _adaptee(__adaptee)
	{
	}
	string request() const override
	{
		string to_reverse = this->_adaptee->specific_request();
		std::reverse(to_reverse.begin(), to_reverse.end());
		return "adaper : (TRANSLATED)" + to_reverse;
	}
};