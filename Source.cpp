#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;
class legal_service
{
public:
	legal_service();
	legal_service(int number, int category, string name_service, string date, string name_client, string name_lawyer, int price);
	~legal_service();
	void print_info();
	void set_Data();
	void write_file(vector<legal_service>& arr, string path);
	void read_file(vector<legal_service>& arr, string path);
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
	int var_switch, count, var;
	var = count = var_switch = 0;
	string path = "data.txt";
	bool exit = false;
	service.print_info();
	while (!exit)
	{
		cin >> var_switch;
		switch (var_switch)
		{
		case 1:
			service.set_Data();
			arr.push_back(service);
			cout << "Объект создан" << endl;
			break;
		case 2:
			if (arr.empty())
			{
				cout << "В векторе нет элементов" << endl;
			}
			else
			{
				count = 0;
				cout << "Выберите элемент из доступных:" << endl;
				for (auto& el : arr)
				{
					cout << "Номер - " << count << endl;
					count++;
				}
				cin >> var;
				arr.erase(arr.begin() + var);
				cout << "Объект удален" << endl;
			}
			break;
		case 3:
			if (arr.empty())
			{
				cout << "В векторе нет элементов" << endl;
			}
			else
			{
				service.write_file(arr, path);
				cout << "Данные записаны в файл" << endl;
			}
			break;
		case 4:
			break;
		case 5:
			if (arr.empty())
			{
				cout << "В векторе нет элементов" << endl;
			}
			else
			{

			}
			break;
		case 6:
			if (arr.empty())
			{
				cout << "В векторе нет элементов" << endl;
			}
			else
			{

			}
			break;
		case 7:
			if (arr.empty())
			{
				cout << "В векторе нет элементов" << endl;
			}
			else
			{

			}
			break;
		case 8:
			if (arr.empty())
			{
				cout << "В векторе нет элементов" << endl;
			}
			else
			{

			}
			break;
		case 9:
			if (arr.empty())
			{
				cout << "В векторе нет элементов" << endl;
			}
			else
			{

			}
			break;
		case 10:
			exit = true;
			break;
		default:
			cout << "Такого режима нет" << endl;
			service.print_info();
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

void legal_service::print_info()
{
	cout << "Доступные режимы:" << endl;
	cout << "1 - Ввод данных" << endl;
	cout << "2 - Удаление объекта" << endl;
	cout << "3 - Сохранение данных в файл" << endl;
	cout << "4 - Чтение данных из файла" << endl;
	cout << "5 - Поиск данных по полям" << endl;
	cout << "6 - Поиск минимального элемента" << endl;
	cout << "7 - Поиск максимального элемента" << endl;
	cout << "8 - Сортировка по полям" << endl;
	cout << "9 - Вывод данных" << endl;
	cout << "10 - Выход" << endl;
}

void legal_service::set_Data()
{
	string first_name, second_name, third_name;
	cout << "Введите номер услуги" << endl;
	cin >> number;
	cout << "Введите категорию услуги" << endl;
	cin >> category;
	cout << "Введите название услуги" << endl;
	cin >> name_service;
	cout << "Введите дату" << endl;
	cin >> date;
	cout << "Введите фамалию клиента" << endl;
	cin >> first_name;
	cout << "Введите имя клиента" << endl;
	cin >> second_name;
	cout << "Введите отчество клиента" << endl;
	cin >> third_name;
	name_client = first_name + " " + second_name + " " + third_name;
	cout << "Введите фамалию юриста" << endl;
	cin >> first_name;
	cout << "Введите имя юриста" << endl;
	cin >> second_name;
	cout << "Введите отчество юриста" << endl;
	cin >> third_name;
	name_lawyer = first_name + " " + second_name + " " + third_name;
	cout << "Введите стоимость услуги" << endl;
	cin >> price;
}

void legal_service::write_file(vector<legal_service>& arr, string path)
{
	fstream file;
	file.open(path, fstream::out);
	if (file.is_open())
	{
		file.clear();
		file << arr.size() << "\n";
		for (auto& el : arr)
		{
			file << el.number << "\n";
			file << el.category << "\n";
			file << el.name_service << "\n";
			file << el.date << "\n";
			file << el.name_client << "\n";
			file << el.name_lawyer << "\n";
			file << el.price << "\n";
		}
		file.close();
	}
	else
	{
		cout << "Ошибка открытия файла" << endl;
	}
}

void legal_service::read_file(vector<legal_service>& arr, string path)
{
	fstream file;
	string data;
	int size = 0;
	file.open(path, fstream::in);
	if (file.is_open())
	{
		getline(file, data);
	}
	else
	{
		cout << "Ошибка открытия файла" << endl;
	}
}
