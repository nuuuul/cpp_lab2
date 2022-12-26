#include "String.h"



//функция создания строки
char* GetString()
{
	int size;												//создаем переменную для размера строки
	cout << "Введите размер строки" << endl;				//просим ввести size
	cin >> size;											//записываем size
	size++;													//увеличиваем для \0
	getchar();												//
	char* string = new char[size];							//создаем строку
	cout << "Введите значение строки" << endl;				//просим ввести значение
	cin.getline(string, size);								//записываем данные в строку
	return string;											//возвращаем строку
}




int main()
{
	setlocale(LC_ALL, "rus");

	//создаем 2 объекта разных классов для пророк перегрузок
	Identifier_String id_str;
	Bit_String bit_str;


	int amount = 4;												//создаем переменную для обозначения кол-ва эл-ов массива указателей на базовый класс

	while (amount > 0)
	{
		system("cls");
		cout << "Введите количество элементов" << endl;
		cin >> amount;											//читает кол-во эл-ов
		String** strings = new String * [amount];				//создаем динамический массив указателей на базовый класс

		for (int i = 0; i < amount; i++)						//создаем цикл для создания и последующего тестирования объектов массива
		{
			cout << "Строка  " << i + 1 << "\n    Выберите тип строки:\n1.Строка\n2.Строка-идентификатор"
				"\n3.Битовая строка\n" << endl;
			int choice, choice_methods = 1;						//choice - переменная для выбора типа, choice_methods - переменная для выбора метода
			cin >> choice;										//считываем выбор типа
			switch (choice)										//создаем switch для меню
			{
			case 1:												//случай String
				strings[i] = new String(GetString());				//записываем в указатель объект класса String
				system("PAUSE");
				while (choice_methods > 0 && choice_methods < 3)	//создаем цикл для тестирования
				{
					system("cls");							//чистим консоль
					cout << "Тестирование\n" <<
						"1.Вернуть строку\n" <<
						"2.Вернуть количество элеметнов строки\n" <<
						"0.Выйти\n" << endl;

					cin >> choice_methods;
					switch (choice_methods)
					{
					case 1:
						cout << strings[i]->GetChar() << endl;
						break;
					case 2:
						cout << strings[i]->GetLenght() << endl;
						break;
					}
					system("PAUSE");
				}
				break;

			case 2:
				strings[i] = new Identifier_String(GetString());
				system("PAUSE");
				while (choice_methods > 0 && choice_methods < 6)
				{
					system("cls");
					cout << "Тестирование\n" <<
						"1.Вернуть строку\n" <<
						"2.Вернуть количество элеметнов строки\n" <<
						"3.Вернуть последнее вхождение строки\n" <<
						"4.Проверка на <=\n" <<
						"0.Выйти\n" << endl;

					cin >> choice_methods;
					switch (choice_methods)
					{
					case 1:
						cout << strings[i]->GetChar() << endl;
						break;

					case 2:
						cout << strings[i]->GetLenght() << endl;
						break;

					case 3:
						cout << static_cast<Identifier_String*>(strings[i])->GetLastChar() << endl;
						break;

					case 4:
						id_str = GetString();
						if (static_cast<Identifier_String*>(strings[i])->operator<=(id_str))
							cout << "<=" << endl;
						else
							cout << ">" << endl;
						break;

					}
					system("PAUSE");
				}
				break;

			case 3:
				strings[i] = new Bit_String(GetString());
				system("PAUSE");
				while (choice_methods > 0 && choice_methods < 6)
				{
					system("cls");
					cout << "Тестирование\n" <<
						"1.Вернуть число\n" <<
						"2.Вернуть количество элеметнов строки\n" <<
						"3.Изменить знак битового числа\n" <<
						"4.Перегрузка >\n" <<
						"0.Выйти" << endl;

					cin >> choice_methods;
					switch (choice_methods)
					{
					case 1:
						cout << strings[i]->GetChar() << endl;
						break;

					case 2:
						cout << strings[i]->GetLenght() << endl;
						break;

					case 3:
						static_cast<Bit_String*>(strings[i])->Reverse();
						cout << strings[i]->GetChar() << endl;
						break;

					case 4:
						bit_str = GetString();
						if (static_cast<Bit_String*>(strings[i])->operator>(bit_str))
							cout << ">" << endl;
						else
							cout << "<=" << endl;
						break;
					}
					system("PAUSE");
				}
				break;

			default:
				i--;
				cout << "Некорректный выбор" << endl;
				break;
			}
			system("cls");
		}


		//чистим память, выделенную для массива указателей на базовый класс
		for (int i = 0; i < amount; i++)
			delete strings[i];
		system("PAUSE");
	}
}