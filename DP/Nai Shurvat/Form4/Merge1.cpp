/*When to use form4?
We casn use form 4 when the size of the array is changing...like in the question
We can use it when all are elements gets merge into the single element
or their is change in length of the subarray...matlab jese iss question mein ho rha ki
length change ho rahi toh agli baar process karne ke lia mujhe array ko bhi change ko
bhi change karna padega....in such type of question we generally dont use form2 we an use form4
in such cases*/

#include<bits/stdc++.h>
using namespace std;
int n;
vector<int> arr;
vector<vector<int>> dp; 
int rec(int l, int r)
{
    //pruning

    //basecase
    if(l==r)
    {
        return 0;
    }
    //cache
    if(dp[l][r]!=-1)
    {
        return dp[l][r];
    }
    //compute/transition
    int ans = 0;
    int sum = 0;
    int tot = 0;
    for (int mid = l; mid <= r; mid++)
    {
        tot= tot + arr[mid];
    }
    for(int mid=l;mid<r;mid++)
    {
        sum = sum + arr[mid];
        ans =  max(ans, rec(l, mid) + rec(mid+1, r) + ((sum)*(tot-sum))%100);
    }
    return dp[l][r] = ans;
    //return
}

void solve(){
    cin>>n;
    arr.resize(n);
    dp.resize(n);
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
        dp[i].assign(n, -1);
    }
    cout<<rec(0, n-1)<<endl;

            
}
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    int t=1; while(t--){
        solve();
    }
    return 0;
}