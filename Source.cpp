//объявление библиотек
#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;//использование пространства имен
class legal_service
{
public:
	legal_service();//конструктор по умолчанию
	legal_service(int number, int category, string name_service, string date, string name_client, string name_lawyer, int price);//конструктор с параметрами
	~legal_service();//деструктор
	void print_info();//вывод информации о консольном меню
	void set_Data();//ввод полей класса 
	void write_file(vector<legal_service>& arr, string path);//запись в файл
	void read_file(vector<legal_service>& arr, string path);//чтение из файла
	void print_data();//вывод данных полей
	void print_field();//вывод доступных полей
	void print_field_mm();//вывод доступных полей для нахождения максимума и минимума
	void find_field(vector<legal_service>& arr, int var, string data);//поиск данных по полям
	void find_min(vector<legal_service>& arr, int var);//поиск минимального элемента
	void find_max(vector<legal_service>& arr, int var);//поиск максимального элемента
	void sort_field(vector<legal_service>& arr, int var);//сортировка по полю
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
	legal_service service;//создание объекта
	vector<legal_service> arr;//создание вектора объектов
	//объявление переменных
	int var_switch, count, var;
	var = count = var_switch = 0;
	string path = "data.txt";
	string data;
	bool exit = false;
	service.print_info();//вывод информации о меню
	service.read_file(arr, path);//чтение данных из файла
	while (!exit)
	{
		cout << "Выберите действие" << endl;
		cin >> var_switch;//навигация по консольному меню
		switch (var_switch)//консольное меню
		{
		case 1://режим 1
			service.set_Data();//ввод данных
			arr.push_back(service);//добавление объекта в вектор
			cout << "Объект создан" << endl;
			break;
		case 2://режим 2
			if (arr.empty())//проверка вектора на пустоту
			{
				cout << "В векторе нет элементов" << endl;
			}
			else
			{
				count = 0;
				cout << "Выберите элемент из доступных:" << endl;
				for (auto& el : arr)//вывод номеров доступных объектов
				{
					cout << "Номер - " << count << endl;
					count++;
				}
				cin >> var;//ввод элемента для удаления
				arr.erase(arr.begin() + var);//удаление элемента
				service.write_file(arr, path);//запись в файл
				cout << "Объект удален" << endl;
			}
			break;
		case 3://режим 3
			service.write_file(arr, path);//запись в файл
			cout << "Данные записаны в файл" << endl;
			break;
		case 4://режим 4
			service.read_file(arr, path);//чтение данных из файла
			cout << "Данные успешно считаны" << endl;
			break;
		case 5://режим 5
			if (arr.empty())//проверка вектора на пустоту
			{
				cout << "В векторе нет элементов" << endl;
			}
			else
			{
				service.print_field();//вывод доступных полей
				cout << "Выберите поле из предложенных" << endl;
				cin >> var;//ввод поля
				cout << "Введите данные" << endl;
				cin >> data;//ввод данных
				service.find_field(arr, var, data);//поиск данных по полю
			}
			break;
		case 6://режим 6
			if (arr.empty())//проверка вектора на пустоту
			{
				cout << "В векторе нет элементов" << endl;
			}
			else
			{
				service.print_field_mm();//вывод полей доступых для нахождения максимума и минимума
				cout << "Выберите поле" << endl;
				cin >> var;//выбор поля
				service.find_min(arr, var);//нахождение минимального элемента
			}
			break;
		case 7://режим 7
			if (arr.empty())//проверка вектора на пустоту
			{
				cout << "В векторе нет элементов" << endl;
			}
			else
			{
				service.print_field_mm();//вывод полей доступных для находения максимума и минимума
				cout << "Выберите поле" << endl;
				cin >> var;//выбор поля
				service.find_max(arr, var);//нахождение максимального
			}
			break;
		case 8://режим 8
			if (arr.empty())//проверка вектора на пустоту
			{
				cout << "В векторе нет элементов" << endl;
			}
			else
			{
				service.print_field();//вывод доступных полей
				cout << "Выберите поле" << endl;
				cin >> var;//выбор поля
				service.sort_field(arr, var);//сортировка поля
				cout << "Вектор отсортирован" << endl;
			}
			break;
		case 9://режим 9
			if (arr.empty())//проверка вектора на пустоту
			{
				cout << "В векторе нет элементов" << endl;
			}
			else
			{
				for (auto& el : arr)//цикл фор ич
				{
					el.print_data();//вывод полей объектов
				}
			}
			break;
		case 10://режим 10
			exit = true;//выход из программы
			cout << "----------------------------------" << endl;
			cout << "Программа завершена" << endl;
			cout << "----------------------------------" << endl;
			break;
		default://на случай некоректного ввода
			cout << "Такого режима нет" << endl;
			service.print_info();//вывод информации о меню
			break;
		}
	}
	return 0;
}

legal_service::legal_service()//конструктор по умолчанию
{
	//заполнение полей данными
	this->number = 0;
	this->category = 0;
	this->name_service = "";
	this->date = "";
	this->name_client = "";
	this->name_lawyer = "";
	this->price = 0;
}

legal_service::legal_service(int number, int category, string name_service, string date, string name_client, string name_lawyer, int price)//конструктор с параметрами
{
	//заполнение полей введенными данными
	this->number = number;
	this->category = category;
	this->name_service = name_service;
	this->date = date;
	this->name_client = name_client;
	this->name_lawyer = name_lawyer;
	this->price = price;
}

legal_service::~legal_service()//деструктор
{
	this->number = 0;
	this->category = 0;
	this->name_service = "";
	this->date = "";
	this->name_client = "";
	this->name_lawyer = "";
	this->price = 0;
}

void legal_service::print_info()//вывод информации о консольном меню
{
	cout << "------------------------------------------------------" << endl;
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
	cout << "------------------------------------------------------" << endl;
}

void legal_service::set_Data()//ввод даннных
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

void legal_service::write_file(vector<legal_service>& arr, string path)//запись данных в файл
{
	fstream file;
	file.open(path, fstream::out);//открытие файла
	if (file.is_open())//проверка открытия файла
	{
		file.clear();//очистка файла
		file << arr.size() << "\n";//запись размера вектора
		for (auto& el : arr)//цикл фор ич
		{
			//запись данных в файл
			file << el.number << "\n";
			file << el.category << "\n";
			file << el.name_service << "\n";
			file << el.date << "\n";
			file << el.name_client << "\n";
			file << el.name_lawyer << "\n";
			file << el.price << "\n";
		}
		file.close();//закртыие файла
	}
	else
	{
		cout << "Ошибка открытия файла" << endl;
	}
}

void legal_service::read_file(vector<legal_service>& arr, string path)//чтение данных из файла
{
	//объявление переменных
	fstream file;
	legal_service obj;
	string data;
	int size = 0;
	file.open(path, fstream::in);//открытие файла
	arr.clear();//очистка вектора
	if (file.is_open())//проверка открытия файла
	{
		getline(file, data);
		size = stoi(data);//считывание количество объектов файла
		for (int i = 0;i < size;i++)
		{
			//считывания данных
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
			arr.push_back(obj);//добавление объекта в вектор
		}
		file.close();//закрытие файла
	}
	else
	{
		cout << "Ошибка открытия файла" << endl;
	}
}

void legal_service::print_data()//вывод данных полей
{
	cout << "----------------------------------------------" << endl;
	cout << "Объект класса legal_service" << endl;
	cout << "Номер услуги : " << number << endl;
	cout << "Категория услуги : " << category << endl;
	cout << "Название услуги : " << name_service << endl;
	cout << "Дата :" << date << endl;
	cout << "ФИО клиента : " << name_client << endl;
	cout << "ФИО юриста : " << name_lawyer << endl;
	cout << "Стоимость услуги : " << price << endl;
}

void legal_service::print_field()//вывод доступных полей
{
	cout << "Доступные поля" << endl;
	cout << "1 - Номер услуги " << endl;
	cout << "2 - Категория услуги" << endl;
	cout << "3 - Название услуги" << endl;
	cout << "4 - Дата" << endl;
	cout << "5 - ФИО клиента" << endl;
	cout << "6 - ФИО юриста" << endl;
	cout << "7 - Стоимость услуги" << endl;
}

void legal_service::print_field_mm()//вывод полей доступных для нахождения максимума и минимума
{
	cout << "Доступные поля" << endl;
	cout << "1 - Номер услуги" << endl;
	cout << "2 - Категория услуги" << endl;
	cout << "3 - Стоимость услуги" << endl;
}

void legal_service::find_field(vector<legal_service>& arr, int var, string data)//поиск данных по полям
{
	for (auto& el : arr)//цикл фор ич
	{
		switch (var)//поиск по полю
		{
		case 1:
			if (stoi(data) == el.number)//проверка данных
			{
				el.print_data();//печать полей найденного объекта
			}
			break;
		case 2:
			if (stoi(data) == el.category)//проверка данных
			{
				el.print_data();//печать полей найденного объекта
			}
			break;
		case 3:
			if (data == el.name_service)//проверка данных
			{
				el.print_data();//печать полей найденного объекта
			}
			break;
		case 4:
			if (data == el.date)//проверка данных
			{
				el.print_data();//печать полей найденного объекта
			}
			break;
		case 5:
			if (data == el.name_client)//проверка данных
			{
				el.print_data();//печать полей найденного объекта
			}
			break;
		case 6:
			if (data == el.name_lawyer)//проверка данных
			{
				el.print_data();//печать полей найденного объекта
			}
			break;
		case 7:
			if (stoi(data) == el.price)//проверка данных
			{
				el.print_data();//печать полей найденного объекта
			}
			break;
		default:
			cout << "Неверный ввод" << endl;
			break;
		}
	}
}

void legal_service::find_min(vector<legal_service>& arr, int var)//поиск минимального элемента
{
	int min = 100000;
	if (var == 1)
	{
		for (auto& el : arr)//цикл фор ич
		{
			if (el.number < min)//определение минимального
			{
				min = el.number;
			}
		}
	}
	else if (var == 2)
	{
		for (auto& el : arr)//цикл фор ич
		{
			if (el.category < min)//определение минимального
			{
				min = el.category;
			}
		}
	}
	else if (var == 3)
	{
		for (auto& el : arr)//цикл фор ич
		{
			if (el.price < min)//определение минимального
			{
				min = el.price;
			}
		}
	}
	cout << "Минимальный элемент = " << min << endl;
}

void legal_service::find_max(vector<legal_service>& arr, int var)
{
	int max = 0;
	if (var == 1)
	{
		for (auto& el : arr)//цикл фор ич
		{
			if (el.number > max)//определение максимального
			{
				max = el.number;
			}
		}
	}
	else if (var == 2)
	{
		for (auto& el : arr)//цикл фор ич
		{
			if (el.category > max)//определение максимального
			{
				max = el.category;
			}
		}
	}
	else if (var == 3)//цикл фор ич
	{
		for (auto& el : arr)
		{
			if (el.price> max)//определение максимального
			{
				max = el.price;
			}
		}
	}
	cout << "Максимальный элемент = " << max << endl;
}

void legal_service::sort_field(vector<legal_service>& arr, int var)//сортировка по полю
{
	switch (var)
	{
	case 1:
		sort(arr.begin(), arr.end(), [](const legal_service& l1, const legal_service& l2) {return l1.number < l2.number;});//сортировка
		break;
	case 2:
		sort(arr.begin(), arr.end(), [](const legal_service& l1, const legal_service& l2) {return l1.category < l2.category;});//сортировка
		break;
	case 3:
		sort(arr.begin(), arr.end(), [](const legal_service& l1, const legal_service& l2) {return l1.name_service < l2.name_service;});//сортировка
		break;
	case 4:
		sort(arr.begin(), arr.end(), [](const legal_service& l1, const legal_service& l2) {return l1.date < l2.date;});//сортировка
		break;
	case 5:
		sort(arr.begin(), arr.end(), [](const legal_service& l1, const legal_service& l2) {return l1.name_client < l2.name_client;});//сортировка
		break;
	case 6:
		sort(arr.begin(), arr.end(), [](const legal_service& l1, const legal_service& l2) {return l1.name_lawyer < l2.name_lawyer;});//сортировка
		break;
	case 7:
		sort(arr.begin(), arr.end(), [](const legal_service& l1, const legal_service& l2) {return l1.price < l2.price;});//сортировка
		break;
	default:
		cout << "Неверный ввод данных" << endl;
		break;
	}
}
