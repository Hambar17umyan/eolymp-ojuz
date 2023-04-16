#include "grader.h"
#include <map>
#include <set>
#include <ctime>
using namespace std;

map<int, int>mp;

void solve(int n)
{
	srand(time(0));
	int i;
	set<int>y;
	int l = 60;
	if (n <= 50)
		l = 50;
	if (n <= l)
	{

	}
	for (i = 1; i <= min(l, n);)
	{
		int k = kth(i);
		i++;
		if (mp[k] == 0)
		{
			mp[k] = cnt(k);
			i++;
		}
		if (mp[k] > n / 3)
		{
			say_answer(k);
			return;
		}
	}
	say_answer(-1);
}
