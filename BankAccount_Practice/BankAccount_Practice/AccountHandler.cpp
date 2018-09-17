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
	cout << "�̸��� �Է��Ͻʽÿ�: "; cin >> name;
	cout << "���¹�ȣ�� �Է��Ͻʽÿ�: "; cin >> number;

	while (1)
	{
		try {
			cout << "�Ա��Ͻ� ���� �Է��Ͻʽÿ�: "; cin >> money;
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
		cout << "���� ������ ���ʽÿ�." << endl;
		cout << "1. �Ϲ� ����" << endl;
		cout << "2. ��� ����" << endl;
		cout << "�Է�: " << endl; cin >> accountCase;

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
				cout << "����� ����ֽʽÿ�" << endl;
				cout << "1. A��� - �߰� ���� 7%" << endl;
				cout << "2. B��� - �߰� ���� 5%" << endl;
				cout << "3. C��� - �߰� ���� 3%" << endl;
				cout << "�Է�: "; cin >> rank;

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
					cout << "�߸��Է��ϼ̽��ϴ�. �ٽ� �Է����ֽʽÿ�. \n";
					break;
				}
			}
		}
		else
		{
			cout << "�ٽ� �Է����ֽʽÿ�." << endl;
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
	cout << "ã�� ���¹�ȣ�� �Է����ֽʽÿ�: "; cin >> number;
	for (int idx = 0; idx < count; idx++)
	{
		if (number == accountLIst[idx]->getNumber())
		{
			cout << "���� ���� ���� \n" << endl;
			accountLIst[idx]->Show();
			return idx;
		}
	}
	cout << "ã���ô� ���°� �������� �ʽ��ϴ�." << endl;
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
		cout << "�Ա��� �ݾ��� �Է����ֽʽÿ�: "; cin >> depositM;
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
		cout << "����� �ݾ��� �Է����ֽʽÿ�: "; cin >> withdrawM;

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
	cout << "��ü�� ���¹�ȣ�� �Է����ֽʽÿ�" << endl;
	int idx2 = Search();
	if (idx2 == -1)
		return;

	while (1)
	{
		int withdrawM;
		cout << endl;
		cout << "��ü�� �ݾ��� �Է����ֽʽÿ�: "; cin >> withdrawM;

		try {
			accountLIst[idx1]->minMoney(withdrawM);
			accountLIst[idx2]->addMoney(withdrawM);
			cout << "��ü �Ϸ�Ǿ����ϴ�." << endl;
			accountLIst[idx1]->Show();
			break;
		}
		catch (Error& expn)
		{
			expn.Show();
		}
	}

}