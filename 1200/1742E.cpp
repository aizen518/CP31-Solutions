  // Problem: Scuza
  //   Codeforces: 1742E
  //   Rating: 1200
  //   Topic: Greedy and Sorting
  //   Link: https://codeforces.com/problemset/problem/1742/E

  //   Approach:
  //   The approach used here is using loops on the vector a and for each i
  //   we just mark the and for b[j] less than a[i] equal to the sum until then.

  //   The second approach is using binary search. We can make a vector v(n) where
  //   v[i] is the greatest element until ith element of a.
  //   v(n) will be surely a sorted vector and we can use binary search to
  //   find the upper bound and hence get answer.
    
  //   Time Complexity: O(n logn)
  //   Space Complexity: O(n)
  
#include <bits/stdc++.h>
using namespace std;
 
using ll=long long;
 
void solve() {
    int n, q;
    cin>>n>>q;
    vector<int> a(n);
    for(int i=0; i<n; i++) cin>>a[i];
    vector<pair<int,int>> b(q);
    for(int i=0; i<q; i++){
        cin>>b[i].first;
        b[i].second=i;
    }
    sort(b.begin(), b.end());
    
    vector<ll> ans(q);
    ll sum=0;
    int j = 0;
    for(int i=0; i<n && j<q; i++){
        while(j<q && b[j].first < a[i]){
            ans[b[j].second] = sum;
            j++;
        }
 
        sum += (1LL * a[i]);
    }
    while(j<q){
        ans[b[j].second] = sum;
        j++;
    }
    for(int i=0; i<q; i++){
        cout<<ans[i]<<" ";
    }
    cout<<"\n";
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    int t;
    cin>>t;
    while(t--) solve();
}