#include "pch.h"
#include <stdio.h>
#include <stack>
#include <map>

using namespace std;

int main()
{
	freopen("Input.txt", "r", stdin);

	

	int Tests;
	scanf("%d", &Tests);

	for (int i = 0; i < Tests; i++)
	{
		int SnowflakesRead;
		scanf("%d", &SnowflakesRead);

		int maxsnowflakes = 0, currentsnowflakes = 0;
		map<int, bool> Check;

		stack<int> pilha;
		int x;
		for(int j = 0; j < SnowflakesRead; j++)
		{
			scanf("%d", &x);

			pilha.push(x);

			if (!Check[x])
			{
				Check[x] = true;
				currentsnowflakes++;
			}
			else
			{
				if (currentsnowflakes > maxsnowflakes)
					maxsnowflakes = currentsnowflakes;
				currentsnowflakes = 0;

				stack<int> Backup;

				Backup.push(pilha.top());
				pilha.pop();
				while (pilha.top() != x)
				{
					Backup.push(pilha.top()); pilha.pop();
				}

				pilha.pop();
				Check.clear();

				while (!Backup.empty())
				{
					Check[Backup.top()] = true;
					currentsnowflakes++;
					pilha.push(Backup.top()); Backup.pop();
				}
			}
		}
		if (currentsnowflakes > maxsnowflakes)
			maxsnowflakes = currentsnowflakes;

		printf("%d\n", maxsnowflakes);
	}
}