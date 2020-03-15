#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

#define ii pair<int, int>
#define inf 3005

vector<ii> V;

int pd[1010][3010];

int f(int index, int sum)
{
	if(index >= (int)V.size()) return 0;
	if(pd[index][sum] != -1) return pd[index][sum];
	
	int resp = f(index + 1, sum);
	
	if(V[index].first <= sum)
		resp = max(resp, 1 + f(index + 1, min(sum - V[index].first, V[index].second)));
	
	return pd[index][sum] = resp;
}

int main()
{
	freopen("in.txt", "r", stdin);
	
	int n;
	while(scanf("%d", &n) && n)
	{
		V.clear();
		memset(pd, -1, sizeof(pd));
		
		for (int i = 0; i < n; i++)
		{
			int x, y; scanf("%d %d", &x, &y);
			V.push_back(ii(x, y));
		}
		
		printf("%d\n", f(0, 6005));
	}
}
