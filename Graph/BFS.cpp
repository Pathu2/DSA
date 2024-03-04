#include<bits/stdc++.h>
using namespace std;
/*We will be using bfs here....
What is bfs? In BFS we first visited the neighbour of the particular node and then to their 
neighbouring nodes...we will use queue in this case like first we will push the neighbouring
nodes in the queue and then will explore each of them..
We can use bfs for the shortest path finding in case of unweighted graphs because in case of
DFS we have a random path to go to the neighbour...but in case of BFS we go from neighbour
to neighbour to the same so we can have a shortest path... */

/*There are two forms of graph..one is explicit..that is our normal way of nodes and all
another is implicit ..in this we have been a 2d grid where each cell works like a different
node*/

/*So in this question we have been given a 2d grid/matrix with a starting point and a ending
point with some cells as empty represented by dots and some have walls where we cant go..
in this we have to find the shortest path from starting to ending point and have to
print the number of moves needed to achieve the same*/

/*We are going to use bfs here to find the shortest path*/

int n, m;
vector<string> arr;
vector<vector<int>> dis;
int dx[]={1, 0, -1, 0};
int dy[]={0, -1, 0, 1};
void bfs(pair<int, int> st, pair<int, int> en)
{
    queue<pair<int, int>> q;
    q.push(st);
    dis[st.first][st.second]=0;
    while (!q.empty())
    {
        pair<int, int> cur = q.front();
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int nx = cur.first+dx[i];
            int ny = cur.second+dy[i];
            if (nx>=0 && nx<n && ny>=0 && ny<m && arr[nx][ny]!='#')
            {
               
                if (dis[nx][ny]>dis[cur.first][cur.second]+1)
                {
                    dis[nx][ny]=dis[cur.first][cur.second]+1;
                    q.push(make_pair(nx, ny));
                }
            }
            
        }
        
    }
    
    
}

void solve(){
    cin>>n>>m;
    arr.resize(n);
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    /*We have taken input here...we will taking each row as a input*/
    pair<int, int> st, en;
    /*How to assign distance 1e9 to each cell in the using assign*/
    dis.resize(n);
    for (int i = 0; i < n; i++)
    {
        dis[i].assign(m, 1e9);
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (arr[i][j]=='S')
            {
                st = make_pair(i, j);
            }
            else if (arr[i][j]=='E')
            {
                en = make_pair(i, j);
            }
        }
        
    }
    bfs(st, en);
    cout<<dis[en.first][en.second]<<endl;
}
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    int t=1; while(t--){
        solve();
    }
    return 0;
}