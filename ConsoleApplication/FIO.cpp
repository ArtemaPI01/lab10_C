#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <conio.h>
#include <stdio.h>
#include "FIO.h"
#include <string>

FIO::FIO() {
	name = "";
	surname = "";
	patronymic = "";
}
FIO::FIO(std::string surname) {
	name = "";
	this->surname = surname;
	patronymic = "";
}
FIO::FIO(std::string name, std::string surname, std::string patronymic) {
	this->name = name;
	this->surname = surname;
	this->patronymic = patronymic;
}

FIO::FIO(const FIO& obj)
{
	name = obj.name;
	surname = obj.surname;
	patronymic = obj.patronymic;
}


void FIO::enter() {
	bool a = true;
	while (a)
	{
		try
		{
			std::cout << "\nВведите имя: ";
			getline(std::cin, name);
			if (name == "") throw std::exception("Ошибка! Пустая строка.");
			std::cout << "\nВведите фамилию: ";
			getline(std::cin, surname);
			if (surname == "") throw std::exception("Ошибка! Пустая строка.");
			std::cout << "\nВведите отчество: ";
			getline(std::cin, patronymic);
			if (patronymic == "") throw std::exception("Ошибка! Пустая строка.");
			a = false;
		}
		catch (const std::exception& ex)
		{
			std::cout << ex.what() << "\nДля продолжения нажмите любую кнопку.\n";
			_getch();
		}
	}
}
void FIO::print() {
	if (surname != "")
	{
		if (name != "")
			std::cout << "\nИмя: " << name << "  ";
		std::cout << "Фамилия: " << surname << "  ";
		if (patronymic != "")
			std::cout << "Отчество: " << patronymic;
	}
}
