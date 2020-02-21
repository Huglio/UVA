#include <stdio.h>
#include <algorithm>
#include <bitset>
#include <vector>
#include <cmath>

using namespace std;

int gcd(int a, int b)
{
	if(b == 0) return a;
	return gcd(b, a % b);
}

int lcm(int a, int b)
{
	return a / gcd(a, b) * b;
}

int main()
{
	int n;
	while(scanf("%d", &n) && n)
	{
		vector<int> divisors;
		
		int i;
		for (i = 1; i * i < n; i++)
			if(n % i == 0)
			{
				divisors.push_back(i);
				divisors.push_back(n / i);
			}
			
		if(i * i == n)
			divisors.push_back(i);
			
		int resp = 0;
		for (int i = 0; i < (int)divisors.size(); i++)
			for (int j = i; j < (int)divisors.size(); j++)
				if(lcm(divisors[i], divisors[j]) == n)
					resp++;
			
		printf("%d %d\n", n, resp);
	}
}
