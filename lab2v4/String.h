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
	char* p;    // ��������� �� ���� ����������� ���������� ������ ��� ���������� �������� ������
	int lenght;    //����� ������

public:
	String();												// ����������� ��� ����������
	String(const char* str);								// �����������, ����������� ������ 
	String(char c);											// �����������, ����������� char
	String(const String& other);							//���������� �����������
	~String();												//����������

	char* GetChar();								//����� �������� ������
	int GetLenght();										// ��������� ����� ������

	String operator=(const String& other);					//���������� ��������� ������������

};



class Identifier_String : public String
{
public:
	Identifier_String() : String() {}							//����������� �� ���������
	Identifier_String(const char* str);							//�����������, ����������� ������
	Identifier_String(char c);									//�����������, ����������� ������


	char GetLastChar();							//�����, ������������ ��������� ��������� � ������

	bool operator<=(const Identifier_String& other);
};


class Bit_String : public String
{
public:
	Bit_String() : String() {}									//����������� �� ���������
	Bit_String(const char* str);								//�����������, ����������� ������
	Bit_String(char c);											//�����������, ����������� ������


	void Reverse();												//����� ������ �����
	bool operator>(const Bit_String& other);					//���������� >
};