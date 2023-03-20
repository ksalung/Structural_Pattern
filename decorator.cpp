#include "decorator.h"

void cliencode(component* _compo)
{
	cout << "result : " << _compo->Operation();
}

int main()
{
	component* _compo = new concrete_component;
	cout << "got a simple component." << endl;
	cliencode(_compo);

	cout << "\n" << endl;
	component* dec1 = new concrete_decorator_A(_compo);
	component* dec2 = new concrete_decorator_B(dec1);
	cout << "Client: Now I've got a decorated component:"<< endl;
	cliencode(dec2);

	delete _compo;
	delete dec1;
	delete dec2;

	return 0;
}