#include "bridge.h"

void clientcode (const Abstraction& abstraction)
{
	cout << abstraction.Operation();
}

int main()
{
	Implemmentation* imple = new Concrete_Implementation_A;
	Abstraction* abstraction = new Abstraction(imple);
	clientcode(*abstraction);
	delete imple;
	delete abstraction;

	imple = new Concrete_Implementation_B;
	abstraction = new ExtendedAbstraction(imple);
	clientcode(*abstraction);
	delete imple;
	delete abstraction;
	
	return 0;
}