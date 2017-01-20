//
// Example from Item 12
//

#include <iostream>
#include <vector>

#include "ESTLUtil.h"
#include "Widget.h"

int data[] = { -30, 102, 5, -19, 0, 5, -3000, 4000, 5, -2 };
const int numValues = sizeof data / sizeof(int);

// Dummy Mutex library:
template<typename T>
inline void getMutexFor(const T &t) {}

template<typename T>
inline void releaseMutexFor(const T &t) {}


int main()
{
	using namespace std;
	using namespace ESTLUtils;

	{
		vector<int> v;
		v.insert(v.begin(), data, data + numValues);	// insert the ints in data
														// into v at the front
		printContainer("after range insert, v", v);

		vector<int>::iterator first5(find(v.begin(), v.end(), 5));	// Line 1
		if (first5 != v.end()) {									// Line 2
			*first5 = 0;											// Line 3
		}

		printContainer("after changing first 5 to zero, v", v);
	}


	{
		vector<int> v;
		v.insert(v.begin(), data, data + numValues);	// insert the ints in data
														// into v at the front
		printContainer("after range insert, v", v);

		getMutexFor(v);
		vector<int>::iterator first5(find(v.begin(), v.end(), 5));
		if (first5 != v.end()) {						// this is now safe
			*first5 = 0;								// so is this
		}
		releaseMutexFor(v);
		printContainer("after changing first 5 to zero, v", v);
	}
	
	return 0;
}	
