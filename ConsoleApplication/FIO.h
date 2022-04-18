#pragma once
class FIO
{
private:
	std::string name;
	std::string surname;
	std::string patronymic;
public:
	void enter();
	void print();
	FIO();
	FIO(const FIO& obj);
	FIO(std::string surname);
	FIO(std::string name, std::string surname, std::string patronymic);
};

