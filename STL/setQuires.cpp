#include<bits/stdc++.h>
using namespace std;
#define int long long
void solve(){
    int Q;
    cin>>Q;
    set<int> s;
    int t, x;
    for (int i = 0; i < Q ; i++)
    {
        cin>>t>>x;
        if (t==1)
        {
            s.insert(x);
        }
        else
        {
            if (s.size()==0)
            {
                cout<<x<<endl;
            }
            else
            {
                auto it = s.lower_bound(x);
                if (it==s.end())
                {
                    cout<<x<<endl;
                    return;
                }
                if ((*it)==x)
                {
                    while ((*it)==x&&it!=s.end())
                    {
                        it++;
                        x++;
                    }
                    cout<<x<<endl;
                    
                }
                else
                {
                    cout<<x<<endl;
                }
                
                
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