#include <iostream>
#include <cstring>
#include "Account.h"
#include "Exception.h"

using namespace std;

Account::Account(const char * name, int number, int money) : accountNumber(number), money(money)
{
	username = new char[strlen(name) + 1];
	strcpy_s(username, strlen(name) + 1, name);
}
void Account::Show() const
{
	cout << "�̸� : " << username << endl;
	cout << "���� ��ȣ: " << accountNumber << endl;
	cout << "�ܾ�: " << money << endl;
}
int Account::getNumber() const
{
	return accountNumber;
}
void Account::addMoney(int depositM)
{
	if (depositM <= 0)
		throw Error();
	money += depositM;
}
void Account::minMoney(int withdrawM)
{
	if (withdrawM > money)
	{
		cout << "������ �ݾ��� �����մϴ�. \n";
		throw Error();
	}
	if (withdrawM <= 0)
		throw Error();
	money -= withdrawM;
}
Account::~Account()
{
	delete[] username;
}