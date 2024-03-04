#include<bits/stdc++.h>
using namespace std;
/*In this question initially we were having the weight in the state and at level are changing
the state with respect to take and taking the maximum value of val accordingly

But in this case we cant keep weight in the state as weight will lead to tle, so in this
case we will do a state rotation that is we will add the value on this state instead of
weight */

int n, W;
vector<int> arr, val;
vector<vector<int>> dp;
int rec(int level, int val_taken)
{
    //pruning
    if(val_taken<0)
    {
        return 1e9;
    }
    if(val_taken==0)
    {
        return 0; 
    }
    //basecase
    if(level==n)
    {
        if(val_taken==0)
        {
            return 0;
        }
        else
        {
            return 1e9;
        }
    }
    //cache
    if(dp[level][val_taken]!=-1)
    {
        return dp[level][val_taken];
    }
    //transition/compute
    int ans  = rec(level+1, val_taken);
    ans =  min(ans, arr[level] + rec(level + 1, val_taken - val[level]));
    return dp[level][val_taken] = ans;
    //return
}

void solve(){
    cin>>n>>W;
    arr.resize(n);
    val.resize(n);
    dp.resize(n);
    
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i]>>val[i];
        sum = sum + val[i];
    }
    for(int i = 0;i<n;i++)
    {
        dp[i].assign(sum+1, -1);
    }
    int ans= -1;
    for(int i = sum; i>=0;i--)
    {
        if(rec(0, i)<=W)
        {
            ans = i;
            break;
        }
    }
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