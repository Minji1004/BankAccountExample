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
			cout << "--------���� ����--------" << endl;
			list.AddAccount();
			break;
		case 2:
			cout << "--------�Ա�--------" << endl;
			list.Deposit();
			break;
		case 3:
			cout << "--------���--------" << endl;
			list.Withdraw();
			break;
		case 4:
			cout << "--------��ü--------" << endl;
			list.Transfer();
			break;
		case 5:
			cout << "--------�ܾ� ��ȸ--------" << endl;
			list.Search();
			break;
		case 6:
			cout << "--------���� ��ü ��ȸ--------" << endl;
			list.ShowAll();
			break;
		case 7:
			cout << "\n����Ǿ����ϴ�. \n";
			while (1);
			return 0;
		default:
			cout << "�߸��Է��ϼ̽��ϴ�. �ٽ� �Է����ֽʽÿ�." << endl;
			break;
		}
	}
}
