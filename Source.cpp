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
	void print_data();
	void print_field();
	void print_field_mm();
	void find_field(vector<legal_service>& arr, int var, string data);
	void find_min(vector<legal_service>& arr, int var);
	void find_max(vector<legal_service>& arr, int var);
	void sort_field(vector<legal_service>& arr, int var);
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
	string data;
	bool exit = false;
	service.print_info();
	service.read_file(arr, path);
	while (!exit)
	{
		cout << "�������� ��������" << endl;
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
				service.write_file(arr, path);
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
			service.read_file(arr, path);
			cout << "������ ������� �������" << endl;
			break;
		case 5:
			if (arr.empty())
			{
				cout << "� ������� ��� ���������" << endl;
			}
			else
			{
				service.print_field();
				cout << "�������� ���� �� ������������" << endl;
				cin >> var;
				cout << "������� ������" << endl;
				cin >> data;
				service.find_field(arr, var, data);
			}
			break;
		case 6:
			if (arr.empty())
			{
				cout << "� ������� ��� ���������" << endl;
			}
			else
			{
				service.print_field_mm();
				cout << "�������� ����" << endl;
				cin >> var;
				service.find_min(arr, var);
			}
			break;
		case 7:
			if (arr.empty())
			{
				cout << "� ������� ��� ���������" << endl;
			}
			else
			{
				service.print_field_mm();
				cout << "�������� ����" << endl;
				cin >> var;
				service.find_max(arr, var);
			}
			break;
		case 8:
			if (arr.empty())
			{
				cout << "� ������� ��� ���������" << endl;
			}
			else
			{
				service.print_field();
				cout << "�������� ����" << endl;
				cin >> var;
				service.sort_field(arr, var);
				cout << "������ ������������" << endl;
			}
			break;
		case 9:
			if (arr.empty())
			{
				cout << "� ������� ��� ���������" << endl;
			}
			else
			{
				for (auto& el : arr)
				{
					el.print_data();
				}
			}
			break;
		case 10:
			exit = true;
			cout << "----------------------------------" << endl;
			cout << "��������� ���������" << endl;
			cout << "----------------------------------" << endl;
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
	cout << "------------------------------------------------------" << endl;
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
	cout << "------------------------------------------------------" << endl;
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
	legal_service obj;
	string data;
	int size = 0;
	file.open(path, fstream::in);
	arr.clear();
	if (file.is_open())
	{
		getline(file, data);
		size = stoi(data);
		for (int i = 0;i < size;i++)
		{
			getline(file, data);
			obj.number = stoi(data);
			getline(file, data);
			obj.category = stoi(data);
			getline(file, obj.name_service);
			getline(file, obj.date);
			getline(file, obj.name_client);
			getline(file, obj.name_lawyer);
			getline(file, data);
			obj.price = stoi(data);
			arr.push_back(obj);
		}
		file.close();
	}
	else
	{
		cout << "������ �������� �����" << endl;
	}
}

void legal_service::print_data()
{
	cout << "----------------------------------------------" << endl;
	cout << "������ ������ legal_service" << endl;
	cout << "����� ������ : " << number << endl;
	cout << "��������� ������ : " << category << endl;
	cout << "�������� ������ : " << name_service << endl;
	cout << "���� :" << date << endl;
	cout << "��� ������� : " << name_client << endl;
	cout << "��� ������ : " << name_lawyer << endl;
	cout << "��������� ������ : " << price << endl;
}

void legal_service::print_field()
{
	cout << "��������� ����" << endl;
	cout << "1 - ����� ������ " << endl;
	cout << "2 - ��������� ������" << endl;
	cout << "3 - �������� ������" << endl;
	cout << "4 - ����" << endl;
	cout << "5 - ��� �������" << endl;
	cout << "6 - ��� ������" << endl;
	cout << "7 - ��������� ������" << endl;
}

void legal_service::print_field_mm()
{
	cout << "��������� ����" << endl;
	cout << "1 - ����� ������" << endl;
	cout << "2 - ��������� ������" << endl;
	cout << "3 - ��������� ������" << endl;
}

void legal_service::find_field(vector<legal_service>& arr, int var, string data)
{
	for (auto& el : arr)
	{
		switch (var)
		{
		case 1:
			if (stoi(data) == el.number)
			{
				el.print_data();
			}
			break;
		case 2:
			if (stoi(data) == el.category)
			{
				el.print_data();
			}
			break;
		case 3:
			if (data == el.name_service)
			{
				el.print_data();
			}
			break;
		case 4:
			if (data == el.date)
			{
				el.print_data();
			}
			break;
		case 5:
			if (data == el.name_client)
			{
				el.print_data();
			}
			break;
		case 6:
			if (data == el.name_lawyer)
			{
				el.print_data();
			}
			break;
		case 7:
			if (stoi(data) == el.price)
			{
				el.print_data();
			}
			break;
		default:
			break;
		}
	}
}

void legal_service::find_min(vector<legal_service>& arr, int var)
{
	int min = 100000;
	if (var == 1)
	{
		for (auto& el : arr)
		{
			if (el.number < min)
			{
				min = el.number;
			}
		}
	}
	else if (var == 2)
	{
		for (auto& el : arr)
		{
			if (el.category < min)
			{
				min = el.category;
			}
		}
	}
	else if (var == 3)
	{
		for (auto& el : arr)
		{
			if (el.price < min)
			{
				min = el.price;
			}
		}
	}
	cout << "����������� ������� = " << min << endl;
}

void legal_service::find_max(vector<legal_service>& arr, int var)
{
	int max = 0;
	if (var == 1)
	{
		for (auto& el : arr)
		{
			if (el.number > max)
			{
				max = el.number;
			}
		}
	}
	else if (var == 2)
	{
		for (auto& el : arr)
		{
			if (el.category > max)
			{
				max = el.category;
			}
		}
	}
	else if (var == 3)
	{
		for (auto& el : arr)
		{
			if (el.price> max)
			{
				max = el.price;
			}
		}
	}
	cout << "������������ ������� = " << max << endl;
}

void legal_service::sort_field(vector<legal_service>& arr, int var)
{
	switch (var)
	{
	case 1:
		sort(arr.begin(), arr.end(), [](const legal_service& l1, const legal_service& l2) {return l1.number < l2.number;});
		break;
	case 2:
		sort(arr.begin(), arr.end(), [](const legal_service& l1, const legal_service& l2) {return l1.category < l2.category;});
		break;
	case 3:
		sort(arr.begin(), arr.end(), [](const legal_service& l1, const legal_service& l2) {return l1.name_service < l2.name_service;});
		break;
	case 4:
		sort(arr.begin(), arr.end(), [](const legal_service& l1, const legal_service& l2) {return l1.date < l2.date;});
		break;
	case 5:
		sort(arr.begin(), arr.end(), [](const legal_service& l1, const legal_service& l2) {return l1.name_client < l2.name_client;});
		break;
	case 6:
		sort(arr.begin(), arr.end(), [](const legal_service& l1, const legal_service& l2) {return l1.name_lawyer < l2.name_lawyer;});
		break;
	case 7:
		sort(arr.begin(), arr.end(), [](const legal_service& l1, const legal_service& l2) {return l1.price < l2.price;});
		break;
	default:
		cout << "�������� ���� ������" << endl;
		break;
	}
}
