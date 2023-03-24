#include "proxy.h"

void clientcode(const subject& sub)
{
	sub.request();
}

int main()
{
	cout << "excute client code with a real subject." << endl;
	realsub* sub = new realsub;
	clientcode(*sub);
	cout << "excute client code with a proxy." << endl;
	proxy* _proxy = new proxy(sub);
	clientcode(*_proxy);

	delete sub;
	delete _proxy;
	return 0;
}