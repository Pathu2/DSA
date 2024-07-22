#include<bits/stdc++.h>
using namespace std;

int move_x[2] = {-1, 0};
int move_y[2] = {0, -1};

bool check(int row, int col, int n, int m){
    if(row>=0 && row<n && col>=0 && col<m){
        return true;
    }
    return false;
}
int n, m;
int arr[1001][1001];
int dp[1001][1001];
int rec(int row, int col){
    //BASE CASE
    
    //PRUNING
    
    //CACHE CHECK
    if(dp[row][col]!=-1){
        return dp[row][col];
    }
    
    //COMPUTE
    int ans = arr[row][col];
    
    for(int i =0;i<2;i++){
        int prev_row = row+move_x[i];
        int prev_col = col+move_y[i];
        if(check(prev_row, prev_col, n, m)){
            ans = max(ans, arr[row][col] + rec(prev_row, prev_col));
        }
    }
    //SAVE AND RETURN
    return dp[row][col] = ans;
}

int main(){
    cin>>n>>m;
    for(int i =0;i<n;i++){
        for(int j =0;j<m;j++){
            cin>>arr[i][j];
        }
    }
    memset(dp, -1, sizeof(dp));
    int ans = rec(n-1, m-1);
    cout<<ans<<endl;
}