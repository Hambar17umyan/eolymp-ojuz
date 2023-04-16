#include <iostream>
typedef long long ll;
using namespace std;

ll arr[100005];
void solve()
{
	ll i, j, k, n, m;
	m = 0;
	cin >> n >> k;
	for (i = 0; i < n; i++)
	{
		cin >> arr[i];
		m += arr[i];
	}
	if (k == 1)
	{
		if (m % 2)
			cout << 1;
		else cout << 0;
	}
	else if (n == 1)
	{
		if (m % 2)
			cout << 1;
		else
		{
			if (k >= n)
				cout << 1;
			else
			{

			}
		}
	}
}
int main()
{
	int t;
	cin >> t;
	while (t--)
		solve();

	return 0;
}