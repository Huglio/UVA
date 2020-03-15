#include <stdio.h>
#include <vector>
#include <bitset>
#include <queue>
#include <cmath>
#include <algorithm>

using namespace std;

#define ll long long int
#define MOD 10
#define ii pair<int, int>

int gcd(int a, int b)
{
	if(b == 0) return a;
	
	return gcd(b, a % b);
}

int main()
{
	int n, k;
	while(scanf("%d %d", &n, &k) != EOF)
	{
		vector<pair<double, ii> > sequence;
		sequence.push_back(pair<double, ii>(1, ii(1, 1)));
		
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				if(i != j && gcd(i, j) == 1)
					sequence.push_back(pair<double, ii>(double(i)/j, ii(i, j)));
					
		sort(sequence.begin(), sequence.end());
		
		printf("%d/%d\n", sequence[k - 1].second.first, sequence[k - 1].second.second);
	}
}
