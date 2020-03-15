#include <stdio.h>
#include <map>
#include <set>

using namespace std;

int next_a(int a)
{
	return ((a * a) % 1000000) / 100;
}

int main()
{
	int a;
	while(scanf("%d", &a) && a)
	{
		set<int> SET;
		
		while(SET.find(a) == SET.end())
		{
			SET.insert(a);
			a = next_a(a);
		}
		
		printf("%d\n", (int)SET.size());
	}
}
