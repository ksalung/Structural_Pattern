#pragma once
#include <iostream>
#include <string>
#include <unordered_map>
#include <initializer_list>

using namespace std;
struct sharedstate
{
	string brand;
	string model;
	string color;
	sharedstate(const string& _brand, const string& _model, const string& _color)
		:brand(_brand), model(_model), color(_color)
	{
	}
	friend ostream& operator <<(ostream& os, const sharedstate& ss)
	{
		return os << "[" << ss.brand << "  ,   " << ss.model << "  ,  " << ss.color << " ]";
	}
};

struct uniquestate
{
	string owner;
	string plates;
	uniquestate(const string _owner, const string _plates)
		:owner(_owner), plates(_plates)
	{
	}
	friend ostream& operator <<(ostream& os, const uniquestate& ss)
	{
		return os << "[" << ss.owner << "  ,   " << ss.plates << " ]";
	}
};

class flyweight
{
private:
	sharedstate* state;
public:
	flyweight(const sharedstate* _state):state(new sharedstate(*_state))
	{}
	flyweight(const flyweight& other) :state(new sharedstate(*other.state))
	{}
	~flyweight()
	{
		delete state;
	}
	sharedstate* shared_state() const
	{
		return state;
	}
	void Operation(const uniquestate& _state) const
	{
		cout << "flyweight : displaying shared (" << _state << ") and unique (" << _state << ") state. \n";
	}
};

class flyweight_factory
{
private:
	unordered_map<string, flyweight> _fly;
	string get_key(const sharedstate& ss) const
	{
		return ss.brand + "_" + ss.model + "_" + ss.color;
	}
public:
	flyweight_factory(std::initializer_list<sharedstate> _state)
	{
		for (const sharedstate& ss : _state)
		{
			this->_fly.insert(make_pair<string, flyweight>(this->get_key(ss), flyweight(&ss)));
		}
	}

	flyweight getflyweight(const sharedstate& _state)
	{
		string key = this->get_key(_state);
		if (this->_fly.find(key) == this->_fly.end())
		{
			cout << "flyweightfactory : can't find flyweight. please create onething." << endl;
			this->_fly.insert(make_pair(key, flyweight(&_state)));
		}
		else
		{
			cout << "flyweightfactory : reusing existing flyweight." << endl;
		}
		return this->_fly.at(key);
	}
	void list_flyweight() const
	{
		size_t count = this->_fly.size();
		cout << "\n flyweightfactory L i have " << count << "flyweights: " << endl;
		for (pair<string, flyweight> _pair : this->_fly)
			{
			cout << _pair.first << endl;
			}
	}
};

