#include <iostream>
using namespace std;

char arr[305][305];
int main()
{
	int i, j, m, n;
	cin >> n;
	for (i = 0; i <= 2 * n; i++)
	{
		for (j = 0; j <= 2 * n; j++)
		{
			arr[i][j] = '.';
		}
	}
	for (i = 0; i <= 2 * n; i++)
	{
		arr[n][i] = '*';
		arr[i][n] = '*';
	}
	for (i = 0; i <= 2 * n; i++)
	{
		for (j = 0; j <= 2 * n; j++)
		{
			cout << arr[i][j];
		}
		cout << endl;
	}

	return 0;
}