#include <stdio.h>
#include <vector>

using namespace std;

vector<int> adjlist[100010];
int paths[100010];

int dfs(int at)
{
    if(paths[at] != -1) return paths[at];
    if(!(int)adjlist[at].size()) return paths[at] = 1;

    int resp = 0;
    for(int to : adjlist[at])
    {
        resp += dfs(to);
    }

    return paths[at] = resp;
}

int main()
{
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);

    int n;

    int t = 1;
    while(scanf("%d", &n) != EOF)
    {
        for(int i = 0; i <= n; i++) paths[i] = -1;
        for(int i = 0; i <= n; i++) adjlist[i].clear();

        for(int i = 0; i < n; i++)
        {
            int x; scanf("%d", &x);

            for(int j = 0; j < x; j++)
            {
                int y; scanf("%d", &y);
                adjlist[i].push_back(y);
            }
        }

        if(t++ - 1)
            printf("\n");
        printf("%d\n",dfs(0));
    }
}
