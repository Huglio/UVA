#include <stdio.h>
#include <vector>
#include <queue>

using namespace std;

vector<int> V[2500];
queue<int> q;

int BFS(int start)
{
	
}

int main()
{
	int E; scanf("%d", &E);
	for(int i = 0; i < E; i++)
	{
		int Friends; scanf("%d", &Friends);
		for(int j = 0; j < Friends; j++)
		{
			int x; scanf("%d", &x);
			V[E].push_back(x);
		}
	}
}
