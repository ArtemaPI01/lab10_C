#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <conio.h>
#include <stdio.h>
#include "Boxoffice.h"
#include <string>

Boxoffice::Boxoffice(int workers) {
	this->workers = workers;
	fio = FIO();
	count = 0;
}

Boxoffice::Boxoffice(int workers, int count, FIO f) {
	this->workers = workers;
	this->count = count;
	this->fio = fio;
}

Boxoffice::Boxoffice() {
	workers = 0;
	count = 0;
	fio = FIO();
}

Boxoffice::Boxoffice(const Boxoffice& obj)
{
	workers = obj.workers;
	count = obj.count;
	fio = obj.fio;
}

void Boxoffice::enter() {
	bool a = true;
	while (a)
	{
		try
		{
			std::cout << "\nВведите ФИО старшего кассира : ";
			fio.enter();
			std::cout << "Введите кол-во касс рабочих: ";
			std::cin >> workers;
			if (workers < 0) throw std::exception("Ошибка! Отрицательное число.");
			std::cout << "\nВведите кол-во касс: ";
			std::cin >> count;
			if (count < 0) throw std::exception("Ошибка! Отрицательное число.");
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

void Boxoffice::print() {
	std::cout << "\nКасса:\nКол-во рабочих - " << workers << "\nКол - во касс - " << count;
	fio.print();
}

int& Boxoffice::cloakBoxoffice(int x) {
	int a;
	if (count - workers < 0)
		a = (x / count) * 2;
	else
		a = (x / workers) * 2;
	return a;
}

Boxoffice& Boxoffice::operator++()
{
	this->workers++;
	this->count++;
	return *this;
}

Boxoffice& Boxoffice::operator++(int x) {
	Boxoffice temp = *this;
	this->workers++;
	this->count++;
	return temp;
}

Boxoffice Boxoffice::operator+(const Boxoffice& other) {
	Boxoffice temp;
	temp.workers = this->workers + other.workers;
	temp.count = this->count + other.count;
	return temp;
}

Boxoffice Boxoffice::operator =(Boxoffice other) {
	workers = other.workers;
	count = other.count;
	fio = other.fio;
	return *this;
}