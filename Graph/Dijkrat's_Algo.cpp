/*We see dijkstra's algo to finf the single soure shortes path*/
/*Its time complexity is equal is O((E+V)log(E))*/
/*Explanation is there in the theory*/

#include<bits/stdc++.h>
using namespace std;
int n, m;
#define ii pair<int, int>
#define lli long long
vector<vector<ii>> g;
vector<lli> dis;
void dijkrats(int sc)
{
    dis[sc]=0;
    priority_queue<ii> pq;
    pq.push(make_pair(-0, sc));

    while (!pq.empty())
    {
        ii cur = pq.top();
        pq.pop();

        for(auto v:g[cur.second])
        {
            if (dis[v.first]>dis[cur.second]+v.second)
            {
                dis[v.first]=dis[cur.second]+v.second;
                pq.push(make_pair(-dis[v.first], v.second));
            }
            
        }
    }
    
}

void solve(){
    cin>>n>>m;
    g.resize(n+1);
    dis.resize(n+1, 1e18);
    while (m--)
    {
        int a, b, c;
        cin>>a>>b>>c;
        g[a].push_back({b,c});
        g[b].push_back({a,c});
    }
    dijkrats(1);
    cout<<dis[n]<<endl;

    
}
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    int t=1; while(t--){
        solve();
    }
    return 0;
}