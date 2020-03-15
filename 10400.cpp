#include <stdio.h>
#include <cstring>
#include <stack>

using namespace std;

int vet[110];
bool dp[110][64010];
stack<char> resp;

int n, target;

bool f(int index, int sum)
{
	if(index == n) return sum == target ? true : false;
	if(dp[index][sum + 32000]) return false;
	
	dp[index][sum + 32000] = true;
	
	if(sum + vet[index] <= 32000)
	{
		if(f(index + 1, sum + vet[index]))
		{
			resp.push('+');
			return true;
		}
	}
	if(sum - vet[index] >= -32000)
	{
		if(f(index + 1, sum - vet[index]))
		{
			resp.push('-');
			return true;
		}
	}
	if(sum%vet[index] == 0)
	{
		if(f(index + 1, sum/vet[index]))
		{
			resp.push('/');
			return true;
		}
	}
	if(sum * vet[index] <= 32000 && sum * vet[index] >= -32000)
	{
		if(f(index + 1, sum * vet[index]))
		{
			resp.push('*');
			return true;
		}
	}
	
	return false;
}

int main()
{
	freopen("in.txt", "r", stdin);
	
	int TC; scanf("%d", &TC);
	
	while(TC--)
	{
		memset(dp, 0, sizeof(dp));
		
		scanf("%d", &n);
		
		for(int i = 0; i < n; i++)
			scanf("%d", vet + i);
			
		scanf("%d", &target);
		
		if(f(1, vet[0]))
		{
			printf("%d", vet[0]);
			for(int i = 1; i < n; i++)
			{
				printf("%c", resp.top()); resp.pop();
				printf("%d", vet[i]);
			}
			printf("=%d\n", target);
		}
		else
			printf("NO EXPRESSION\n");
	}
}
