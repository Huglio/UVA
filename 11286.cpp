#include "pch.h"
#include <stdio.h>
#include <map>
#include <algorithm>
#include <string>

using namespace std;


class Curse
{
public:
	int Input[5];

	bool operator < (const Curse B) const
	{
		long long int x = Input[0] + (1000 * Input[1]) + (1000000 * Input[2]) + (1000000000 * Input[3]) + (1000000000000 * Input[4]);
		long long int y = B.Input[0] + (1000 * B.Input[1]) + (1000000 * B.Input[2]) + (1000000000 * B.Input[3]) + (1000000000000 * B.Input[4]);

		return x > y;
	}


	bool operator ==(const Curse B) const
	{
		return B.Input[0] == Input[0] && B.Input[1] == Input[1] && B.Input[2] == Input[2] && B.Input[3] == Input[3] && B.Input[4] == Input[4];
	}
};

int main()
{
	freopen("Input.txt", "r", stdin);

	int N;
	while (scanf("%d", &N) && N)
	{
		map<Curse, int> M;
		int Matrix[10000][5];

		for (int i = 0; i < N; i++)
		{
			Curse x;
			for (int j = 0; j < 5; j++)
			{
				scanf("%d", &x.Input[j]);
			}
			sort(x.Input, x.Input + 5);

			M[x]++;
		}


		int MaxRepeats = 1;
		int sum = 0;
		for (map<Curse, int>::iterator It = M.begin(); It != M.end(); It++)
		{
			if (It->second == MaxRepeats)
				sum += MaxRepeats;
			else if (It->second > MaxRepeats)
			{
				MaxRepeats = It->second;
				sum = MaxRepeats;
			}
		}

		printf("%d\n", sum);
	}
}