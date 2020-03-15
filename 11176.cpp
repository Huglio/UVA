#include <stdio.h>
#include <algorithm>
#include <cstring>

using namespace std;

double memo[510][510][510];
bool dp[510][510][510];

double p;
double f(int index, int best, int streak)
{
	if(index <= 0) return best;
	if(dp[index][best][streak]) return memo[index][best][streak];
	
	double p1 = p * f(index - 1, max(best, streak + 1), streak + 1);
	double p2 = (1 - p) * f(index - 1, best, 0);
	
	dp[index][best][streak] = 1;
	return memo[index][best][streak] = p1 + p2;
}

int main()
{
	freopen("in.txt", "r", stdin);
	
	int n;
	
	while(scanf("%d %lf", &n, &p) && n)
	{
		memset(dp, 0, sizeof(dp));
		printf("%lf\n", f(n, 0, 0));
	}
}
