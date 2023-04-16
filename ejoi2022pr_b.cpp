#include <iostream>
#define ll long long
using namespace std;

const int N = 1000006;
int a[N], b[N], c[N];
int arr[N];
int main()
{
	int n, i, k = 0, j;
	ll res = 0;
	cin >> n;
	for (i = 0; i < n; i++)
	{
		int x, y, z;
		cin >> x >> y >> z;
		a[x - 1] = i;
		b[y - 1] = i;
		c[z - 1] = i;
	}
	for (i = 0; i < n; i++)
	{
		int x, y, z;
		x = arr[a[i]];
		y = arr[b[i]];
		z = arr[c[i]];
		if (x == 2)
		{
			res += k;
		}
		if (y == 2)
		{
			res += k;
		}
		if (z == 2)
		{
			res += k;
		}
		arr[a[i]]++;
		arr[b[i]]++;
		arr[c[i]]++;
		x++;
		y++;
		z++;
		if (x == 3)
		{
			k++;
		}
		if (y == 3)
		{
			k++;
		}
		if (z == 3)
		{
			k++;
		}
	}
	cout << res;

	return 0;
}