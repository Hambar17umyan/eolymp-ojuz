#include <iostream>
using namespace std;
#define ll long long

const int N = 100002;
ll arr[N];
ll p[N], pp[N], s[N], ss[N];

int main()
{
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	p[0] = pp[0] = arr[0];
	s[n - 1] = ss[n - 1] = arr[n - 1];
	for (int i = 1; i < n; i++)
	{
		p[i] = p[i - 1] + arr[i];
		pp[i] = pp[i - 1] + p[i];
	}

	for (int i = n - 2; i >= 0; i--)
	{
		s[i] = s[i + 1] + arr[i];
		ss[i] = ss[i + 1] + s[i];
	}
	int q;
	cin >> q;
	while (q--)
	{
		short op;
		cin >> op;
		if (op == 2)
		{
			int l, r, k;
			cin >> l >> r >> k;
			l--;
			r--;
			ll sum = (l > 0) ? p[r] - p[l - 1] : p[r];
			sum *= k;
			if (k == 1)
			{
				cout << sum << endl;
				continue;
			}
			sum -= pp[l + k - 2];
			if (l != 0)
			{
				sum += pp[l - 1];
				sum += p[l - 1] * (k - 1);
			}
			sum -= ss[r - k + 2];
			if (r != n - 1)
			{
				sum += ss[r + 1];
				sum += s[r + 1] * (k - 1);
			}
			cout << sum << endl;
		}
		else
		{
			for (int i = 0; i < m; i++)
			{
				int o;
				cin >> o;
			}
		}
	}

	return 0;
}