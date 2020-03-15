#include <stdio.h>
#include <vector>
#include <algorithm>
#include <cstring>
#include <iostream>

using namespace std;

#define ll long long int

int main()
{
	int n;
	while(scanf("%d", &n) != EOF)
	{
		int zeros = 0;
		vector<int> big;
		vector<int> small;
		
		while(n)
		{
			if(n % 10 == 0)
				zeros++;
			else
			{
				big.push_back(n % 10);
				small.push_back(n % 10);
			}
			
			n /= 10;
		}
		
		sort(big.begin(), big.end(), greater<int>());
		sort(small.begin(), small.end());
		
		ll n1 = 0;
		for (int i = 0; i < (int)big.size(); i++)
			n1 = n1 * 10 + big[i];
		for (int i = 0; i < zeros; i++)
			n1 = n1 * 10;
			

		ll n2 = 0; if(small.size()) n2 = small[0];
		for (int i = 0; i < zeros; i++)
			n2 = n2 * 10;
		for (int i = 1; i < (int)small.size(); i++)
			n2 = n2 * 10 + small[i];
		
		printf("%lld - %lld = %lld = 9 * %lld\n", n1, n2, n1 - n2, (n1 - n2) / 9);
	}
}
