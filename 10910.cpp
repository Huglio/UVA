#include <stdio.h>
#include <cstring>

using namespace std;

int dp[80][80];

int f(int n, int t)
{
	if(n == 0) return t == 0 ? 1 : 0;
	if(t < 0) return 0;
	if(dp[n][t] != -1) return dp[n][t];
	
	int resp = 0;
	for (int i = 0; i <= t; i++)
		resp += f(n - 1, t - i);
		
	return dp[n][t] = resp;
}

int main()
{
	int TC; scanf("%d", &TC);
	
	while(TC--)
	{
		int n, t, p; scanf("%d %d %d", &n, &t, &p);
		memset(dp, -1, sizeof(dp));
		
		printf("%d\n", f(n, t - (n * p)));
	}
}
