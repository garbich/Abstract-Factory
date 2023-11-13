#include <iostream>

using namespace std;

class Order {
public:
	virtual void order() = 0;
};

class Dish : public Order {
public:
	void order() override {
		cout << "You ordered dish " << endl;
	 }
};

class Drink : public Order {
public:
	 void order() override {
		 cout << "You ordered drink " << endl;
	}
};

class Desert : public Order {
public:
	void order() override {
		cout << "You ordered desert " << endl;
	}
};

class RestoranFabric {
public:

	virtual Order* MakeOrder() = 0;
	
};

class Makeorder : public RestoranFabric{
public:
	/*Order* MakeOrder() override {
		Order* dish = new Dish();
		return dish;
	}*/

	Order* MakeOrder() override {
		Order* drink = new Drink();
		return drink;
	}
	/*
	Order* MakeOrder() override {
		Order* desert = new Desert();
		return desert;
	}*/

};




class ItalianoKitchen : public RestoranFabric {
public:
	/*Order* MakeOrder() {
		Order* order = new Dish();
		return order;
	}*/

	Order* MakeOrder() {
		Order* order = new Drink();
		return order;
	}
	/*
	Order* MakeOrder() {
		Order* order = new Desert();
		return order;
	}*/
};

class Visitor {
public:
	RestoranFabric* restorntFabric;

	Visitor(RestoranFabric* _restoranFabric) : restorntFabric(_restoranFabric) {}


	/*void MakeOrder() {
		Order* order = restorntFabric->MakeOrder();
		order->order();
	}*/

	void MakeOrder() {
		Order* order = restorntFabric->MakeOrder();
		order->order();
	}
	/*
	void MakeOrder() {
		Order* order = restorntFabric->MakeOrder();
		order->order();
	}*/
};



int main()
{
	RestoranFabric* restoranFabric = new ItalianoKitchen();

	Visitor* visitor = new Visitor(restoranFabric);
	visitor->MakeOrder();
}

