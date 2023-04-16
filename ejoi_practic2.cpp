#include <iostream>
#include <map>
#include <iterator>
#include <algorithm>
#include <vector>
#include <set>
#define ll long long
using namespace std;


const int N = 1000006;
int a[N], b[N], c[N];
map<ll, ll>am[N], bm[N], cm[N];

int main()
{
	ll i, j, m, n, k;
	cin >> n;
	for (i = 0; i < n; i++)
	{
		int aa, bb, cc;
		cin >> aa >> bb >> cc;
		a[aa - 1] = i;
		b[bb - 1] = i;
		c[cc - 1] = i;
	}
	map<ll, ll>mp;
	for (i = 0; i < n; i++)
	{
		am[i] = mp;
		mp[a[i]] = 1;
	}
	mp.erase()

		return 0;
}