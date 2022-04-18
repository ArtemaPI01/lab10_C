#pragma once
#include "FIO.h"
class Boxoffice
{
private:
	int workers;
	int count;
	FIO fio;
public:
	void enter();
	void print();
	int& cloakBoxoffice(int x);
	Boxoffice(const Boxoffice& obj);
	Boxoffice& operator ++();
	Boxoffice operator =(Boxoffice other);
	Boxoffice& operator ++(int x);
	Boxoffice operator +(const Boxoffice& other);
	Boxoffice();
	Boxoffice(int workers);
	Boxoffice(int workers, int count, FIO fio);
};

