#include <stdio.h>
#include <cmath>

using namespace std;

int x, y, d;

void extendedEuclid(int a, int b)
{
	if(b == 0) {x = 1; y = 0; d = a; return; }
	extendedEuclid(b, a % b);
	
	int x1 = y;
	int y1 = x - (a / b) * y;
	
	x = x1;
	y = y1;
}

int main()
{
	int TC; scanf("%d", &TC);
	
	while(TC--)
	{
		int r, s; scanf("%d %d", &r, &s);
		
		int a = int(floor(float(r) / s));
		int b = int(ceil(float(r) / s));
		
		extendedEuclid(a, b);
		int mult = r / d;
		x = x * mult;
		y = y * mult;
		
		printf("%d %d\n", x, y);
	}
}
