#include "adapter.h"

void clientcode(const Target* _target)
{
	cout << _target->request();
}

//int main()
//{
//	cout << "start" << endl;
//	Target* _target = new Target;
//	clientcode(_target);
//
//	adaptee* _adeptee = new adaptee;
//	cout << "class has a weird interface." << endl;
//	cout << "Adaptee : " << _adeptee->specific_request();
//
//	adapter* _adapter = new adapter(_adeptee);
//	cout << "client : work with bia the adapter." << endl;
//	clientcode(_adapter);
//
//	delete _target;
//	delete _adapter;
//	delete _adeptee;
//
//	return 0;
//}