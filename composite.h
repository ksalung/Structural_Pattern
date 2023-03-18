#pragma once
#include <iostream>
#include <algorithm>
#include <list>
#include <string>

using namespace std;

class component 
{
protected:
	component* _parent;
public:
	void set_parent(component* parent)
	{
		this->_parent = parent;
	}
	component* get_parent() const
	{
		return this->_parent;
	}
	virtual void add(component* _component) {}
	virtual void remove(component* _component) {}
	virtual bool is_composite() const
	{
		return false;
	}
	virtual string Operation() const = 0;
};

class leaf : public component
{
public:
	string Operation() const override
	{
		return "LEAF";
	}
};

class composite : public component
{
protected:
	list<component*> _children;
public:
	void add(component* _component) override
	{
		_children.remove(_component);
		_component->set_parent(nullptr);
	}
	bool is_composite() const override
	{
		return true;
	}
	string Operation() const override
	{
		string result;
		for (const component* c : _children)
		{
			if (c = _children.back())
			{
				result += c->Operation();
			}
			else {
				result += c->Operation() + "+";
			}
		}
		return "branch(" + result + "); ";
	}
};

