#include<bits/stdc++.h>
using namespace std;

const int Boardsize = 4;
const int Cellsize = 2;
int ans = 0;
int board[Boardsize][Boardsize];

bool check(int val, int row, int col)
{
    /*Check for same row*/
    for (int i = 0; i < col; i++)
    {
        if (board[row][i]==val)
        {
            return false;
        }
    }
    
    /*Check for same column*/
    for (int i = 0; i < row; i++)
    {
        if (board[i][col]==val)
        {
            return false;
        }
    }
    /*Check for same grid*/
    int gridx = (row/Cellsize)*Cellsize;
    int gridy = (col/Cellsize)*Cellsize;
    for (int i = 0; i < Cellsize; i++)
    {
        for (int j = 0; j < Cellsize; j++)
        {
            if (board[i+gridx][j+gridy]==val)
            {
                return false;
            }
            
        } 
    }
    
    return true;
}

void rec(int row, int col)
{
    if (col==Boardsize)
    {
        rec(row+1, 0);
        return;
    }
    
    if (row==Boardsize)
    {
        ans++;
        cout<<"Answer is "<<ans<<endl;
        for (int i = 0; i < Boardsize; i++)
        {
            for (int j = 0; j < Boardsize; j++)
            {
                cout<<board[i][j]<<" ";
            }
            cout<<endl;
        }
        cout<<endl;
        return;
    }
    if (board[row][col]==0)
    {
        for (int i = 1; i <=Boardsize; i++)
        {
            if (check(i, row, col))
            {
                board[row][col]=i;
                rec(row, col+1);
                board[row][col]=0;
            }
            
        }
        
    }
    else
    {
        rec(row, col+1);
    }
}

void solve(){
    for (int i = 0; i < Boardsize; i++)
    {
        for (int j = 0; j < Boardsize; j++)
        {
            cin>>board[i][j];
        }
    }
    rec(0,0);
    /*Our level is cell, so we will pass the column number and row number to the fucntion*/
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