#include<bits/stdc++.h>
using namespace std;
int n;
vector<int> arr;

int rec(int level, int last_taken)
{
    //basecase
    if(level==n)
    {
        return 0;
    }
    //cache

    //compute
    int ans = rec(level+1, last_taken);
    if(last_taken<arr[level])
    {
        ans =  max(ans, 1 + rec(level+1, arr[level]));
    }
    return ans;
}

void solve(){
    cin>>n;
    arr.resize(n);
    for(int i = 0;i<n;i++)
    {
        cin>>arr[i];
    }
    cout<<rec(0, -1)<<endl;
}
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    int t=1; while(t--){
        solve();
    }
    return 0;
}