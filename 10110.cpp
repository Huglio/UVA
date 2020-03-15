#include <stdio.h>
#include <bitset>
#include <vector>
#include <cmath>

using namespace std;

#define ll long long int

int main()
{
	ll n;
	while(scanf("%lld", &n) && n)
	{
		ll root = sqrt(n);
		
		if(root * root == n)
			printf("yes\n");
		else
			printf("no\n");
	}
}
