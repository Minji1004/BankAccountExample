#include <iostream>
#include <cstring>
#include "AccountHandler.h"
#include "HighCreditAccount.h"
#include "Exception.h"

using namespace std;

namespace Rank
{
	enum { A = 7, B = 5, C = 3 };
}


AccountHandler::AccountHandler(int size) : accountLIst(size) 
{
	count = 0;
}

void AccountHandler::AddAccount()
{
	char name[10];
	int number;
	int money;
	int accountCase;
	cout << "이름을 입력하십시오: "; cin >> name;
	cout << "계좌번호를 입력하십시오: "; cin >> number;

	while (1)
	{
		try {
			cout << "입금하실 돈을 입력하십시오: "; cin >> money;
			if (money <= 0)
				throw Error();
			break;
		}
		catch (Error& err)
		{
			err.Show();
		}
	}

	while (1)
	{
		cout << "계좌 종류를 고르십시오." << endl;
		cout << "1. 일반 계좌" << endl;
		cout << "2. 우대 계좌" << endl;
		cout << "입력: " << endl; cin >> accountCase;

		if (accountCase == 1)
		{
			accountLIst[count++] = new NormalAccount(name, number, money);
			return;
		}
		else if (accountCase == 2)
		{
			while (1)
			{
				int rank;
				cout << "등급을 골라주십시오" << endl;
				cout << "1. A등급 - 추가 이자 7%" << endl;
				cout << "2. B등급 - 추가 이자 5%" << endl;
				cout << "3. C등급 - 추가 이자 3%" << endl;
				cout << "입력: "; cin >> rank;

				switch (rank)
				{
				case 1:
					accountLIst[count++] = new HighAccount(name, number, money, Rank::A);
					return;
				case 2:
					accountLIst[count++] = new HighAccount(name, number, money, Rank::B);
					return;
				case 3:
					accountLIst[count++] = new HighAccount(name, number, money, Rank::C);
					return;
				default:
					cout << "잘못입력하셨습니다. 다시 입력해주십시오. \n";
					break;
				}
			}
		}
		else
		{
			cout << "다시 입력해주십시오." << endl;
		}
	}

}
void AccountHandler::ShowAll() const
{
	for (int idx = 0; idx < count; idx++)
		accountLIst[idx]->Show();
}

int AccountHandler::Search() const
{
	int number;
	cout << "찾을 계좌번호를 입력해주십시오: "; cin >> number;
	for (int idx = 0; idx < count; idx++)
	{
		if (number == accountLIst[idx]->getNumber())
		{
			cout << "현재 계좌 상태 \n" << endl;
			accountLIst[idx]->Show();
			return idx;
		}
	}
	cout << "찾으시는 계좌가 존재하지 않습니다." << endl;
	return -1;
}

void AccountHandler::Deposit() throw(Error)
{
	int idx = Search();
	if (idx == -1)
		return;

	while (1)
	{
		int depositM;
		cout << endl;
		cout << "입금할 금액을 입력해주십시오: "; cin >> depositM;
		try {
			accountLIst[idx]->addMoney(depositM);
			accountLIst[idx]->Show();
			break;
		}
		catch (Error& expn)
		{
			expn.Show();
		}
	}
}

void AccountHandler::Withdraw() throw(Error)
{
	int idx = Search();
	if (idx == -1)
		return;
	while (1)
	{
		int withdrawM;
		cout << endl;
		cout << "출금할 금액을 입력해주십시오: "; cin >> withdrawM;

		try {
			accountLIst[idx]->minMoney(withdrawM);
			accountLIst[idx]->Show();
			break;
		}
		catch (Error& expn)
		{
			expn.Show();
		}
	}
}

void AccountHandler::Transfer() throw(Error)
{
	int idx1 = Search();
	if (idx1 == -1)
		return;
	cout << "이체할 계좌번호를 입력해주십시오" << endl;
	int idx2 = Search();
	if (idx2 == -1)
		return;

	while (1)
	{
		int withdrawM;
		cout << endl;
		cout << "이체할 금액을 입력해주십시오: "; cin >> withdrawM;

		try {
			accountLIst[idx1]->minMoney(withdrawM);
			accountLIst[idx2]->addMoney(withdrawM);
			cout << "이체 완료되었습니다." << endl;
			accountLIst[idx1]->Show();
			break;
		}
		catch (Error& expn)
		{
			expn.Show();
		}
	}

}