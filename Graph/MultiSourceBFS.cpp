#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> p_dis;
vector<vector<int>> m_dis;
int dx[]={1, 0, -1, 0};
int dy[]={0, -1, 0, 1};
void solve(){
    int n, m;
    cin>>n>>m;
    vector<string> arr;
    arr.resize(n); 
    queue<pair<int, int>> person;
    queue<pair<int, int>> monster;

    p_dis.resize(n);
    m_dis.resize(n);
    for (int i = 0; i < n; i++)
    {
        p_dis[i].assign(m, 1e9);
        m_dis[i].assign(m, 1e9);
    }


    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
        for (int j = 0; j < m; j++)
        {
            if (arr[i][j]=='A')
            {
                person.push(make_pair(i, j));
                p_dis[i][j]=0;
            }
            else if(arr[i][j]=='M')
            {
                monster.push(make_pair(i, j));
                m_dis[i][j]=0;
            }
            
        }
        
    }

    while (!person.empty())
    {
        pair<int, int> cur = person.front();
        person.pop();
        for (int i = 0; i < 4; i++)
        {
            int nx = cur.first + dx[i];
            int ny = cur.second + dy[i];
            if (nx>=0 && nx<n && ny>=0 && ny<m && arr[nx][ny]!='#')
            {
                if (p_dis[nx][ny]>p_dis[cur.first][cur.second]+1)
                {
                    p_dis[nx][ny]=p_dis[cur.first][cur.second]+1;
                    person.push(make_pair(nx, ny));
                }
                
            }
            
        }
        
    }

    while (!monster.empty())
    {
        pair<int, int> cur = monster.front();
        monster.pop();
        for (int i = 0; i < 4; i++)
        {
            int nx = cur.first + dx[i];
            int ny = cur.second + dy[i];
            if (nx>=0 && nx<n && ny>=0 && ny<m && arr[nx][ny]!='#')
            {
                if (m_dis[nx][ny]>m_dis[cur.first][cur.second]+1)
                {
                    m_dis[nx][ny]=m_dis[cur.first][cur.second]+1;
                    monster.push(make_pair(nx, ny));
                }
                
            }
            
        }
        
    }
    int min_dis = n*m;
    bool exit = false;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (i==0 || i==n-1 || j==0 || j==m-1)
            {
                if (p_dis[i][j]<m_dis[i][j])
                {
                    exit=true;
                    min_dis = min(min_dis, p_dis[i][j]);
                }
                
            }
            else
            {
                continue;
            }
            
            
        }
        
    }
    if (exit)
    {
        cout<<"YES"<<endl;
        cout<<min_dis<<endl;
    }
    else
    {
        cout<<"NO"<<endl;
    }
    
    
    
    
}
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    int t=1; while(t--){
        solve();
    }
    return 0;
}
