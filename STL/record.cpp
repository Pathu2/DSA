#include<bits/stdc++.h>
using namespace std;

bool isfind(string s, vector<string> r)
{

}

void solve(){
    int N;
    cin>>N;
    map<string, int> mp;
    string s;
    for (int i = 0; i < N; i++)
    {
        cin>>s;
        if (mp.count(s))
        {
            mp[s]++;
            cout<<s<<mp[s]<<endl;
        }
        else
        {
            mp[s]=0;
            cout<<"OK"<<endl;
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