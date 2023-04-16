#include <iostream>
#include <algorithm>
typedef long long ll;
#include <map>
using namespace std;

int arr[100005];
int mp[100005];
int main()
{
	int i, j, m, n, k;
	cin >> n >> m;
	for (i = 0; i < n; i++)
	{
		cin >> arr[i];
	}

	
	while (m--)
	{
		for (i = 0; i <= n; i++)
		{
			mp[i] = 0;
		}
		cin >> k;
		ll a, b;
		int p = 0;
		a = b = 0;
		for (i = 0; i < k; i++)
		{
			mp[arr[i]]++;
			p = max(p, arr[i]);
		}
		int y = n;
		a += p;
		mp[p]--;
		y--;
		int o = k;
		bool al = false;
		while (y)
		{
			if (mp[p] == 0)
			{
				for (; p >= 1; p--)
				{
					if (mp[p] > 0)
					{
						break;
					}
				}
			}
			if (o < n)
			{
				if (arr[o] >= p)
				{
					if (al)
						a += arr[o];
					else b += arr[o];
				}
				else
				{
					mp[arr[o]]++;
					mp[p]--;
					if (al)
						a += p;
					else b += p;
				}
			}
			else
			{
				mp[p]--;
				if (al)
					a += p;
				else b += p;
			}
			o++;
			y--;
			al = !al;
		}
		cout << a - b << endl;
	}

	return 0;
}