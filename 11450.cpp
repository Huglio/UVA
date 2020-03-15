#include <stdio.h>
#include <cstring>
#include <algorithm>

using namespace std;

#define inf 1000000

int pd[410][210];
int models[30];
int vet[410];
int c;

int f(int index, int sum, int cnt)
{
	if(cnt == c) return sum;
	if(index == models[cnt]) return inf;
	if(pd[index][sum] != -1) return pd[index][sum];
	
	int resp = f(index + 1, sum, cnt);
	
	if(vet[index] <= sum)
		resp = min(resp, f(models[cnt], sum - vet[index], cnt + 1));
		
	return pd[index][sum] = resp;
}

int main()
{
	freopen("in.txt", "r", stdin);
	
	int TC; scanf("%d", &TC);
	
	while(TC--)
	{
		int m, cnt = 0; scanf("%d %d", &m, &c);
		memset(pd, -1, sizeof(pd));
		
		for (int i = 0; i < c; i++)
		{
			int k; scanf("%d", &k);
			
			for (int j = 0; j < k; j++)
				scanf("%d", &vet[cnt++]);
				
			models[i] = cnt;
		}
		
		int resp = f(0, m, 0);
		
		if(resp == inf)
			printf("no solution\n");
		else
			printf("%d\n", m - resp);
	}
}
