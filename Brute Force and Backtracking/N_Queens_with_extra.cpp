#include<iostream>
#include<vector>
#include<math.h>
using namespace std;
const int Boardsize = 8;

int ans = 0;
vector<int> sol;

bool check(int row, int col)
{
    for (int prow = 0; prow < row; prow++)
    {
        int pcol = sol[prow];
        if (pcol==col || abs(pcol-col)==abs(prow-row))
        {
            return false;
        }
    }
    return true;
    
}

void rec(int level, char Board[][8])
{
    if (level==Boardsize)
    {
        ans++;
        return;
    }

    for (int i = 0; i < Boardsize; i++)
    {
        if (Board[level][i]=='*')
        {
            continue;
        }
        if (check(level , i))
        {
            sol.push_back(i);
            rec(level+1, Board);
            sol.pop_back();
        }
    }
    return;
    
    
}

void solve(){
    char Board[Boardsize][Boardsize];
    for (int i = 0; i < Boardsize; i++)
    {
        for (int j = 0; j < Boardsize; j++)
        {
            cin>>Board[i][j];
        }
        
    }
    rec(0, Board);
    cout<<ans<<endl;
    
    
}
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    int t=1; while(t--){
        solve();
    }
    return 0;
}