#include "composite.h"
void clientcode(component* _component)
{
	cout << "result : " << _component->Operation();
}

void clientcode2(component* _component1, component* _component2)
{
	if (_component1->is_composite())
	{
		_component1->add(_component2);
	}
	cout << "result : " << _component1->Operation();
}

//int main()
//{
//	component* simple = new leaf;
//	cout << "client : got a simple component." << endl;
//	clientcode(simple);
//
//	component* tree = new composite;
//	component* branch1 = new composite;
//
//	component* leaf_1 = new leaf;
//	component* leaf_2 = new leaf;
//	component* leaf_3 = new leaf;
//	branch1->add(leaf_1);
//	branch1->add(leaf_2);
//	component* branch2 = new composite;
//	branch2->add(leaf_3);
//	tree->add(branch1);
//	tree->add(branch2);
//	cout << "client : got a composite tree :" << endl;
//	clientcode(tree);
//	cout << "client : don't need to check the components cleass." << endl;
//	clientcode2(tree, simple);
//	cout << endl;
//
//	delete simple;
//	delete tree;
//	delete branch1;
//	delete branch2;
//	delete leaf_1;
//	delete leaf_2;
//	delete leaf_3;
//
//	return 0;
//}