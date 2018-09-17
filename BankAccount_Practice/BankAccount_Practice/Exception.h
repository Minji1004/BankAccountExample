#ifndef __EXCEPTION_H__
#define __EXCEPTION_H__

#include <iostream>
using namespace std;

class Error
{
public:
	void Show() const
	{
		cout << "금액을 잘못입력하셨습니다. 다시 입력해주십시오." << endl;
	}
};


#endif
