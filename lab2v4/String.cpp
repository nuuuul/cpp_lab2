#define _CRT_SECURE_NO_WARNINGS
#include "String.h"

// конструктор без параметров
String::String() :
	p(nullptr), lenght(0)
{
	cout << "Вызван конструктор по умолчанию |String" << endl;
}

// конструктор, принимающий строку 
String::String(const char* str)
{
	cout << "Вызван конструктор, принимающий строку |String" << endl;
	if (str == nullptr)
	{
		cout << "Передача пустой строки" << endl;
		lenght = 0;
		p = nullptr;
		return;
	}
	lenght = strlen(str);
	p = new char[lenght + 1];	//веделение доп. памяти для \0
	strcpy(p, str);
}

// конструктор, принимающий char
String::String(char c)
{
	cout << "Вызван конструктор, принимающий символ |String" << endl;
	p = new char[2];
	p[0] = c;
	p[1] = '\0';
	lenght = 2;
}

//коструктор копирования
String::String(const String& other) : String(other.p)
{}

//гетер символов строки
char* String::GetChar()
{
	cout << "Вызван метод возвращения символов |String" << endl;
	return p;
}

//метод возвращения длины
int String::GetLenght()
{
	cout << "Вызван метод возвращения длины |String" << endl;
	return lenght;
}


//деструктор
String::~String()
{
	cout << "Вызван деструктор" << endl;
	delete[] p;
	p = nullptr;
	lenght = 0;
}

//перегрузка оператора присваивания
String String::operator=(const String& other)
{
	cout << "Вызвана перегрузка оператора =" << endl;
	delete[] p;
	p = new char[other.lenght + 1];
	lenght = other.lenght;
	strcpy(p, other.p);
	return  (*this);
}







//конструктор, принимающий строку
Identifier_String::Identifier_String(const char* str)
{
	cout << "Вызван конструктор, принимающий строку |Identifier_String" << endl;
	if (isalpha(str[0]) == 0 && str[0] != '_')
	{
		cout << "Error:\t некорректная строка-идентифитатор\nСоздалась пустая строка-идентификатор" << endl;
		return;
	}
	int i;
	for (i = 1; i < strlen(str); i++)
	{
		if (!isalpha(str[i]) && str[i] != '_')
		{
			cout << "Error:\t некорректная строка-идентифитатор\nСоздалась пустая строка-идентификатор" << endl;
			return;
		}

	}
	lenght = strlen(str);
	p = new char[lenght + 1];
	strcpy(p, str);
}

//конструктор, принимающий символ
Identifier_String::Identifier_String(char c)
{
	cout << "Вызван конструктор, принимающий символ\tIdentifier_String" << endl;
	if (isalpha(c) && c != '_')
	{
		cout << "Некорректная строка-идентифитатор\nСоздалась пустая строка-идентификатор" << endl;
		return;
	}
	p = new char[2];
	p[0] = c;
	p[1] = '\0';
	lenght = 2;

}

//метод, возвращающий последнее вхождение в строку
char Identifier_String::GetLastChar()
{
	cout << "Вызван метод, возвращающий последнее вхождение в строку | Identifier_String" << endl;
	if (p != nullptr)
		return p[this->lenght - 1];
	return false;
}

//перегрузка оператора <=
bool Identifier_String::operator<=(const Identifier_String& other)
{
	cout << "Вызвана перегрузка оператора <=\tIdentifier_String" << endl;
	return (this->lenght < other.lenght || this->lenght == other.lenght);
}








//конструктор, принимающий строку
Bit_String::Bit_String(const char* str)
{
	cout << "Вызван конструктор, принимающий строку |Bit_String" << endl;

	int i;
	for (i = 0; i < strlen(str); i++)
	{
		if (str[i] != '1' && str[i] != '0')
		{
			cout << "Error" << endl;
			lenght = 0;
			p = nullptr;
			return;
		}
	}
	lenght = i;
	p = new char[lenght + 1];
	strcpy(p, str);
}


//метод замены знака числа
void Bit_String::Reverse()
{
	cout << "Вызван метод *(-1) <=\tBit_String" << endl;
	if (p[0] == '1')
		p[0] = '0';
	else
		p[0] = '1';
}

//перегрузка >
bool Bit_String::operator>(const Bit_String& other)
{
	cout << "Вызвана перегрузка оператора >\tBit_String" << endl;
	if (this->p[0] == '0' && other.p[0] == '1')
		return true;
	else if (this->p[0] == '1' && other.p[0] == '0')
		return false;

	if (this->p[0] == '0' && other.p[0] == '0')
		return(this->p > other.p);
	return (other.p > this->p);
}