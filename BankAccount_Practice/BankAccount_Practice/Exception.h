#ifndef __EXCEPTION_H__
#define __EXCEPTION_H__

#include <iostream>
using namespace std;

class Error
{
public:
	void Show() const
	{
		cout << "�ݾ��� �߸��Է��ϼ̽��ϴ�. �ٽ� �Է����ֽʽÿ�." << endl;
	}
};


#endif
