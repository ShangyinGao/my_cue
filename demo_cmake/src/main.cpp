#include <iostream>
#include "myMath.h"

using namespace std;

int main () {
	double x = 1.0, y = 2.0;
	cout << MyMath::myAdd(x, y) << endl;
	cout << MyMath::mySub(x, y) << endl;
	cout << MyMath::myMul(x, y) << endl;
	cout << MyMath::myDiv(x, y) << endl;

	return 0;
}
