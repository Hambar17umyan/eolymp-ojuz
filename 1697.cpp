#include <iostream>
#define ll long long
using namespace std;

ll lcm(ll a, ll b)
{
	if (a > b)
	{
		a += b;
		b = a - b;
		a -= b;
	}
	//a<=b
	for (ll i = 1; i <= a; i++)
	{
		if ((i * b) % a == 0)
		{
			return i * b;
		}
	}
}

int main()
{
	ll n;
	ll k = 1;
	cin >> n;
	for (int i = 2; i <= n; i++)
	{
		k = lcm(k, i);
	}
	cout << k - 1;

	return 0;
}