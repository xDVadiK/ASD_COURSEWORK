#include <iostream>
#include "Calculator.h"

using namespace std;

int main()
{
	cout << "The simplest version of the calculator has been launched\n\n";
	String_mathematical_expression mathematical_expression;
	cout << "Enter a mathematical expression: ";
	cin >> mathematical_expression;
	Processing_mathematical_expression(mathematical_expression);

	return 0;
}