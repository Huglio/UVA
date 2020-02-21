#include <stdio.h>
#include <algorithm>

using namespace std;

int gcd(int a, int b)
{
	if(b == 0) return a;
	
	return gcd(b, a % b);
}

int main()
{
	int vet[1010];
	int cnt = 0;
	while(scanf("%d", &vet[cnt++]) && vet[cnt - 1])
	{
		while(scanf("%d", &vet[cnt++]) && vet[cnt - 1]);
		cnt--;

		sort(vet, vet + cnt);
		
		for (int i = 1; i < cnt; i++)
			vet[i] = vet[i] - vet[0];
		
		int divisor = 0;
		for (int i = 1; i < cnt; i++)
			divisor = gcd(divisor, vet[i]);
			
		printf("%d\n", divisor);
		cnt = 0;
	}
			
}
