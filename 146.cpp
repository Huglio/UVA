#include <stdio.h>
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
    string Sequence;
    while(cin >> Sequence && Sequence[0] != '#')
    {
        char S[60];
        for(int i = 0; i < Sequence.length(); i++)
        {
            S[i] = Sequence[i];
        }

        if(next_permutation(S, S + Sequence.length()))
            {
                for(int i = 0; i < Sequence.length(); i++)
                    printf("%c", S[i]);
            }
            else
                printf("No Successor");
            printf("\n");
    }
}
