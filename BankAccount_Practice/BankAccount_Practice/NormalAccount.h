#ifndef __NORMAL_ACCOUNT_H__
#define __NORMAL_ACCOUNT_H__

#include "Account.h"
#include <iostream>
using namespace std;

class NormalAccount : public Account
{
	double baseInterest;
public:
	NormalAccount(const char * name, int number, int money) : Account(name, number, money)
	{
		baseInterest = 0.02;
	}
	virtual void addMoney(int depositM)
	{
		Account::addMoney(depositM);
		int interest = (int)(depositM * baseInterest);
		Account::addMoney(interest);
	}
	virtual void Show() const
	{
		Account::Show();
		cout << "°èÁÂ Á¾·ù: ÀÏ¹Ý °èÁÂ" << endl << endl;
	}
};


#endif