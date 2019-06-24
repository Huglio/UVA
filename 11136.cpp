#include "pch.h"
#include <stdio.h>
#include <set>

using namespace std;

int main()
{
	freopen("Input.txt", "r", stdin);

	int n;
	while (scanf("%d", &n) && n)
	{
		long long int total = 0;
		multiset<int> SET;
		
		for (int i = 0; i < n; i++)
		{
			int k; scanf("%d", &k);
			for (int j = 0; j < k; j++)
			{
				int x; scanf("%d", &x);
				SET.insert(x);
			}

			multiset<int>::iterator Greatest = SET.end(); Greatest--;
			multiset<int>::iterator Lowest = SET.begin();

			total += *Greatest - *Lowest;
			SET.erase(Greatest);
			SET.erase(Lowest);
		}

		printf("%lld\n", total);
	}
}