#include<bits/stdc++.h>
using namespace std;

void solve(){
    int N, K;
    cin>>N>>K;
    set<int> s;
    int t;
    for (int i = 0; i < N; i++)
    {
        cin>>t;
        s.insert(t);
    }
    // int sum = 0;
    // while (K--)
    // {
    //     auto it = s.rbegin();
    //     sum = sum + *it;

    // }
    auto it = s.rbegin();
    cout<<*it<<endl;
    

    
    
    
    
}
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    int t; cin>>t; while(t--){
        solve();
    }
    return 0;
}