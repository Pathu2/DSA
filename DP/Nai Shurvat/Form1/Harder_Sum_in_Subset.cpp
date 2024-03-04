#include<bits/stdc++.h>
using namespace std;
int n, T;
vector<int> a;
int dp[101][1001];
/*Now in this question we have to been given q queries and for each query we will be given the
value of T for which we have to see whether their exits a subarray with sum equal to T*/

/*Now to solve this question according to state which we have used in the last problem is
difficult because our state is dependent on dp and for each query i have to again refresh 
the array dp and all my saved values will be gone. The time limit will be excedded in this*/

/*So to overcome this what we can do is to change the state, such that it becomes independent of T*/

/*To do the same we will set the state to "Level, Sum_left" and at the end level if Sum_left==0 then
return 1 else return 0*/
int subset_sum(int level, int Sum_left)
{
    //bacsecase
    if(level==n)
    {
        if(Sum_left==0)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
    
    //cache check
    if(dp[level][Sum_left]!=-1)
    {
        return dp[level][Sum_left];
    }

    //compute
    int ans = subset_sum(level+1, Sum_left);
    /*Dekho nhi lena is always an option*/
    /*While lena depends on the condition given in the question*/

    if(Sum_left-a[level]>=0)
    {
        ans = ans || subset_sum(level+1, Sum_left-a[level]);
    }

    //return
    return dp[level][Sum_left]=ans;
}

void printset(int level, int Sum_left)
{
    if(level==n)
    {
        return;
    }
    if(subset_sum(level+1, Sum_left))
    {
        printset(level+1, Sum_left);
    }
    else if(subset_sum(level+1, Sum_left-a[level]))
    {
        cout<<a[level]<<" ";
        printset(level+1, Sum_left-a[level]);
    }
}


void solve(){
    cin>>n;
    int q;
    cin>>q;
    a.resize(n);
    for(int i  =0;i<n;i++)
    {
        cin>>a[i];
    }
    memset(dp, -1, sizeof(dp));
    while (q--)
    {
        cin>>T;   
        if(subset_sum(0, T))
        {
            printset(0, T);
            cout<<endl;
        }
        else
        {
            cout<<"No solution"<<endl;
        }
    }
    
    

}
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    int t=1; while(t--){
        solve();
    }
    return 0;
}