// Jeff Foreman 100216478
// CSE 100 03L
// Lab 06: Matrix Chain Multiplication
// 25 Oct 2017

#include <iostream>

using namespace std;

// Pseudocode found on page 377.
void PrintOptimalParens(int i, int j, int bracket, int *name)
{
	if (i == j)
	{
		cout << "A" << (i - 1);
		return;
	}
	
	else
	{
		cout << "(";
		
		int jp = name + i * bracket + j;
		
		PrintOptimalParens(i, *jp, bracket, name);
		PrintOptimalParens(*jp + 1, j, bracket, name);
		
		cout << ")";
	}
}
