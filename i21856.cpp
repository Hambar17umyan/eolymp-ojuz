#include <map>
#include <set>
#include <iterator>
#include <iostream>
using namespace std;
typedef long long ll;

pair<set<ll>, ll>a[1002];
map<set<ll>, ll>mp;
int main()
{
	ll n, m;
	cin >> m >> n;
	ll i, j;
	for (i = 0; i < n; i++)
	{
		ll p, nr;
		cin >> nr >> p;
		for (j = 0; j < nr; j++)
		{
			ll k;
			cin >> k;
			a[i].first.insert(k);
		}
		a[i].second = p;
	}
	set<ll>st;
	for (i = n - 1; i >= 0; i--)
	{
		for (map<set<ll>, ll>::iterator it = mp.begin(); it != mp.end(); it++)
		{
			st = a[i].first;
			for (set<ll>::iterator it1 = it->first.begin(); it1 != it->first.end(); it1++)
			{
				st.insert(*it1);
			}
			ll k = mp[st];
			if (k == 0 || k > a[i].second + it->second)
			{
				mp[st] = a[i].second + it->second;
			}
		}
		if (mp[a[i].first] == 0)
			 
			mp[a[i].first] = a[i].second;
		else mp[a[i].first] = min(mp[a[i].first], a[i].second);
	}
	set<ll>o;
	for (i = 0; i < m; i++)
		o.insert(i + 1);
	cout << mp[o];

	return 0;
}