#pragma once
#include <iostream>
#include <string>

using namespace std;

class subject
{
public:
	virtual void request() const = 0;
};

class realsub : public subject
{
public:
	void request() const override
	{
		cout << "real subject : handle request." << endl;
	}
};

class proxy : public subject
{
private:
	realsub* sub;
	bool check_access() const
	{
		cout << "proxy : checking access prior to firing a real request." << endl;
		return true;
	}
	void log_access() const
	{
		cout << "proxy : logging the time of request." << endl;
	}
public:
	proxy(realsub* real_sub) : sub(new realsub(*real_sub)) {};
	~proxy()
	{
		delete sub;
	}
	void request() const override
	{
		if (this->check_access())
		{
			this->sub->request();
			this->log_access();
		}
	}
};

