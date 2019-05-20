#include <stdio.h>
#include <algorithm>
#include <cstring>
#include <vector>

using namespace std;

int n;

int value[40];
int owt[40];
int wt[40];

int pd[40][1010];

int f(int item, int left)
{
    if(item == n)
        return 0;

    int &p = pd[item][left];

    if(p != -1)
        return p;

    int resp = f(item + 1, left);

    if(left - wt[item] >= 0)
        resp = max(resp, f(item + 1, left - wt[item]) + value[item]);

    return p = resp;
}

vector<int>res;

void rec (int item, int left)
{
    if(item == n)
        return;

    int resp = f (item + 1, left);

    if (left - wt[item] >= 0)
    {
        if (f(item + 1, left - wt[item]) + value[item] >= resp)
        {

            res.push_back(item);
            rec (item + 1, left - wt[item]);
            return;
        }
    }

    rec(item + 1, left);
}

int main()
{
    int seconds, peso;

    bool first = true;
    while(scanf("%d %d", &seconds, &peso) != EOF)
    {
        if(!first)
            printf("\n");
        else
            first = false;

        memset(pd, -1, sizeof pd);
        res.clear();

        scanf("%d", &n);
        for(int i = 0; i < n; i++)
        {
            scanf("%d %d", &owt[i], &value[i]);
            wt[i] = (peso * owt[i]) + (2 * peso * owt[i]);
        }

        printf("%d\n", f(0, seconds));
        rec(0, seconds);
        printf("%d\n", res.size());

        for(int i = 0; i < res.size(); i++)
        {
            printf("%d %d\n", owt[res[i]],value[res[i]]);
        }
    }
}
