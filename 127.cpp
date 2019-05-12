#include <stdio.h>
#include <iostream>
#include <bitset>

using namespace std;

int main()
{
    bitset<32> Binary;
    bitset<32> Convert;

    int x;
    while(scanf("%d", &x) != EOF)
    {
        Binary.reset();
        Convert.reset();

        Binary = x;
        for(int i = 3; i >= 0; i--)
        {
            for(int j = 0; j < 8; j++)
            {
                Convert[((3-i)*8)+j] = Binary[(i*8)+j];
            }
        }
        int y = Convert.to_ulong();
        printf("%d converts to %d\n", x, y);
    }
}
