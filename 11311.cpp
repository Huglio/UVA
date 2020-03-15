#include <stdio.h>
#include <map>
#include <set>

using namespace std;

int main()
{
	int TC; scanf("%d", &TC);
	
	while(TC--)
	{
		int m, n, r, c; scanf("%d %d %d %d", &m, &n, &r, &c);
		m--, n--;
		
		int nim1 = c;
		int nim2 = n - c;
		int nim3 = r;
		int nim4 = m - r;
		
		if(nim1 ^ nim2 ^ nim3 ^ nim4)
			printf("Gretel\n");
		else
			printf("Hansel\n");
	}
}
