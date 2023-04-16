#include <iostream>
#include <vector>
#include <map>
#include <set>
#define ll long long
using namespace std;

map<vector<int>, int>mp;
map<char, int>ind;
int arr[88];
int main()
{
	int i, j, m, n;
	cin >> n;
	string s;
	cin >> s;
	set<char>st;
	j = 0;
	for (i = 0; i < n; i++)
	{
		st.insert(s[i]);
	}
	for (set<char>::iterator it = st.begin(); it != st.end(); it++, j++)
	{
		ind[*it] = j;
	}
	vector<int>v(j);
	mp[v] = 1;
	ll res = 0;
	ll mod = 1000000007;
	for (i = 0; i < n; i++)
	{
		v[ind[s[i]]]++;
		if (ind[s[i]] - 1 >= 0)
		{
			v[ind[s[i]] - 1]--;
		}
		else
		{
			v[j - 1]--;
		}
		res += mp[v];
		res %= mod;
		mp[v]++;
		//cout << i << ' ' << mp[v]++ << endl;
	}
	/*cout << endl;
	for (i = n - 1; i > 0; i--)
	{
		int s1, w;
		s1 = w = 0;
		if (s[i] == 'S')
			s1++;
		else w++;
		for (j = i - 1; j >= 0; j--)
		{
			if (s[j] == 'S')
				s1++;
			else w++;

			if (w == s1)
			{
				arr[i]++;
			}
		}
	}
	for (i = 0; i < n; i++)
	{
		cout << i << ' ' << arr[i] << '\n';
	}*/
	cout << res;

	return 0;
}