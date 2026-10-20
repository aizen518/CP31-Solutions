  // Problem: Contrast Values
  //   Codeforces: 1832C
  //   Rating: 1200
  //   Topic: Greedy and implementation
  //   Link: https://codeforces.com/problemset/problem/1832/C

  //   Approach:
  //   Firstly we can ignore the equal elements like 1,4,4,6 can be seen as 1,4,6.
  //   Annd after observing its clear the sorted part of vector can be compressed into boundaries.
  //   For 1,3,5,4,2,1,7 we can get the ans as 1,5,1,7. 
  //   So for in the end we just need to know how many times the vector shifts between increase and decrease.
    
  //   Time Complexity: O(n)
  //   Space Complexity: O(n)

#include <bits/stdc++.h>
using namespace std;
 
using ll=long long;
 
void solve() {
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0; i<n; i++) cin>>a[i];
    int ans = 1, prev = 0;
    for(int i=1; i<n; i++){
        if(a[i] > a[i-1] && prev != 1){
            ans++;
            prev = 1;
        }
        else if(a[i] < a[i-1] && prev != -1){
            ans++;
            prev = -1;
        }
    }
    cout<<ans<<"\n";
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    int t;
    cin>>t;
    while(t--) solve();
}