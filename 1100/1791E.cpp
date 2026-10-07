  // Problem: Positives and Negatives
  //   Codeforces: 1791E
  //   Rating: 1100
  //   Topic: Greedy, maths
  //   Link: https://codeforces.com/problemset/problem/1791/E

  //   Approach:
  //   The main observation is whether you can make all numbers positive or not. 
  //   As each operation changes 2 signs we can only make all no. positive if the number of negatives are even.
  //   If its odd then we try to the minimise it.
    
  //   Time Complexity: O(n)
  //   Space Complexity: O(n)

#include <bits/stdc++.h>
using namespace std;
 
void solve(){
    int n;
    cin>>n;
    vector<long long> v(n);
    long long ans=0;
    int x=0;
    long long mini=INT_MAX;
    for(int i=0; i<n; i++){
        cin>>v[i];
        mini=min(mini, abs(v[i]));
        if(v[i]<0) x++;
        ans+=abs(v[i]);
    }
    if(x%2==0){
        cout<<ans<<"\n";
    }else{
        cout<<ans-2*mini<<"\n";
    }
}
 
 
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    int t;
    cin >> t;
 
    while(t--){
        solve();
    }
}
