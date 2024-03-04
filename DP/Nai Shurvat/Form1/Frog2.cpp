#include<bits/stdc++.h>
using namespace std;
int n, k;
vector<int> arr;
#define int long long
int rec(int level)
{
    //pruning
    if(level>=n)
    {
        return 1e9;
    }
    //basecase
    if(level==n-1)
    {
        return 0;
    }
    //cache

    //compute/transition
    int ans=1e9;
    for(int i = 1;i<=k;i++)
    {
        if(level+i<=n-1)
        {
            ans=min(ans, abs(arr[level+i]-arr[level])+rec(level+i));
        }
    }
    //return
    return ans;
}

void solve(){
    cin>>n>>k;
    arr.resize(n);
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    cout<<rec(0)<<endl;

    
}
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    int t=1; while(t--){
        solve();
    }
    return 0;
}