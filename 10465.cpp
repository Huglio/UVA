#include <stdio.h>
#include <algorithm>
#include <cstring>

using namespace std;

#define inf 1000000

int main()
{
	int n, m, t;
	
	while(scanf("%d %d %d", &n, &m, &t) != EOF)
	{
		int dp[10010];
		
		for (int i = 0; i <= t; i++) dp[i] = -1;
		dp[0] = 0;
		
		for (int i = 0; i <= t; i++)
		{
			if(n <= i && dp[i - n] != -1)
				dp[i] = max(dp[i], 1 + dp[i - n]);
			if(m <= i && dp[i - m] != -1)
				dp[i] = max(dp[i], 1 + dp[i - m]);
		}
		
		if(dp[t] != -1)
			printf("%d\n", dp[t]);
		else
		{
			int i;
			for(i = t; i >= 0 && dp[i] == -1; i--);
			
			printf("%d %d\n", dp[i], t - i);
		}
	}
}
