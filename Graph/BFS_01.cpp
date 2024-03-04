#include<bits/stdc++.h>
using namespace std;
int n, m;
vector<vector<pair<int, int>>> g;
vector<int> dis;
/*Theory notes mein likha ho*/
void BFS_01(int sc)
{
    deque<int> dq;
    dq.push_back(sc);
    dis[sc]=0;
    while (!dq.empty())
    {
        int cur = dq.front();
        dq.pop_front();

        for (auto v:g[cur])
        {
            if (dis[v.first]>dis[cur]+v.second)
            {
                dis[v.first]=dis[cur]+v.second;
                if (v.second ==0)
                {
                    dq.push_front(v.first);
                }
                else
                {
                    dq.push_back(v.first);
                }

                
            }
            
        }
        
    }
    
}

void solve(){
    cin>>n>>m;
    g.resize(n+1);
    dis.assign(n+1, 1e9);
    while (m--)
    {
        int a, b, c;
        cin>>a>>b>>c;
        g[a].push_back({b, c});
        g[b].push_back({a, c});
    }
 
    int sc;
    cin>>sc;
    
    BFS_01(sc);
    

}
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    int t=1; while(t--){
        solve();
    }
    return 0;
}