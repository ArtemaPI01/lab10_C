#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <conio.h>
#include <stdio.h>
#include "Warehouse.h"
#include <string>
#include <algorithm>

Warehouse::Warehouse(){
	station = 0;
	products = {};
}

Warehouse::Warehouse(std::vector<std::string> products) {
	this->products = products;
	station = 0;
}

Warehouse::Warehouse(std::vector<std::string> products, int station) {
	this->products = products;
	this->station = station;
}

Warehouse::Warehouse(const Warehouse& obj)
{
	products = obj.products;
	station = obj.station;
}


void Warehouse::enter() {
	bool a = true;
	while (a)
	{
		try
		{
			std::cout << "\nТовар: ";
			std::string str;
			getline(std::cin, str);
			std::string buffer = "";
			for (int i = 0; i < str.size(); i++) {
				if (str[i] != ' ') {
					buffer += str[i];
				}
				else {
					products.push_back(buffer);
					buffer = "";
				}
			}
			products.push_back(buffer);
			std::cout << "Кол-во пунктов приема: ";
			std::cin >> station;
			if (station < 0) throw std::exception("Ошибка! Отрицательное число.");
			while (getchar() != '\n');
			a = false;
		}
		catch (const std::exception& ex)
		{
			std::cout << ex.what() << "\nДля продолжения нажмите любую кнопку.\n";
			_getch();
		}
	}
}

void Warehouse::print() {
	std::cout << "Склад:\nТовар: ";
	if (products.size() > 0)
		for (int i = 0; i < products.size(); i++)
			std::cout << products[i] << " ";
	else
		std::cout <<"пусто.";
	std::cout << "\nПункты приема - " << station << "\n";
}

int* Warehouse::cloakWarehouse(int x) {
	int i = 0;
	int time = 0;
	while (i < x)
	{
		time += 15;
		i += station;
	}
	return &time;
}

void Warehouse::Poisk(std::string product) {
	std::vector<std::string>::iterator it = find(products.begin(), products.end(), product);
	if (it == products.end())
		std::cout << product << " нет на складе\n";
	else
		std::cout << product << " есть на складе\n";
}