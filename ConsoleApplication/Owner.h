#pragma once
#include "FIO.h"
class Owner
{
private:
	FIO fio;
	int income;
	int expenses;
public:
	Owner();
	Owner(FIO f, int i, int e);
	Owner(FIO f);
	void enter();
	void print();
	int profitOwner();
	Owner(const Owner& obj);
};

