#include "pch.h"
#include <stdio.h>
#include <vector>
#include <set>
#include <bitset>
#include <queue>
#include <map>

using namespace std;

int main()
{
	int N; int Case = 1;
	while (scanf("%d", &N) && N)
	{

		map<int, vector<int> > V;
		set<int> Nodes;

		for (int i = 0; i < N; i++)
		{
			int x, y;
			scanf("%d %d", &x, &y);

			Nodes.insert(x); Nodes.insert(y);
			V[x].push_back(y);
			V[y].push_back(x);
		}

		int x, y;
		while (scanf("%d %d", &x, &y) && (x || y))
		{
			map<int, bool> Check;

			int Start = x;
			int TTL = y;
			int Counter = 0;

			if (Nodes.count(Start))
			{
				queue<int> q;

				int Moves = 0;
				int Nodes_to_next = 0;
				int Nodes_left = 0;

				q.push(Start);
				Check[Start] = true;

				bool Done = false;
				while (!q.empty() && !Done)
				{

					if (Moves > TTL)
						Done = true;
					else
					{
						int r = q.front(); q.pop();
						Counter++;

						for (int i = 0; i < V[r].size(); i++)
						{
							if (!Check[V[r][i]])
							{
								Check[V[r][i]] = true;
								q.push(V[r][i]);
								Nodes_to_next++;
							}
						}

						Nodes_left--;
						if (Nodes_left <= 0)
						{
							Moves++;
							Nodes_left = Nodes_to_next;
							Nodes_to_next = 0;
						}
					}
				}
			}

			printf("Case %d: %d nodes not reachable from node %d with TTL = %d.\n", Case, Nodes.size() - Counter, x, y);
			Case++;
		}
	}
}
