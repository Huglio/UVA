#include <stdio.h>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;

int n, k;
int input[30];

int pd[25][10000];

int f(int i, int rest)
{
	if(i >= n)
		return rest;
	
	if(pd[i][rest] != -1)
		return pd[i][rest];
	
	int resp = f(i + 1, rest);
	
	if(rest - input[i] >= 0)
	{
		resp = min(resp, f(i + 1, rest - input[i]));
	}
		
	return pd[i][rest] = resp;
}

vector<int> V;

void rec(int i, int rest)
{
	if(i >= n)
		return;
		
	int resp = f(i + 1, rest);
	
	if(rest - input[i] >= 0 && f(i + 1,rest - input[i]) < resp)
	{
		V.push_back(input[i]);
		rec(i + 1, rest - input[i]);
		return;
	}
	else
		rec(i + 1, rest);
}

int main()
{
	while(scanf("%d %d", &k, &n) != EOF)
	{
		memset(pd, -1, sizeof pd);
		
		V.clear();
		for(int i = 0; i < n; i++)
		{
			scanf("%d", &input[i]);
		}
		
		int sum = 0;
		sum = f(0, k);
		sum = k - sum;
		
		rec(0, k);	
		
		if(V.size() > 0)
		{
			printf("%d", V[0]);
			for(int i = 1; i < (int)V.size(); i++)
				printf(" %d", V[i]);
		}
		printf(" sum:%d\n", sum);
		
	}
}
