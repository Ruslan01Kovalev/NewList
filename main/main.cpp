#include "SList.h"
#include <cstdlib>

using namespace std;

int main()
{
	SList<int> Mylist;
	Mylist.push_back(1);
	Mylist.push_back(5);
	Mylist.push_back(100);

	cout << MyList;
	cout << endl;

	for (int i = 0; i < 3; i++)
		MyList.pop_back();

	for (int i = 0; i < 3; i++)
	{
		int m = i + rand() % 10;
		MyList.push_back(m);
	}

	cout << MyList;

	return 0;
}