#include<bits/stdc++.h>
using namespace std;

void solve(){
    int Q;
    cin>>Q;
    string s;
    int t;
    deque<int> d;
    for (int i = 0; i < Q; i++)
    {
        cin>>s;
        if (s=="insertback")
        {
            cin>>t;
            d.push_back(t);
        }
        else if (s=="eraseback")
        {
            if (d.size()!=0)
            {
                d.pop_back();
            }
            
        }
        else if (s=="insertfront")
        {
            cin>>t;
            d.push_front(t);
        }
        else if (s=="erasefront")
        {
            if (d.size()!=0)
            {
                d.pop_front();
            }
        }
        else if (s=="printfront")
        {
            if (d.size()!=0)
            {
                cout<<d.front()<<endl;
            }
            else
            {
                cout<<0<<endl;
            }
        }
        else if (s=="printback")
        {
            if (d.size()!=0)
            {
                cout<<d.back()<<endl;
            }
            else
            {
                cout<<0<<endl;
            }
        }
        else if (s=="print")
        {
            cin>>t;
            if (d.size()==0||t>d.size()-1)
            {
                cout<<0<<endl;
            }
            else
            {
                
                auto it = d.begin();
                cout<<*(it+t)<<endl;
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