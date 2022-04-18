#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "locale.h"
#include <stdio.h>
#include <conio.h>
#include <iostream>
#include <Windows.h>
#include "Shop.h"
#include "Owner.h"
#include "Boxoffice.h"
#include "Warehouse.h"
#include <vector>
#include <string>

using namespace std;

int main()
{
	try
	{
	setlocale(LC_ALL, "Rus");
	SetConsoleCP(1251);
	int N = 1;
	Shop* Ashan = new Shop[N]();
	for (int i = 0; i < N; i++)
	{
		Ashan[i] = Shop("A", "B", "C", "10:00-20:00");
		Ashan[i].print();
		cloakShop(Ashan[i]);
	}
	Shop Ashan2 = Shop(Ashan[0]);
	Ashan2.print();
	Ashan->CountOfShop();
	delete[] Ashan;
	Ashan->CountOfShop();
	Owner* Alisher = new Owner();
	Alisher->enter();
	Alisher->print();
	delete Alisher;
	vector<string> v = { "Арбуз", "Тыква", "Огурец" };
	Warehouse* house = new Warehouse(v, 7);
	(*house).print();
	int t = 20;
	cout << "\nСкорость разгрузки "<< t <<" тонн в минутах: " << *(*house).cloakWarehouse(20) << "\n";
	(*house).Poisk("Тыква");
	delete house;
	Boxoffice box = Boxoffice();
	box.enter();
	box.print();
	int x = 100;
	cout << "\nВремя обслуживания " << x << " клиентов - " << box.cloakBoxoffice(x) << " минуты\n";
	Boxoffice box1 = box++;
	box1.print();	
	Boxoffice box2 = ++box;
	box2.print();
	Boxoffice box3 = box1 + box2;
	box3.print();
	Boxoffice box4 = Boxoffice();
	box4 = box1;
	box4.print();
	_getch;
	}
	catch (const std::exception& ex)
	{
		std::cout << ex.what() << "\nДля продолжения нажмите любую кнопку.\n";
		_getch();
	}
}