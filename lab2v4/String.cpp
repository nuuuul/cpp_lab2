#define _CRT_SECURE_NO_WARNINGS
#include "String.h"

// ����������� ��� ����������
String::String() :
	p(nullptr), lenght(0)
{
	cout << "������ ����������� �� ��������� |String" << endl;
}

// �����������, ����������� ������ 
String::String(const char* str)
{
	cout << "������ �����������, ����������� ������ |String" << endl;
	if (str == nullptr)
	{
		cout << "�������� ������ ������" << endl;
		lenght = 0;
		p = nullptr;
		return;
	}
	lenght = strlen(str);
	p = new char[lenght + 1];	//��������� ���. ������ ��� \0
	strcpy(p, str);
}

// �����������, ����������� char
String::String(char c)
{
	cout << "������ �����������, ����������� ������ |String" << endl;
	p = new char[2];
	p[0] = c;
	p[1] = '\0';
	lenght = 2;
}

//���������� �����������
String::String(const String& other) : String(other.p)
{}

//����� �������� ������
char* String::GetChar()
{
	cout << "������ ����� ����������� �������� |String" << endl;
	return p;
}

//����� ����������� �����
int String::GetLenght()
{
	cout << "������ ����� ����������� ����� |String" << endl;
	return lenght;
}


//����������
String::~String()
{
	cout << "������ ����������" << endl;
	delete[] p;
	p = nullptr;
	lenght = 0;
}

//���������� ��������� ������������
String String::operator=(const String& other)
{
	cout << "������� ���������� ��������� =" << endl;
	delete[] p;
	p = new char[other.lenght + 1];
	lenght = other.lenght;
	strcpy(p, other.p);
	return  (*this);
}







//�����������, ����������� ������
Identifier_String::Identifier_String(const char* str)
{
	cout << "������ �����������, ����������� ������ |Identifier_String" << endl;
	if (isalpha(str[0]) == 0 && str[0] != '_')
	{
		cout << "Error:\t ������������ ������-�������������\n��������� ������ ������-�������������" << endl;
		return;
	}
	int i;
	for (i = 1; i < strlen(str); i++)
	{
		if (!isalpha(str[i]) && str[i] != '_')
		{
			cout << "Error:\t ������������ ������-�������������\n��������� ������ ������-�������������" << endl;
			return;
		}

	}
	lenght = strlen(str);
	p = new char[lenght + 1];
	strcpy(p, str);
}

//�����������, ����������� ������
Identifier_String::Identifier_String(char c)
{
	cout << "������ �����������, ����������� ������\tIdentifier_String" << endl;
	if (isalpha(c) && c != '_')
	{
		cout << "������������ ������-�������������\n��������� ������ ������-�������������" << endl;
		return;
	}
	p = new char[2];
	p[0] = c;
	p[1] = '\0';
	lenght = 2;

}

//�����, ������������ ��������� ��������� � ������
char Identifier_String::GetLastChar()
{
	cout << "������ �����, ������������ ��������� ��������� � ������ | Identifier_String" << endl;
	if (p != nullptr)
		return p[this->lenght - 1];
	return false;
}

//���������� ��������� <=
bool Identifier_String::operator<=(const Identifier_String& other)
{
	cout << "������� ���������� ��������� <=\tIdentifier_String" << endl;
	return (this->lenght < other.lenght || this->lenght == other.lenght);
}








//�����������, ����������� ������
Bit_String::Bit_String(const char* str)
{
	cout << "������ �����������, ����������� ������ |Bit_String" << endl;

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


//����� ������ ����� �����
void Bit_String::Reverse()
{
	cout << "������ ����� *(-1) <=\tBit_String" << endl;
	if (p[0] == '1')
		p[0] = '0';
	else
		p[0] = '1';
}

//���������� >
bool Bit_String::operator>(const Bit_String& other)
{
	cout << "������� ���������� ��������� >\tBit_String" << endl;
	if (this->p[0] == '0' && other.p[0] == '1')
		return true;
	else if (this->p[0] == '1' && other.p[0] == '0')
		return false;

	if (this->p[0] == '0' && other.p[0] == '0')
		return(this->p > other.p);
	return (other.p > this->p);
}