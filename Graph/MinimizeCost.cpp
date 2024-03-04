#include<bits/stdc++.h>
using namespace std;
vector<vector<pair<int, pair<int, int>>>> g;
vector<vector<int>> dist;
int c[10001];
void dj(pair<int, int> st, int k)
{
    dist[st.first][st.second] = 0;
    priority_queue<pair<int, pair<int, int>>> pq;
    pq.push(make_pair(-0, st));
    while (!pq.empty())
    {
        pair<int, pair<int, int>> cur = pq.top();
        pq.pop();

        //visited condition....wait for it

        for (auto v: g[cur.second.first])
        {
           if (cur.second.second>=v.second.first)
           {
                if(dist[v.first][cur.second.second-v.second.first]>(-cur.first)+(0));
                pq.push(make_pair(-dist[v.first][cur.second.second-v.second.first], make_pair(v.first, cur.second.second-v.second.first)));
           }
           
        }

        //the nodes, in the formulated graph, some of them is of refill as well
        //refilling 
        if (cur.second.second<k)
        {
            if(dist[cur.second.first][cur.second.second+1]>dist[cur.second.first][cur.second.second]+c[cur.second.first]);
            dist[cur.second.first][cur.second.second+1]=dist[cur.second.first][cur.second.second]+c[cur.second.first];
            pq.push(make_pair(-dist[cur.second.first][cur.second.second+1], make_pair(cur.second.first, cur.second.second+1)));
        }
        
    }
    
}

void solve(){
    int n, m, k;
    cin>>n>>m>>k;
    g.resize(n+1);
    dist.resize(n+1);
    for (int i = 0; i <= n; i++)
    {
       dist[i].assign(k+1, 1e9);
    }
    
    while (m--)
    {
        int a, b;
        cin>>a>>b;
        int p,d;
        cin>>p>>d;
        g[a].push_back(make_pair(b, make_pair(p, d)));
        g[b].push_back(make_pair(a, make_pair(p, d)));
    }
    pair<int, int> state = {1, 0};
    //Defining the initial state, that is i am first node and have fuel equal to zero
    dj(state, k);
    cout<<dist[n][0]<<endl;
}
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    int t=1; while(t--){
        solve();
    }
    return 0;
}