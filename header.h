#pragma once
#include<iostream>
#include<string>
using namespace std;

class Ship
{
public:
	virtual void run() = 0;
	virtual void shot() = 0;
};

class NorthCarolina :public Ship
{
public:
	void run() { cout << "NorthCarolina is running." << endl; };
	void shot() { cout << "NorthCarolina is shotting." << endl; };
};

class Iowa :public Ship
{
public:
	void run() { cout << "Iowa is running." << endl; };
	void shot() { cout << "Iowa is shotting." << endl; };
};

class Decorator :public Ship
{
public:
	Decorator(Ship* ship) :ship(ship) {};
	void run() { ship->run(); }
	void shot() { ship->shot(); }
protected:
	Ship* ship;
};

class ScoutPlane :public Decorator
{
	string scout;
public:
	ScoutPlane(Ship* ship) :Decorator(ship) {}
	void setScout() { scout = "Searching......"; };
	void getScout() { cout << scout << endl; }
	void run() {
		ship->run();
		setScout();
		getScout();
	}
	void shot() {
		ship->shot();
	}
};

class Ammu :public Decorator
{
	string ammu;
public:
	Ammu(Ship* ship) :Decorator(ship) {}
	void setAmmu() { ammu = "AP"; };
	void getAmmu() { cout << "shotting " << ammu << "." << endl; }
	void run() {
		ship->run();
	}
	void shot() {
		ship->shot();
		setAmmu();
		getAmmu();
	}
};