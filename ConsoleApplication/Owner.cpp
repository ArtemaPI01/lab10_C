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
	std::cout << "Введите ФИО владельца: ";
	fio.enter();
	std::cout << "\nВведите доходы: ";
	std::cin >> income;
	std::cout << "\nВведите расходы: ";
	std::cin >> expenses;
	while (getchar() != '\n');
}

void Owner::print() {
	std::cout << "\nИнформация о владельце:\n";
	fio.print();
	std::cout << "\nДоходы - " << income << "\nРасходы - " << expenses << "\nПрибыль - " << profitOwner() << "\n";
}
int Owner::profitOwner() {
	return income - expenses;
}
