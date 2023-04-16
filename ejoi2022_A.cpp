#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define ll long long
#define middle ll mid = (l + r) / 2
#define poss pos * 2
#define midd mid + 1

const int N = 100005;

ll d[N], e[N], af[N];

//segment tree
ll prr[N];
ll t[4 * N];

void build(int l, int r, int pos)
{
	if (l == r)
	{
		t[pos] = r;
		prr[l] = pos;
		return;
	}
	middle;
	build(l, mid, poss);
	build(midd, r, poss + 1);
	if (d[t[poss]] >= d[t[poss + 1]])
	{
		t[pos] = t[poss];
	}
	else t[pos] = t[poss + 1];
}

ll fmax(int l, int r, int ql, int qr, int u, int pos)
{
	if (d[t[pos]] <= d[u])
	{
		return -1;
	}
	middle;
	if (l == r)
	{
		return l;
	}
	if (qr <= mid)
	{
		return fmax(l, mid, ql, qr, u, poss);
	}
	if (ql >= midd)
	{
		return fmax(midd, r, ql, qr, u, poss + 1);
	}
	ll p = fmax(l, mid, ql, mid, u, poss);
	if (p == -1)
	{
		return fmax(midd, r, midd, qr, u, poss + 1);
	}
	return p;
}
//end of segment tree
void build2(int l, int r, int pos)
{
	if (l == r)
	{
		t[pos] = e[l];
		prr[r] = pos;
		return;
	}
	middle;
	build(l, mid, poss);
	build(midd, r, poss + 1);
	t[pos] = t[poss] + t[poss + 1];
}

int rec(int i, ll v)
{
	if (e[i] < v)
	{
		if (af[i] != -1)
		{
			return rec(af[i], v - e[i]);
		}
		return -1;
	}
	return i;
}
int main()
{
	ll n, q;
	cin >> n >> q;
	ll o = 0;
	vector<ll>pref(n);
	for (int i = 0; i < n; i++)
	{
		cin >> d[i];
		cin >> e[i];
		o += e[i];
		pref[i] = o;
	}
	build(0, n - 1, 1);
	for (int i = 0; i < n - 1; i++)
	{
		af[i] = fmax(0, n - 1, i + 1, n - 1, i, 1);
	}
	af[n - 1] = -1;
	build2(0, n - 1, 1);
	if (n <= 1000)
	{
		while (q--)
		{
			ll k, l;
			cin >> k >> l;
			k--;
			ll res = rec(k, l);
			cout << res + 1 << endl;
		}
		return 0;
	}
	while (q--)
	{
		ll k, l;
		cin >> k >> l;
		ll p = 0;
		if (k != 1)
		{
			p = pref[k - 2];
		}
		vector<ll>::iterator it = lower_bound(pref.begin() + k - 1, pref.end(), l + p);
		if (it == pref.end())
		{
			cout << 0 << endl;
		}
		else cout << it - pref.begin() + 1 << endl;
	}


	return 0;
}