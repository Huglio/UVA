#include <stdio.h>
#include <cstring>

using namespace std;

bool dp[10010][210];
int vet[10010];

int n, k;

int soma(int a, int b)
{
	return ((a % k) + (b % k)) % k;
}

bool f(int index, int sum)
{	
	if(index == n && sum % k == 0) return true;
	if(index == n) return false;
	if(dp[index][sum + k]) return false;
	
	dp[index][sum + k] = true;
	return f(index + 1, soma(sum, vet[index])) || f(index + 1, soma(sum, -vet[index]));
}

int main()
{
	int TC; scanf("%d", &TC);
	
	while(TC--)
	{
		scanf("%d %d", &n, &k);
		
		for (int i = 0; i < n; i++)
		{
			scanf("%d", &vet[i]);
			vet[i] = vet[i] % k;
		}
		
		memset(dp, 0, sizeof(dp));
		
		if(f(0, 0))
			printf("Divisible\n");
		else
			printf("Not divisible\n");
	}
}
