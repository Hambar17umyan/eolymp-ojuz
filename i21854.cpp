#include <iostream>
#include <iostream>
#include <math.h>
using namespace std;
typedef long long ll;

ll pw(ll x, ll mod) 
{
	ll res;
	if (x == 0) res = 1;
	else if (x == 1)    res = 2;
	else {
		res = pw(x / 2, mod);
		if (x % 2 == 0)
			res = (res * res) % mod;
		else
			res = (((res * res) % mod) * 2) % mod;
	}
	return res;
}

int main()
{
	ll i, j;
	int n;
	cin >> n;
	ll res = 0;
	ll mod = 1000000007;
	for (i = 0; i < n; i++)
	{
		cin >> j;
		res += pw(j, mod);
		res %= mod;
	}
	cout << res;

	return 0;
}