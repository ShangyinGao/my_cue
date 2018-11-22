#include <iostream>
#include "myMath.h"

using namespace std;

double MyMath::myMul(double x, double y) {
	cout << "MyMath::myMul" << endl;
	return x * y;
}

double MyMath::myAdd(double x, double y) {
	cout << "MyMath::myAdd" << endl;
	return x + y;
}

double MyMath::mySub(double x, double y) {
	cout << "MyMath::mySub" << endl;
	return x - y;
}

double MyMath::myDiv(double x, double y) {
	cout << "MyMath::myDiv" << endl;
	return x / y;
}

