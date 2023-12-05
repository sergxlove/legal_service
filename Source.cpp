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
	int number;//����� ������
	int category;//��������� ������
	string name_service;//�������� ������
	string date;//����
	string name_client;//��� �������
	string name_lawyer;//��� ������
	int price;//���������
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
			cout << "������ ������" << endl;
			break;
		case 2:
			if (arr.empty())
			{
				cout << "� ������� ��� ���������" << endl;
			}
			else
			{
				count = 0;
				cout << "�������� ������� �� ���������:" << endl;
				for (auto& el : arr)
				{
					cout << "����� - " << count << endl;
					count++;
				}
				cin >> var;
				arr.erase(arr.begin() + var);
				cout << "������ ������" << endl;
			}
			break;
		case 3:
			if (arr.empty())
			{
				cout << "� ������� ��� ���������" << endl;
			}
			else
			{
				service.write_file(arr, path);
				cout << "������ �������� � ����" << endl;
			}
			break;
		case 4:
			break;
		case 5:
			if (arr.empty())
			{
				cout << "� ������� ��� ���������" << endl;
			}
			else
			{

			}
			break;
		case 6:
			if (arr.empty())
			{
				cout << "� ������� ��� ���������" << endl;
			}
			else
			{

			}
			break;
		case 7:
			if (arr.empty())
			{
				cout << "� ������� ��� ���������" << endl;
			}
			else
			{

			}
			break;
		case 8:
			if (arr.empty())
			{
				cout << "� ������� ��� ���������" << endl;
			}
			else
			{

			}
			break;
		case 9:
			if (arr.empty())
			{
				cout << "� ������� ��� ���������" << endl;
			}
			else
			{

			}
			break;
		case 10:
			exit = true;
			break;
		default:
			cout << "������ ������ ���" << endl;
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
	cout << "��������� ������:" << endl;
	cout << "1 - ���� ������" << endl;
	cout << "2 - �������� �������" << endl;
	cout << "3 - ���������� ������ � ����" << endl;
	cout << "4 - ������ ������ �� �����" << endl;
	cout << "5 - ����� ������ �� �����" << endl;
	cout << "6 - ����� ������������ ��������" << endl;
	cout << "7 - ����� ������������� ��������" << endl;
	cout << "8 - ���������� �� �����" << endl;
	cout << "9 - ����� ������" << endl;
	cout << "10 - �����" << endl;
}

void legal_service::set_Data()
{
	string first_name, second_name, third_name;
	cout << "������� ����� ������" << endl;
	cin >> number;
	cout << "������� ��������� ������" << endl;
	cin >> category;
	cout << "������� �������� ������" << endl;
	cin >> name_service;
	cout << "������� ����" << endl;
	cin >> date;
	cout << "������� ������� �������" << endl;
	cin >> first_name;
	cout << "������� ��� �������" << endl;
	cin >> second_name;
	cout << "������� �������� �������" << endl;
	cin >> third_name;
	name_client = first_name + " " + second_name + " " + third_name;
	cout << "������� ������� ������" << endl;
	cin >> first_name;
	cout << "������� ��� ������" << endl;
	cin >> second_name;
	cout << "������� �������� ������" << endl;
	cin >> third_name;
	name_lawyer = first_name + " " + second_name + " " + third_name;
	cout << "������� ��������� ������" << endl;
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
		cout << "������ �������� �����" << endl;
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
		cout << "������ �������� �����" << endl;
	}
}
