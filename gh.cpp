#include <iostream>
#include <stack>
using namespace std;

long long dp[105][105], arr[105][105];

stack<char>st;
void rec(int x, int y)
{
	if (x > 0)
	{
		if (dp[x - 1][y] + arr[x][y] == dp[x][y])
		{
			st.push('D');
			rec(x - 1, y);
			return;
		}
	}
	if (y > 0)
	{
		if (dp[x][y - 1] + arr[x][y] == dp[x][y])
		{
			st.push('R');
			rec(x, y - 1);
			return;
		}
	}
}
int main()
{
	int n, m, i, o, p, j;
	cin >> n >> m;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < m; j++)
		{
			cin >> arr[i][j];
		}
	}
	dp[0][0] = arr[0][0];
	for (i = 1; i < n; i++)
	{
		dp[i][0] = dp[i - 1][0] + arr[i][0];
	}
	for (i = 1; i < m; i++)
	{
		dp[0][i] = dp[0][i - 1] + arr[0][i];
	}
	for (i = 1; i < n; i++)
	{
		for (j = 1; j < m; j++)
		{
			dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]) + arr[i][j];
		}
	}
	cout << dp[n - 1][m - 1] << endl;
	rec(n - 1, m - 1);
	while (!st.empty())
	{
		cout << st.top() << ' ';
		st.pop();
	}

	return 0;
}