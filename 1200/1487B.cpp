  // Problem: Cat Cycle
  //   Codeforces: 1487C
  //   Rating: 1200
  //   Topic: Maths and Constructive
  //   Link: https://codeforces.com/problemset/problem/1487/B

  //   Approach:
  //   If n is even then they will never meet so the ans is straightforward.
  //   If n is odd then after [n/2] time they meet and for x hours they meet a total of [x/[n/2]] times.
  //   If we add the extra steps to the x and find the position as we did in even case we get the answer.
    
  //   Time Complexity: O(1)
  //   Space Complexity: O(n)
  
#include <bits/stdc++.h>
using namespace std;
 
using ll=long long;
 
void solve() {
    ll n, m;
    cin>>n>>m;
    if(n%2 == 0){
        cout<<(m-1)%n+1<<"\n";
    }
    else{
        ll x=(m-1)/(n/2);
        ll ans=(m-1 + x)%n +1;
        cout<<ans<<"\n";
    }
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    int t;
    cin>>t;
    while(t--) solve();
}