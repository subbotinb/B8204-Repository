#include "stdafx.h"
#include "Header.h"
#include <iostream>
using namespace std;
int main()
{
	dekInfo dequeInfo;
	dequeInfo.head = NULL;
	dequeInfo.tail = NULL;
	dequeInfo.size = 0;
	int caseD;
	int insVal;
	bool close = true;
	while (close) {
		cout << "choose operation \n 1)insert el. left \n 2)insert el. right \n 3)delete el. left \n 4)delete el. right \n 5)output deque size \n 6)close \n";
		cin >> caseD;
		switch (caseD)
		{
		case 1: cin >> insVal;
			lPush(dequeInfo, insVal);
			break;
		case 2: cin >> insVal;
			RPush(dequeInfo, insVal);
			break;
		case 3:cout << lPop(dequeInfo)<<"/n";
			break;
		case 4:cout << RPop(dequeInfo) << "/n";
			break;
		case 5: printDekSize(dequeInfo);
			break;
		case 6: close = false;
			break;
		}
	}

	return 0;
}
