#include<bits/stdc++.h>
using namespace std;

void solve(){
    int N;
    cin>>N;
    vector<int> a(N);
    for (int i = 0; i < N; i++)
    {
        cin>>a[i];
    }
    sort(a.begin(), a.end());
    int X;
    cin>>X;
    auto it = lower_bound(a.begin(), a.end(), X);
    if (it==a.end())
    {
        cout<<-1<<endl;
    }
    else
    {
        cout<<*it<<endl;
    }
    
    
}
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    int t; cin>>t; while(t--){
        solve();
    }
    return 0;
}