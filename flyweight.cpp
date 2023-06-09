#include "flyweight.h"
void add_car_to_police_data(flyweight_factory& ff, const string& plates, const string& owner, const string& brand, const string& model, const string& color)
{
	cout << "\nclient : adding a car to data." << endl;
	const flyweight& fly = ff.getflyweight({ brand, model, color });
	fly.Operation({ owner, plates });
}

//int main()
//{
//	flyweight_factory* _factory = new flyweight_factory({ {"chevrolet", "camaro2020", "pink"}, {"Mercedes benz", "c300", "black"}, {"Mercedes benz", "c500", "red"}, {"BMW", "M5", "red"}, {"BMS", "X6", "white"}});
//	_factory->list_flyweight();
//
//	add_car_to_police_data(*_factory, 
//		"CL234IR",
//		"James Doe",
//		"BMW",
//		"M5",
//		"red");
//
//	add_car_to_police_data(*_factory,
//		"CL234IR",
//		"James Doe",
//		"BMW",
//		"X1",
//		"red");
//	_factory->list_flyweight();
//	delete _factory;
//	return 0;
//}