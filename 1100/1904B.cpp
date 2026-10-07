  // Problem: Collecting Game
  //   Codeforces: 1904B
  //   Rating: 1100
  //   Topic: Prefix sum, sorting, dp
  //   Link: https://codeforces.com/problemset/problem/1904/B

  //   Approach:
  //   We sort the array and compare prefix sum with value at next index and do a right to left dp.
    
  //   Time Complexity: O(n logn)
  //   Space Complexity: O(n)

#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin >> n;

    vector<vector<int>> a(n, vector<int>(2,0));

    for(int i = 0; i < n; i++){
        cin >> a[i][0];
        a[i][1]=i;
    }

    sort(a.begin(), a.end());

    vector<long long> prefix(n, 0);
    prefix[0]=a[0][0];

    for(int i = 1; i < n; i++)
        prefix[i] = prefix[i-1] + a[i][0];

    vector<int> ans(n);
    ans[a[n-1][1]]=n-1;

    for(int i=n-2; i>=0; i--){
        if(a[i+1][0] <= prefix[i]){
            ans[a[i][1]]=ans[a[i+1][1]];
        }else{
            ans[a[i][1]]=i;
        }
    }
    for(int i=0; i<n; i++) cout<<ans[i]<<" ";

    cout<<"\n";
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
