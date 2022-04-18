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
			std::cout << "\n������� ���: ";
			getline(std::cin, name);
			if (name == "") throw std::exception("������! ������ ������.");
			std::cout << "\n������� �������: ";
			getline(std::cin, surname);
			if (surname == "") throw std::exception("������! ������ ������.");
			std::cout << "\n������� ��������: ";
			getline(std::cin, patronymic);
			if (patronymic == "") throw std::exception("������! ������ ������.");
			a = false;
		}
		catch (const std::exception& ex)
		{
			std::cout << ex.what() << "\n��� ����������� ������� ����� ������.\n";
			_getch();
		}
	}
}
void FIO::print() {
	if (surname != "")
	{
		if (name != "")
			std::cout << "\n���: " << name << "  ";
		std::cout << "�������: " << surname << "  ";
		if (patronymic != "")
			std::cout << "��������: " << patronymic;
	}
}
