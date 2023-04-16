#include <iostream>
#include <queue>
#define ll long long
using namespace std;

ll arr[300005];
ll pref[300005], suf[300005];
int main()
{
	priority_queue<ll>pq;
	priority_queue<ll>pq1;
	ll i, j, m, n;
	cin >> n;
	for (i = 0; i < 3 * n; i++)
	{
		cin >> arr[i];
	}
	ll k = 0;
	for (i = 0; i < n; i++)
	{
		pq.push(-arr[i]);
		k += arr[i];
	}
	pref[n - 1] = k;
	for (i = n; i < 3 * n; i++)
	{
		if (-pq.top() < arr[i])
		{
			k += (arr[i] + pq.top());
			pq.pop();
			pq.push(-arr[i]);
		}
		pref[i] = k;
	}
	k = 0;
	for (i = 3 * n - 1; i > 2 * n - 1; i--)
	{
		pq1.push(arr[i]);
		k += arr[i];
	}
	suf[2 * n] = k;
	for (i = 2 * n - 1; i >= 0; i--)
	{
		if (pq1.top() > arr[i])
		{
			k -= (pq1.top() - arr[i]);
			pq1.pop();
			pq1.push(arr[i]);
		}
		suf[i] = k;
	}
	ll res = 0;
	bool b = 1;
	for (i = n - 1; i < 2 * n; i++)
	{
		if (b)
		{
			b = false;
			res = pref[i] - suf[i + 1];
		}
		else if (pref[i] - suf[i + 1] > res)
		{
			res = pref[i] - suf[i + 1];
		}
	}
	cout << res;

	return 0;
}