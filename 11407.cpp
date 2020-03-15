#include <stdio.h>
#include <cstring>
#include <algorithm>

using namespace std;

#define inf 1000000

int dp[110][10010];
int vet[110];

int f(int index, int sum)
{
	if(sum == 0) return 0;
	if(index > 100) return inf;
	if(dp[index][sum] != -1) return dp[index][sum];
	
	int resp = f(index + 1, sum);
	
	if(vet[index] <= sum)
	{
		resp = min(resp, 1 + f(index + 1, sum - vet[index]));
		resp = min(resp, 1 + f(index, sum - vet[index]));
	}
	
	return dp[index][sum] = resp;
}

int main()
{
	freopen("in.txt", "r", stdin);
	
	for (int i = 0; i <= 100; i++)
		vet[i] = i * i;
		
	int TC; scanf("%d", &TC);
	
	memset(dp, -1, sizeof(dp));

	while(TC--)
	{	
		int N; scanf("%d", &N);
		printf("%d\n", f(1, N));
	}
}
