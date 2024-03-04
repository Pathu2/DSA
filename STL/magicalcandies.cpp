#include<bits/stdc++.h>
using namespace std;
#define int long long
void solve(){
    int N, K;
    cin>>N>>K;
    priority_queue<int> p;
    int t;
    for (int i = 0; i < N; i++)
    {
        cin>>t;
        p.push(t);
    }
    int sum = 0;
    while (K--)
    {
        int max = p.top();
        sum = sum + max;
        max = max/2;
        p.pop();
        p.push(max);
    }
    cout<<sum<<endl;
    
    
}
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    int t; cin>>t; while(t--){
        solve();
    }
    return 0;
}