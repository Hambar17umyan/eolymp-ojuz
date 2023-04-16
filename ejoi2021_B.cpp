#include <iostream>
#include <map>
#include <set>
#include <vector>
#include <queue>
using namespace std;

int arr[1002];
int sum[1002][1002];
map<int, set<pair<int, bool>>> g;
void solve()
{
	int n, i, j, k;
	cin >> n;
	for (i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	for (i = 0; i < n; i++)
	{
		k = 0;
		for (j = i; j < n; j++)
		{
			k += arr[j];
			sum[i][j] = k;
		}
	}
	k = 0;
	for (i = 0; i < n; i++)
	{
		map<int, set<pair<int, bool>>>::iterator it;
		queue<pair<int, int>>q;
		for (it = g.begin(); it != g.end(); it++)
		{
			q.push(make_pair(arr[i], it->first));
		}
		while (!q.empty())
		{
			g[q.front().first].insert({ q.front().first + q.front().second, 1 });
			g[q.front().second].insert({ q.front().first + q.front().second, 1 });
			g[q.front().first + q.front().second].insert({ q.front().first, 0 });
			g[q.front().first + q.front().second].insert({ q.front().second, 0 });
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