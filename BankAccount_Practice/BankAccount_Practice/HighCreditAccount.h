#ifndef __HIGH_CREDIT_ACCOUNT_H__
#define __HIGH_CREDIT_ACCOUNT_H__

#include "NormalAccount.h"
#include <iostream>
using namespace std;

class HighAccount : public NormalAccount
{
	double bonusInterest;
public:
	HighAccount(const char * name, int number, int money, int bonus) 
		: NormalAccount(name, number, money)
	{
		bonusInterest = (double)bonus/100;
	}
	virtual void addMoney(int depositM)
	{
		NormalAccount::addMoney(depositM);
		int interest = (int)(depositM*bonusInterest);
		Account::addMoney(interest);
	}
	virtual void Show() const
	{
		Account::Show();
		cout << "°èÁÂ Á¾·ù: ¿ì´ë °èÁÂ" << endl<<endl;
	}
};

#endif