#include "pch.h"
#include <stdio.h>
#include <map>
#include <set>
#include <stack>
#include <vector>
#include <iostream>
#include <queue>

using namespace std;

class mycomparison
{
public:
	bool operator () (const int a, const int b)
	{
		return a < b;
	}
};

int main()
{
	freopen("Input.txt", "r", stdin);

	int N; scanf("%d", &N);

	while (N--)
	{
		int B, SG, SB;
		scanf("%d %d %d", &B, &SG, &SB);

		priority_queue<int, vector<int>, mycomparison> greenq;
		priority_queue<int, vector<int>, mycomparison> blueq;

		for (int i = 0; i < SG; i++)
		{
			int x; scanf("%d", &x);
			greenq.push(x);
		}

		for (int i = 0; i < SB; i++)
		{
			int x; scanf("%d", &x);
			blueq.push(x);
		}

		while (!greenq.empty() && !blueq.empty())
		{
			vector<int> greensurvivors;
			vector<int> bluesurvivors;

			for (int i = 0; i < B && !greenq.empty() && !blueq.empty(); i++)
			{
				int green = greenq.top();
				int blue = blueq.top();

				if (green > blue)
					greensurvivors.push_back(green - blue);
				else if (blue > green)
					bluesurvivors.push_back(blue - green);

				greenq.pop();
				blueq.pop();
			}

			for(int i = 0; i < greensurvivors.size(); i++)
				greenq.push(greensurvivors[i]);

			for(int i = 0; i < bluesurvivors.size(); i++)
				blueq.push(bluesurvivors[i]);
		}

		if (greenq.empty() && blueq.empty())
			printf("green and blue died\n");
		else if (greenq.empty())
		{
			printf("blue wins\n");
			while (!blueq.empty())
			{
				printf("%d\n", blueq.top());
				blueq.pop();
			}
		}
		else
		{
			printf("green wins\n");
			while (!greenq.empty())
			{
				printf("%d\n", greenq.top());
				greenq.pop();
			}
		}
		if (N)
			printf("\n");
	}
}