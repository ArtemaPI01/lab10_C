#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <conio.h>
#include <stdio.h>
#include "Owner.h"

Owner::Owner(FIO f, int i, int e) {
	this->fio = fio;
	this->income = income;
	this->expenses = expenses;
}

Owner::Owner(FIO f) {
	this->fio = fio;
	income = 0;
	expenses = 0;
}

Owner::Owner() {
	fio = FIO();
	income = 0;
	expenses = 0;
}

Owner::Owner(const Owner& obj)
{
	income = obj.income;
	expenses = obj.expenses;
	fio = obj.fio;
}

void Owner::enter() {
	std::cout << "������� ��� ���������: ";
	fio.enter();
	std::cout << "\n������� ������: ";
	std::cin >> income;
	std::cout << "\n������� �������: ";
	std::cin >> expenses;
	while (getchar() != '\n');
}

void Owner::print() {
	std::cout << "\n���������� � ���������:\n";
	fio.print();
	std::cout << "\n������ - " << income << "\n������� - " << expenses << "\n������� - " << profitOwner() << "\n";
}
int Owner::profitOwner() {
	return income - expenses;
}
