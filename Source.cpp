#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
using namespace std;
class legal_service
{
public:
	legal_service();
	legal_service(int number, int category, string name_service, string date, string name_client, string name_lawyer, int price);
	~legal_service();
private:
	int number;//номер услуги
	int category;//категория услуги
	string name_service;//название услуги
	string date;//дата
	string name_client;//фио клиента
	string name_lawyer;//фио юриста
	int price;//стоимость
};
int main()
{
	setlocale(LC_ALL, "rus");
	legal_service service;
	vector<legal_service> arr;
	int var_switch;
	var_switch = 0;
	bool exit = false;
	while (!exit)
	{
		switch (var_switch)
		{
		case 1:
			break;
		case 2:
			break;
		case 3:
			break;
		case 4:
			break;
		case 5:
			break;
		case 6:
			break;
		case 7:
			break;
		case 8:
			break;
		case 9:
			break;
		case 10:
			exit = true;
			break;
		default:
			break;
		}
	}
	return 0;
}

legal_service::legal_service()
{
	this->number = 0;
	this->category = 0;
	this->name_service = "";
	this->date = "";
	this->name_client = "";
	this->name_lawyer = "";
	this->price = 0;
}

legal_service::legal_service(int number, int category, string name_service, string date, string name_client, string name_lawyer, int price)
{
	this->number = number;
	this->category = category;
	this->name_service = name_service;
	this->date = date;
	this->name_client = name_client;
	this->name_lawyer = name_lawyer;
	this->price = price;
}

legal_service::~legal_service()
{
	this->number = 0;
	this->category = 0;
	this->name_service = "";
	this->date = "";
	this->name_client = "";
	this->name_lawyer = "";
	this->price = 0;
}
