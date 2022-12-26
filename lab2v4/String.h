#pragma once
#include <iostream>
#include <stdio.h>
#include <string>
#include <ctype.h>
#include <math.h>

using namespace std;

class String
{
protected:
	char* p;    // указатель на блок динамически выделенной памяти для размещения символов строки
	int lenght;    //длина строки

public:
	String();												// конструктор без параметров
	String(const char* str);								// конструктор, принимающий строку 
	String(char c);											// конструктор, принимающий char
	String(const String& other);							//коструктор копирования
	~String();												//деструктор

	char* GetChar();								//гетер символов строки
	int GetLenght();										// получение длины строки

	String operator=(const String& other);					//перегрузка оператора присваивания

};



class Identifier_String : public String
{
public:
	Identifier_String() : String() {}							//конструктор по умолчанию
	Identifier_String(const char* str);							//конструктор, принимающий строку
	Identifier_String(char c);									//конструктор, принимающий символ


	char GetLastChar();							//метод, возвращающий последнее вхождение в строку

	bool operator<=(const Identifier_String& other);
};


class Bit_String : public String
{
public:
	Bit_String() : String() {}									//конструктор по умолчанию
	Bit_String(const char* str);								//конструктор, принимающий строку
	Bit_String(char c);											//конструктор, принимающий символ


	void Reverse();												//метод замены знака
	bool operator>(const Bit_String& other);					//перегрузка >
};