#include<bits/stdc++.h>
using namespace std;
#define int long long
#define float double
int n, m;
vector<vector<pair<int, int>>> g;
vector<int> dist;
vector<pair<pair<int, int>, int>> edge_list;
void dj(int node)
{
    dist[node]=0;
    priority_queue<pair<int, int>> pq;
    pq.push({-0, 1});
    while (!pq.empty())
    {
        int cur_dist = -pq.top().first;
        int cur_node = pq.top().second;
        pq.pop();
        for (auto v: g[cur_node])
        {
            if(dist[v.first]> cur_dist + v.second)
            {
                dist[v.first] = cur_dist + v.second;
                pq.push({-dist[v.first], v.first});
            }
        }
        
    }  
}

float burn(int a, int b, int c)
{
    if(abs(a-b)>=c)
    {
        return (float)c + (float)min(a, b);
    }
    else
    {
        return (float)min(a, b)+ abs(a-b) + (c-abs(a-b))/2.0;
    }
}

void solve(){
    cin>>n>>m;
    g.resize(n+1);
    dist.assign(n+1, 1e9);
    while (m--)
    {
        int a, b, c;
        cin>>a>>b>>c;
        g[a].push_back({b, c});
        g[b].push_back({a, c});
        edge_list.push_back({{a, b}, c});
    }
    int fire;
    cin>>fire;
    dj(fire);
    float max = 0;
    for(auto e: edge_list)
    {
        int a= dist[e.first.first];
        int b = dist[e.first.second];
        int c = e.second;
        float val = burn(a, b, c);
        if(max<val)
        {
            max =  val;
        } 
    }
    cout<<10*max<<endl;
    
}
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    int t=1; while(t--){
        solve();
    }
    return 0;
}