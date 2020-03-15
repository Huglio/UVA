#include <stdio.h>
#include <vector>
#include <cstring>

using namespace std;

#define ll long long int

vector<int> Coins;

int main()
{
	for (int i = 1; i * i * i <= 9261; i++)
		Coins.push_back(i * i * i);
	
	int s;
	while(scanf("%d", &s) != EOF)
	{
		ll vet[10010];
		memset(vet, 0, sizeof(vet));
		vet[0] = 1;
		
		for (int i = 0; i < (int)Coins.size(); i++)
		{
			for(int j = 1; j <= s; j++)
			{
				if(Coins[i] <= j)
				{
					vet[j] += vet[j - Coins[i]];
				}
			}
		}
		
		printf("%lld\n", vet[s]);
	}
}
