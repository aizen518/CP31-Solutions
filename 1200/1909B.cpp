  // Problem: Make Almost Equal With Mod
  //   Codeforces: 1909B
  //   Rating: 1200
  //   Topic: Mod with power of 2 CRAZY OBSERVATION
  //   Link: https://codeforces.com/problemset/problem/1909/B

  //   Approach:
  //   2 will work in most cases only not in the all even and all odd cases.
  //   For all even and odd cases one of the powers of 2 can be the answer.
  //   This can be seen if we follow the powers of 2.
    
  //   Time Complexity: O(n^2)
  //   Space Complexity: O(n)
  
#include <bits/stdc++.h>
using namespace std;

using ll=long long;

void solve() {
    int n;
    cin>>n;
    vector<ll> a(n);
    for(int i=0; i<n; i++) cin>>a[i];

    set<ll> s;
    for(ll i=1; i<57; i++){
        s.clear();
        ll x =1LL << i;
        for(int j=0; j<n; j++){
            s.insert(a[j]%x);
        }
        if(s.size()==2){
            cout<<x<<"\n";
            return;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin>>t;
    while(t--) solve();
}