#include<bits/stdc++.h>
using namespace std;
vector<int> dp;
int fibo2(int n , int k)
{
    if(n<=0)
    {
        return 0;
    }
    else if(n==1)
    {
        return 1;
    }
    else if(dp[n]!=-1)
    {
        return dp[n];
    }
    dp[n]=0;
    for(int i = 1;i<=k;i++)
    {
        dp[n]+=fibo2(n-i, k);
    }
    return dp[n];
    /*Here are the getting the sum first and then returning*/
    /*See the tree in the notes and their is nothing to get confuse here*/
}
void solve(){
    int n,k;
    cin>>n>>k;
    dp.assign(n+1, -1);
    cout<<fibo2(n, k)<<endl;
}
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    int t=1; while(t--){
        solve();
    }
    return 0;
}