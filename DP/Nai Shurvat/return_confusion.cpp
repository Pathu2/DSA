#include<bits/stdc++.h>
using namespace std;

int check(int n)
{
    if(n==0)
    {
        return 1;
    }
    check(n-1);
}

int check1(int n)
{
    if(n==0)
    {
        return 1;
    }
    return check1(n-1);
}
/*In the above two examples it doesnt matter, because you are not performing any operations
and dont want to return its value....its useless to use recurrsion in this case*/

int check2(int n)
{
    if(n<=0)
    {
        return 1;
    }
    return check2(n-1) + check2(n-2);
    /*When we are returning and calling the function i am getting the sum from the base cases
    and in this case, i am returning it such that i will get the sum of the previous 2 levels
    as the value of the current level*/
}

int check3(int n)
{
    if(n<=0)
    {
        return 1;
    }
    check3(n-1) + check3(n-2);
    /*When you just call the function, at the time of the base condition it will return 1
    but in rest of the levels since it is not returning anything only 1 will be their*/
}

void solve(){
    int n;
    cin>>n;
    for(int i = 2; i<=n;i++)
    {
        cout<<"For the level "<<i<<endl;
        cout<<"With return "<<check1(i)<<endl;
        cout<<"Without return "<<check(i)<<endl;
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