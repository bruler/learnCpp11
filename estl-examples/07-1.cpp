//
// First example from Item 7
//

#include <iostream>
#include <vector>

#include "ESTLUtil.h"
#include "Widget.h"

using namespace std;
using namespace ESTLUtils;

int data[] = { -30, 102, 55, -19, 0, 222, -3000, 4000, 8, -2 };
const int numValues = sizeof data / sizeof(int);
const int SOME_MAGIC_NUMBER = 10;

void doSomething()
{
	vector<Widget*> vwp;
	for (int i = 0; i < SOME_MAGIC_NUMBER; ++i)
	vwp.push_back(new Widget);
						// use vwp
	printContainer("vwp", vwp);
						// Widgets are leaked here!
}


int main()
{
	using namespace std;
	using namespace ESTLUtils;

	doSomething();

	return 0;
}
