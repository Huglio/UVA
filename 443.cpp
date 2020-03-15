#include <stdio.h>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

#define ll long long int

ll power(int n, int e)
{
	if (e == 1) return n;
	if (e == 0) return 1;
	
	ll resp = power(n, e / 2);
	resp = resp * resp;
	
	if(e % 2) resp = resp * n;
	
	return resp;
}

int main()
{
	vector<ll> V;
	ll init = 1;
	for (int i = 0; init * power(2, i) <= 2000000000; i++)
	{
		ll two = init * power(2, i);
		for (int j = 0; two * power(3, j) <= 2000000000; j++)
		{
			ll three = two * power(3, j);
			for (int k = 0; three * power(5, k) <= 2000000000; k++)
			{
				ll five = three * power(5, k);
				for (int l = 0; five * power(7, l) <= 2000000000; l++)
				{
					V.push_back(five * power(7, l));
				}
			}
		}
	}
					
	sort(V.begin(), V.end());
	
	int n;
	while(scanf("%d", &n) && n)
	{
		if(n % 10 == 1 && (n / 10) % 10 != 1)
			printf("The %dst humble number is %lld.\n", n, V[n - 1]);
		else if(n % 10 == 2 && (n / 10) % 10 != 1)
			printf("The %dnd humble number is %lld.\n", n, V[n - 1]);
		else if(n % 10 == 3 && (n / 10) % 10 != 1)
			printf("The %drd humble number is %lld.\n", n, V[n - 1]);
		else
			printf("The %dth humble number is %lld.\n", n, V[n - 1]);
	}
}
