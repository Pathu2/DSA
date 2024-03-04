#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;

vector<int> sol;
map<int, int> mp;
int n;
void rec(int level)
{
    if (level==n)
    {
        for (int i = 0; i < sol.size(); i++)
        {
            cout<<sol[i]<<" ";
        }
        cout<<endl;
        return;
    }

    for (auto i = mp.begin(); i != mp.end(); i++)
    {
        if (i->second!=0)
        {
            sol.push_back(i->first);
            mp[i->first]--;
            rec(level+1);
            sol.pop_back();
            mp[i->first]++;
        }
        
    }
    return;
    
    
}


void solve(){
    cin>>n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    sort(arr, arr+n);
    for (int i = 0; i < n; i++)
    {
        mp[arr[i]]= mp[arr[i]]+1;
    }
    rec(0);    
    
    
    
}
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    int t=1; while(t--){
        solve();
    }
    return 0;
}