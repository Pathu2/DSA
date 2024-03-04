#include<bits/stdc++.h>
using namespace std;

void solve(){
    int Q;
    cin>>Q;
    string s;
    int t;
    vector<int> v;
    for (int i = 0; i < Q; i++)
    {
        cin>>s;
        if (s=="add")
        {
            cin>>t;
            v.push_back(t);
        }
        else if(s=="remove")
        {
            if (v.size()!=0)
            {
                v.erase(v.end()-1);
            }  
        }
        else if(s=="print")
        {
            cin>>t;
            if(v.size()==0||t>=v.size())
            {
                cout<<0<<endl;
            }
            else
            {
                cout<<v[t]<<endl;
            }
        }
        else if(s=="clear")
        {
            v.erase(v.begin(), v.end());
        }
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