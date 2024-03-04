#include<bits/stdc++.h>
using namespace std;

void solve(){
    int Q;
    cin >> Q;
    string s;
    string t;
    int r;
    map<string, int> q;
    while (Q--)
    {
        cin >> s;
        if (s == "add")
        {
            cin >> t >> r;
            if (q.count(t))
            {
                q[t]=r;
            }
            else
            {
                q.insert({t, r});
            }
        }
        else if (s == "erase")
        {
            cin>>t;
            if (q.count(t))
            {
                q.erase(t);
            }
        }
        else if (s == "print")
        {
            cin>>t;
            if (q.count(t))
            {
                cout<<q[t]<<endl;
            }
            else
            {
                cout << 0 << endl;
            }
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