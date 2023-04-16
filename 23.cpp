#include <iostream>
#define ll long long
using namespace std;

ll arr[20];
int main()
{
	ll n, k;
	cin >> n >> k;
	arr[0] = 1;
	for (int i = 1; i < n; i++)
	{
		arr[i] = arr[i - 1] * (k - 1);
	}
	cout << arr[n - 1] * k;


	return 0;
}