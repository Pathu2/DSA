#include<bits/stdc++.h>
using namespace std;
#define int long long
int mod =  1e9+7;
struct UnionFind
{
  vector<int> par;
  vector<int> rank;
  void init(int n)
  {
    par.resize(n+1);
    rank.assign(n+1, 1);
    for (int i = 0; i <= n; i++)
    {
        par[i]=i;
    }
  }

  int find(int x)
  {
    if(par[x]==x)
    {
        return x;
    }
    else return par[x]=find(par[x]);
  }

  void merge(int rootx, int rooty)
  {
    if(rank[rootx]>=rank[rooty])
    {
        par[rooty]=rootx;
        rank[rootx] = rank[rootx] + rank[rooty];
    }
    else
    {
        par[rootx]=rooty;
        rank[rooty] = rank[rooty] + rank[rootx];
    }
  }

};
void solve(){
    int n, m;
    cin>>n>>m;
    priority_queue<pair<int, pair<int, int>>> pq;
    UnionFind g_union;
    g_union.init(n);
    while (m--)
    {
        int a, b, c;
        cin>>a>>b>>c;
        pq.push({c, {a, b}});
    }
    int sum  = 0;
    while (!pq.empty())
    {
        int weight = pq.top().first;
        int x= pq.top().second.first;
        int y =pq.top().second.second;
        pq.pop();
        int root_x=g_union.find(x);
        int root_y=g_union.find(y);
        sum = sum + ((g_union.rank[root_x])*(g_union.rank[root_y])*weight)%mod;
        g_union.merge(root_x, root_y);
        
    }
    cout<<sum<<endl;
}
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    int t=1; while(t--){
        solve();
    }
    return 0;
}