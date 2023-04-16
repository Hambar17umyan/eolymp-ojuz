#include <iostream>
#include <map>
#include <iterator>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;
typedef long long ll;

const int N = 200005;
ll arr[N];
map<ll, ll>mp;
map<ll, pair<vector<ll>, ll>>r;
int main()
{
	ll i, j, n, k;
	cin >> n >> k;
	for (i = 0; i < n + k; i++)
	{
		cin >> arr[i];
		mp[arr[i]]++;
	}
	sort(arr, arr + k);
	for (i = 0; i <= k; i++)
	{
		for (j = n + k - 1; j - i + 1 >= n; j--)
		{
			ll w = arr[i] + arr[j];
			ll q = 1 * (j - i + 1);
			set<ll>st;
			for (int e = i; e <= j; e++)
			{
				int sz = st.size();
				st.insert(arr[e]);
				st.insert(w - arr[e]);
				ll qq = 2;
				if (w - arr[e] == arr[e])
					qq = 1;
				if (st.size() - sz == qq)
				{
					q -= abs(mp[arr[e]] - mp[w - arr[e]]);
				}
			}
			if (q < n)
			{
				mp[arr[j]]--;
				continue;
			}
			st.erase(st.begin(), st.end());
			ll y = n / 2;
			multiset<ll> res;
			for (int e = i; e <= j && y > 0; e++)
			{
				if (mp[arr[e]] && mp[w - arr[e]])
				{
					if (mp[arr[e]] == 1 && arr[e] == w - arr[e])
					{

					}
					else
					{
						res.insert(arr[e]);
						res.insert(w - arr[e]);
						mp[arr[e]]--;
						mp[w - arr[e]]--;
						y--;
					}
				}
			}
			//cout << i << ' ' << j << endl;
			for (multiset<ll>::iterator it = res.begin(); it != res.end(); it++)
			{
				cout << *it << ' ';
			}
			return 0;
		}
		for (j = n + k - 1; j - i + 1 >= n; j--)
		{
			mp[arr[j]]++;
		}
		mp[arr[i]]--;
	}
	//(k^2)/2 * (n+k)

	return 0;
}