#include<bits/stdc++.h>
using namespace std;
int N;
int K;
vector<int> arr;
vector<int> sol;

void rec(int level)
{
    /*1.st is the level, we are at which level*/

    /*2nd is the choice whether we have to take it or not*/

    /*3rd is the check that the size of my solution arr should be less than or equal to k
    If it is less than K, then only we will take the next one else not*/

    /*4th is the move that once the choice n check is done then we have to move
    to next level and do the same accordingly*/

    /*Now, remember that we have to go to each and every subset possible
    therefore and have to go each node of the recursive tree which we are generating 
    and take dicision accordingly*/

    //base case
    if (level==N)
    {
        if (sol.size()==K)
        {
            for (int i = 0; i < sol.size(); i++)
            {
                cout<<sol[i]<<" ";
            }
            cout<<endl;  
        }
        return;
    }

    if (sol.size()<K)
    {
        sol.push_back(arr[level]);
        rec(level+1);
        sol.pop_back();
    }

    rec(level + 1);
    //for not taking the element at this level
    

}

void solve(){
    
    cin>>N>>K;
    arr.resize(N);
    for (int i = 0; i < N; i++)
    {
        cin>>arr[i];
    }

    //call the recursive fuction with the level 0
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