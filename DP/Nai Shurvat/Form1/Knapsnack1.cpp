#include<bits/stdc++.h>
using namespace std;
#define int long long 
int n;
int W;
vector<int> w, v;
/*DP time*/
int dp[101][100100];
int rec(int level, int W)
{
    //prunate

    //basecase
    if(level==n)
    {
        return 0;
    }
    //cache check
    if(dp[level][W]!=-1)
    {
        return dp[level][W];
    }

    //compute/transition
    /*In case of form 1 we know that we have two options, either we take or we dont take*/
    /*So just give this two transitions*/
    /*Pehele mat looo and phir if the constraints statisfies either loo ya continue*/
    int ans = rec(level+1, W);
    if(W>=w[level])
    {
        ans =  max(ans, v[level]+rec(level+1, W-w[level]));
    }
    //return
    return dp[level][W]=ans;
}

void solve(){
    cin>>n>>W;
    w.resize(n);
    v.resize(n);
    for(int i = 0;i<n;i++)
    {
        cin>>w[i]>>v[i];
    }
    memset(dp, -1, sizeof(dp));
    cout<<rec(0, W)<<endl;

}
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    int t=1; while(t--){
        solve();
    }
    return 0;
}