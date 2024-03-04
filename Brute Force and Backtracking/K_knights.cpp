#include<bits/stdc++.h>
using namespace std;

int N, K;
int board[14][14];
int ans = 0;
bool check(int row, int col)
{
    if (board[row][col]==1)
    {
        return 0;
    }
    if ((row-2>=0 && row-2<N) && (col+1>=0 && col+1<N) && board[row-2][col+1]==1)
    {
        return 0;
    }
    else if ((row-2>=0 && row-2<N) && (col-1>=0 && col-1<N) && board[row-2][col-1]==1)
    {
        return 0;
    }
    else if ((row+2>=0 && row+2<N) && (col+1>=0 && col+1<N) && board[row+2][col+1]==1)
    {
        return 0;
    }
    else if ((row+2>=0 && row+2<N) && (col-1>=0 && col-1<N) && board[row+2][col-1]==1)
    {
        return 0;
    }
    else if ((row-1>=0 && row-1<N) && (col+2>=0 && col+2<N) && board[row-1][col+2]==1)
    {
        return 0;
    }
    else if ((row+1>=0 && row+1<N) && (col+2>=0 && col+2<N) && board[row+1][col+2]==1)
    {
        return 0;
    }
    else if ((row+1>=0 && row+1<N) && (col-2>=0 && col-2<N) && board[row+1][col-2]==1)
    {
        return 0;
    }
    else if ((row-1>=0 && row-1<N) && (col-2>=0 && col-2<N) && board[row-1][col-2]==1)
    {
        return 0;
    }
    return 1;
}

void rec(int level)
{
    if (level==K)
    {
        ans++;
        return;
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (check(i, j))
            {
                board[i][j]=1;
                rec(level+1);
                board[i][j]=0;
            }
            
        }
        
    }
    
    

}

void solve(){
    cin>>N>>K;
    for(int i =0;i<14;i++)
    {
        for(int j=0;j<14;j++)
        {
            board[i][j]=0;
        }
    }
    rec(0);
    // for (int i = 1; i <=K; i++)
    // {
    //     ans = ans/i;
    // }
    cout<<ans<<endl;
    
}
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    int t; cin>>t; while(t--){
        solve();
    }
    return 0;
}