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
	std::cout << "\n�����: ";
	std::string a;
	getline(std::cin, a);
	std::string buffer = "";
	for (int i = 0; i < a.size(); i++) {
		if (a[i] != ' ') {
			buffer += a[i];
		}
		else {
			products.push_back(buffer);
			buffer = "";
		}
	}
	products.push_back(buffer);
	std::cout << "���-�� ������� ������: ";
	std::cin >> station;
	while (getchar() != '\n');
}

void Warehouse::print() {
	std::cout << "�����:\n�����: ";
	if (products.size() > 0)
		for (int i = 0; i < products.size(); i++)
			std::cout << products[i] << " ";
	else
		std::cout <<"�����.";
	std::cout << "\n������ ������ - " << station << "\n";
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
		std::cout << product << " ��� �� ������\n";
	else
		std::cout << product << " ���� �� ������\n";
}