#include<bits/stdc++.h>
using namespace std;
int n, T;
vector<int> a;
int dp[101][1001];
/*While thinking regarding the states, in case of form 1 we will definitely have level as
one of our states also the req conditions that have to checked at each level*/
int subset_sum(int level, int S)
{
    //prunate
    /*Not any possible condition to prunate*/

    //bacsecase
    if(level==n)
    {
        if(S==T)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
    /*Basecase will be when we level==n and at that condition if my sum is equal to sum
    given then we can return 1, else return 0*/

    //cache check
    if(dp[level][S]!=-1)
    {
        return dp[level][S];
    }

    //compute
    int ans = subset_sum(level+1, S);
    /*Dekho nhi lena is always an option*/
    /*While lena depends on the condition given in the question*/

    if(T>=S + a[level])
    {
        ans = ans || subset_sum(level+1, S+a[level]);
    }

    /*Compute karna is basically the transition karna....in this we have two possible tra-
    -nsition, one is including while other is excluding, and we have to take the or between two,
    as if anyone is true we can have a true*/

    //return
    return dp[level][S]=ans;
    
}

void solve(){
    cin>>n>>T;
    a.resize(n);
    for(int i  =0;i<n;i++)
    {
        cin>>a[i];
    }
    memset(dp, -1, sizeof(dp));
    cout<<subset_sum(0, 0)<<endl;

}
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    int t=1; while(t--){
        solve();
    }
    return 0;
}