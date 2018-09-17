#ifndef __ACCOUNT_LIST_H__
#define __ACCOUNT_LIST_H__

#include "Account.h"
#include "NormalAccount.h"
#include "HighCreditAccount.h"

class AccountList
{
private:
	Account** accountList;
public:
	AccountList(int size=0) {
		accountList = new Account*[size];
	}
	Account*& operator[] (int idx)
	{
		return accountList[idx];
	}
	Account* operator[] (int idx) const
	{
		return accountList[idx];
	}
	~AccountList()
	{
		delete[] accountList;
	}
};

#endif __ACCOUNT_LIST_H__
