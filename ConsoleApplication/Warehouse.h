#pragma once
#include <vector>
class Warehouse
{
private:
	std::vector<std::string> products;
	int station;
public:
	Warehouse();
	Warehouse(std::vector<std::string> products);
	Warehouse(std::vector<std::string> products, int station);
	Warehouse(const Warehouse& obj);
	void enter();
	void print();
	int* cloakWarehouse(int x);
	void Poisk(std::string product);
};

