#include<bits/stdc++.h>
using namespace std;

void solve(){
    vector<int> v;
    for (int i = 0; i < 5; i++)
    {
        v.push_back(i);
    }
    cout<<v.empty()<<endl;
    cout<<"Size is "<<v.size()<<endl;
    v.erase(v.begin(), v.end());
    cout<<v.empty()<<endl;
    cout<<"Size is "<<v.size()<<endl;
    for (int i = 0; i < 5; i++)
    {
        v.push_back(i);
    }
    cout<<v.empty()<<endl;
    for (int i = 0; i < 5; i++)
    {
        cout<<"Removing "<<*(v.end()-1)<<endl;
        v.erase(v.end()-1);
        cout<<"Size is "<<v.size()<<endl<<endl;
    }
    cout<<v.empty()<<endl;

    
}
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    int t; cin>>t; while(t--){
        solve();
    }
    return 0;
}