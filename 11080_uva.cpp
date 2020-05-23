#include <bits/stdc++.h>
#define MAX 2005
using namespace std;
int n,e;
int Partition[MAX];
bool visit[MAX],f=true;
vector< int > G[MAX];
void is_bipartite(int x)
{
    visit[x]=true;
    Partition[x]=1;
    queue<int>q;
    q.push(x);
    while(!q.empty())
    {
        int y=q.front();
        q.pop();
        for(int i=0; i<G[y].size(); i++)
        {
            int r=G[y][i];
            if(Partition[y]==Partition[r])
            {
                f=false;
            }
            if(visit[r]==false)
            {
                visit[r]=true;
                Partition[r]=3-Partition[y];
                q.push(r);
            }
        }
    }
}
void sob_clear()
{
    for(int i=0; i<MAX; i++)
    {
        G[i].clear();
        Partition[i]=0;
    }
    memset(visit,false,sizeof(visit));
    f=true;
}
int main()
{
    int i, u, v,ca;
    scanf("%d",&ca);
    while(ca--)
    {
        sob_clear();
        scanf("%d", &n);
        scanf("%d", &e);
        for(i = 0; i < e; i++)
        {
            scanf("%d %d", &u, &v);
            G[u].push_back(v);
            G[v].push_back(u);
        }
        int ans=0,j;
        for(i=0; i<n; i++)
        {
            int c1=0,c2=0;
            if(visit[i]==false)
            {
                is_bipartite(i);
                for(j=0; j<n; j++)
                {
                    if(Partition[j]==1)
                        c1++;
                    else if(Partition[j]==2)
                        c2++;
                    Partition[j]=0;
                }
                if(c2==0)ans+=c1;
                else ans+=min(c1,c2);
            }
        }
        if(f==false)printf("-1\n");
        else
            printf("%d\n",ans);
    }
    return 0;
}


