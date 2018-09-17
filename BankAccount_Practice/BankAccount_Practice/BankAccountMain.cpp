#include <iostream>
#include "AccountHandler.h"
#include "BankAccountEtc.h"
using namespace std;



int main(void)
{
	AccountHandler list(100);

	while (1)
	{
		int choice;
		ShowMenu();
		cin >> choice;

		switch (choice)
		{
		case 1:
			cout << "--------계좌 개설--------" << endl;
			list.AddAccount();
			break;
		case 2:
			cout << "--------입금--------" << endl;
			list.Deposit();
			break;
		case 3:
			cout << "--------출금--------" << endl;
			list.Withdraw();
			break;
		case 4:
			cout << "--------이체--------" << endl;
			list.Transfer();
			break;
		case 5:
			cout << "--------잔액 조회--------" << endl;
			list.Search();
			break;
		case 6:
			cout << "--------계좌 전체 조회--------" << endl;
			list.ShowAll();
			break;
		case 7:
			cout << "\n종료되었습니다. \n";
			while (1);
			return 0;
		default:
			cout << "잘못입력하셨습니다. 다시 입력해주십시오." << endl;
			break;
		}
	}
}
