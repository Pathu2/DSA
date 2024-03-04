#include<bits/stdc++.h>
using namespace std;

void solve(){
    int Q;
    cin>>Q;
    string s;
    int t;
    multiset<int> st;
    while (Q--)
    {
        cin >> s;
        if (s == "add")
        {
            cin >> t;
            st.insert(t);
        }
        else if (s == "erase")
        {
            cin>>t;
            auto it = st.find(t);
            if (it!=st.end())
            {
                st.erase(it);  
            }
        }
        else if(s=="eraseall")
        {
            cin>>t;
            if (st.count(t))
            {
                st.erase(t);  
            }

        }
        else if (s == "find")
        {
            cin>>t;
            if (st.count(t))
            {
                cout<<"YES"<<endl;
            }
            else
            {
                cout<<"NO"<<endl;
            }
        }
        else if(s=="count")
        {
            cin>>t;
            int count = 0;
            for (auto it = st.begin(); it!=st.end(); it++)
            {
                if (*it==t)
                {
                    count++;
                }
            }
            cout<<count<<endl;
        }
        else if(s=="print")
        {
            for (auto it = st.begin(); it!=st.end(); it++)
            {
                cout<<*(it)<<" ";
            }
            cout<<endl;
        }
        else if(s=="empty")
        {
            st.erase(st.begin(), st.end());
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