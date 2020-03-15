#include "pch.h"

#include <iostream>
#include <cstring>

using namespace std;

unsigned long long int dp[65][65];

unsigned long long int trib(int n, int back)
{
	if (n <= 1) return 0;
	if (dp[n][back] != 0) return dp[n][back];

	unsigned long long int sum = 0;
	for (int i = 1; i <= back; i++)
		sum += 1 + trib(n - i, back);

	return dp[n][back] = sum;
}
int main()
{
	memset(dp, 0, sizeof(dp));

	int TC = 1;
	int n, back;
	while (scanf("%d %d", &n, &back) && (n <= 60))
	{
		cout << "Case " << TC++ << ": " << 1 + trib(n, back) << endl;
	}
}