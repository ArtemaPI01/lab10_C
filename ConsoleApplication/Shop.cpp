#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <conio.h>
#include <stdio.h>
#include "Shop.h"
#include <string>
int Shop::counter = 0;

Shop::Shop(std::string name, std::string type, std::string street, std::string cloak) :c(counter) {
	this->name = name;
	this->type = type;
	this->street = street;
	this->cloak = cloak;
	c = ++counter;
}

Shop::Shop() :c(counter) {
	c = ++counter;
	name = "";
	type = "";
	street = "";
	cloak = "";
}

Shop::Shop(std::string cloak) : c(counter) {
	this->cloak = cloak;
	c = ++counter;
	name = "";
	type = "";
	street = "";
}
Shop::Shop(const Shop& obj) {
	this->name = obj.name;
	this->type = obj.type;
	this->street = obj.street;
	this->cloak = obj.cloak;
	c = ++counter;
}

Shop::~Shop(){
	counter--;
}

void Shop::CountOfShop()
{
	std::cout << "���-�� ���������: " << counter << "\n";
}

int Shop::getSize() const
{
	return c;
}

void Shop::enter() {
	std::cout << "������� ��������: ";
	getline(std::cin, name);
	std::cout << "\n������� ���: ";
	getline(std::cin, type);
	std::cout << "\n������� �����: ";
	getline(std::cin, street);
	std::cout << "\n������� ���� ������: ";
	getline(std::cin, cloak);
}

void Shop::print() {
	std::cout << "\n���������� � ��������:\n�������� - " << name << "\n��� - " << type << "\n����� - " << street << "\n���� ������ - " << cloak << "\n", name, type, street, cloak;
}

void cloakShop(Shop &x) {
	char str1[5];
	char str2[5];
	int k = 0;
	for (int i = 0; i < 5; i++)
	{
		if (i == 2) i++;
		str1[k] = x.cloak.c_str()[i];
		str2[k] = x.cloak.c_str()[i + 6];
		k++;
	}
	int a = atoi(str2) / 100 - atoi(str1) / 100;
	int b = atoi(str2) % 100 - atoi(str1) % 100;
	if (b < 0) {
		b += 60;
		a--;
	}
	std::cout << "\n���� ������ - " << x.cloak << "\n���� -  " << a << " \n������ - " << b << "\n";
}