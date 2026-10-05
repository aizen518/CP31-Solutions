  // Problem: Quests
  //   Codeforces: 1914C
  //   Rating: 1100
  //   Topic: Greedy, math
  //   Link: https://codeforces.com/problemset/problem/1914/C

  //   Approach:
  //   We transverse the vector while calculating the possible profit if we stop at every position
  //   Mantain variables for Sum, Ans, Max_b
    
  //   Time Complexity: O(n)
  //   Space Complexity: O(1)



#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n, k;
    cin>>n>>k;
    vector<int> a(n);
    vector<int> b(n);
    for(int i=0; i<n; i++) cin>>a[i];
    for(int i=0; i<n; i++) cin>>b[i];

    int ans=0, maxi=0, sum=0;

    for(int i=0; i<n && i<k; i++){
        maxi=max(maxi, b[i]);
        sum+=a[i];
        int curr=sum + (k-1-i)*maxi;
        ans=max(ans, curr);
    }
    cout<<ans<<"\n";

}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}
