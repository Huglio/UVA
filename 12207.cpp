#include "pch.h"
#include <stdio.h>
#include <queue>
#include <map>
#include <set>
#include <stack>
#include <iostream>

using namespace std;

int main()
{
	freopen("Input.txt", "r", stdin);

	int P, C, Case = 0;
	while (scanf("%d %d", &P, &C) && (P || C))
	{
		Case++;
		printf("Case %d:\n", Case);

		map<int, int> waittime;
		queue<int> q;
		map<int, bool> frontabled;
		stack<int> frontqueue;

		if(P >= C)
			for (int i = 1; i <= C; i++)
				q.push(i);
		else
			for (int i = 1; i <= P; i++)
				q.push(i);

		for (int i = 0; i < C; i++)
		{
			char op; scanf(" %c", &op);

			if (op == 'N')
			{
				while (!frontqueue.empty() && frontabled[frontqueue.top()] == false)
					frontqueue.pop();

				if (frontqueue.size())
				{
					printf("%d\n", frontqueue.top());
					q.push(frontqueue.top());
					frontabled[frontqueue.top()] = false;
					waittime[frontqueue.top()]++;

					frontqueue.pop();
				}
				else
				{
					while (waittime[q.front()])
					{
						waittime[q.front()]--;
						q.pop();
					}

					printf("%d\n", q.front());
					q.push(q.front());
					q.pop();
				}
			}
			else
			{
				int x; scanf("%d", &x);

				frontqueue.push(x);
				frontabled[x] = true;
			}
		}
	}
}