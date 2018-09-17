#ifndef __ACCOUNT_H__
#define __ACCOUNT_H__

class Account
{
	char * username;
	int accountNumber;
	int money;
public:
	Account(const char * name, int number, int money);
	virtual void Show() const;
	int getNumber() const;
	virtual void addMoney(int depositM);
	void minMoney(int withdrawM);
	~Account();
};


#endif