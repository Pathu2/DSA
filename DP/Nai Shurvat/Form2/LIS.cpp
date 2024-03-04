#include<bits/stdc++.h>
using namespace std;
int n;
vector<int> arr;
vector<int> dp;

/*Some explanation regarding the form 2*/
/*State in the form 2
The State in the form is of (level, restriction)
in this question as we have been asked to to get the LIS and we are checking it within
the function itself therefore there is no need to have any restriction in this*/

/*The transition
Lets take this as an example, at each index we have to find the best LIS ending at that index
It can be the index or we can append the current element with any of the previous element if the
current element is greater than previous wala and depending on it, we have to take the make

So, if we are able to append then we will make a transition to the prev element and will increase
the length by 1
and will take the max of it*/

/*Time complexity
The formula for the time complexity is no. of states * (1+ avg of tranition)
So here there are n states and for each state in thier can n transition therefore n^2 is the ans*/


int rec(int level)
{
    //basecase
    if(level==n)
    {
        return 0;
    }

    //cache
    if(dp[level]!=-1)
    {
        return dp[level];
    }
    //compute and return
    int ans = 1;
    for(int i = 0;i<level;i++)
    {
        if(arr[level]>arr[i])
        {
            ans = max(ans, 1+ rec(i));
        }
    }
    return dp[level] = ans;

}

void solve(){
    cin>>n;
    arr.resize(n);
    for(int i = 0;i<n;i++)
    {
        cin>>arr[i];
    }
    dp.assign(n, -1);
    int mx = 0;
    for (int i = 0; i < n; i++)
    {
        int val = rec(i);
        if(mx<val)
        {
            mx = val;
        }
    }
    cout<<mx<<endl;
    

}
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    int t=1; while(t--){
        solve();
    }
    return 0;
}