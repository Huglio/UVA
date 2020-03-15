#include <stdio.h>
#include <vector>
#include <queue>
#include <bitset>

using namespace std;

vector<int> Adjlist[110];
int src, dest;
int answer = 0;
int flow[110][110];
int parents[110];

bool MaxFlow()
{
	bitset<110> bs; bs.set();
	queue<int> q;
	
	bs[src] = 0;
	q.push(src);
	
	bool done = false;
	while(!q.empty() && !done)
	{
		int r = q.front(); q.pop();
		
		if(r == dest)
			done = true;
		else
		{
			for(int i = 0; i < (int)Adjlist[r].size(); i++)
			{
				if(bs[Adjlist[r][i]] && flow[r][i])
				{
					bs[Adjlist[r][i]] = 0;
					parents[Adjlist[r][i]] = r;					
					q.push(Adjlist[r][i]);
				}
			}
		}
	}
	
	if(!done)
		return false;
	
	int child = dest;
	while(child != src)
	{
		flow[child][parents[child]] += flow[parents[child]][child];
		answer += flow[parents[child]][child];
		
		flow[parents[child]][child] = 0;
	}
	
	return true;
}

int main()
{
	int n;
	while(scanf("%d", &n) && n)
	{
		answer = 0;
		for(int i = 0; i <= n; i++)
			Adjlist[i].clear();
		
		int m;
		scanf("%d %d %d", &src, &dest, &m);
		
		for(int i = 0; i < m; i++)
		{
			int x, y, z; scanf("%d %d %d", &x, &y, &z);
			Adjlist[x].push_back(y);
			Adjlist[y].push_back(x);
			
			flow[x][y] = z;
			flow[y][x] = 0;
		}
		
		while(MaxFlow());
		
		printf("%d\n", answer);
	}
}
