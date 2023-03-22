#include "facade.h"

void clientcode(facade* _facade)
{
	cout << _facade->Operation();
}

//int main()
//{
//	subsystem1* sys1 = new subsystem1;
//	subsystem2* sys2 = new subsystem2;
//	facade* _facade = new facade(sys1, sys2);
//	clientcode(_facade);
//
//	delete _facade;
//
//	return 0;
//}