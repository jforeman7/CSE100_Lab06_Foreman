// Jeff Foreman 100216478
// CSE 100 03L
// Lab 06: Matrix Chain Multiplication
// 25 Oct 2017

#include <iostream>
#include <limits> // To set a variable to "infinity".

using namespace std;

// Pseudocode found on page 377.
void PrintOptimalParens(int *s, int i, int j, int n)
{
	// Print out the name of the Matrix.
	if (i == j)
	{
		cout << "A" << (i - 1);
		return;
	}
	
	// Place the parenthesis.
	cout << "(";

	PrintOptimalParens((int *)s, i, *((s + i * n) + j), n);
	PrintOptimalParens((int *)s, *(s + i * n) + j) + 1, j, n);

	cout << ")";
} // End function.

// Pseudocode found on page 375.
void MatrixChainOrder(int p[], int n)
{
	// Allocate memory for the two dimensional matrix arrays.
	int m[n][n];
	int s[n][n];
	
	// Initialize the diagonal entries in matrix 'm' to zero.
	for (int i = 0; i < n; i++)
		m[i][i] = 0;;
	
	
	// Extra iterator variable.
	int j;
	
	// Temp variable for the matrix chain multiplication.
	int q;
	
	for (int l = 2; l < n; l++)
	{
		for (int i = 1; i < n - l + 1; i++)
		{
			j = i + l - 1;
			
			// Set to "infinity".
			m[i][j] = numeric_limits<int>::max();
			
			for (int k = i; k <= j - 1; k++)
			{
				q = m[i][k] + m[k + 1][j] + (p[i - 1] * p[k] * p[j]);
				
				if (q < m[i][j])
				{
					m[i][j] = q;
					s[i][j] = k;
				} // End if.
			} // End k loop.	
		} // End i loop.
	} // End l loop.
	
	// Print out the result.
	cout << m[1][n - 1] << endl;
	
	// Print out the optimal chain multiplication.
	PrintOptimalParens((int *)s, 1, n - 1, n);
	cout << endl;
	
} // End function.

int main()
{
	// Get the size of the array.
	int n;
	cin >> n;
	
	// Instantiate the array.
	int *A = new int[n];
	
	// Input into the array.
	for (int i = 0; i <= n; i++)
		cin >> A[i];
	n++;
	
	// Begin the Matrix Chain Multiplication.
	MatrixChainOrder(A, n + 1);
	
	return 0;
}
