#ifndef __ACCOUNT_HANDLER_H__
#define __ACCOUNT_HANDLER_H__

#include "AccountList.h"


class AccountHandler
{
	AccountList accountLIst;
	int count;
	AccountHandler() {}
public:
	AccountHandler(int size);
	void AddAccount();
	void ShowAll() const;
	int Search() const;
	void Deposit();
	void Withdraw();
	void Transfer();
};


#endif