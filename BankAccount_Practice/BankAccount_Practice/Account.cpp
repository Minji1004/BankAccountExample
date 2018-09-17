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
	cout << "이름 : " << username << endl;
	cout << "계좌 번호: " << accountNumber << endl;
	cout << "잔액: " << money << endl;
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
		cout << "인출할 금액이 부족합니다. \n";
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