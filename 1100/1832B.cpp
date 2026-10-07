  // Problem: Maximum Sum
  //   Codeforces: 1832B
  //   Rating: 1100
  //   Topic: Prefix sum, sorting
  //   Link: https://codeforces.com/problemset/problem/1832/B

  //   Approach:
  //   We iterate on k by taking x as no of times we take the smallest 2 and k-x as the times we take the largest one.
    
  //   Time Complexity: O(n)
  //   Space Complexity: O(n)


#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n, k;
    cin >> n >> k;

    vector<long long> a(n);

    for(int i = 0; i < n; i++)
        cin >> a[i];

    sort(a.begin(), a.end());

    vector<long long> prefix(n + 1, 0);

    for(int i = 0; i < n; i++)
        prefix[i + 1] = prefix[i] + a[i];

    long long ans = 0;

    for(int x = 0; x <= k; x++){
        long long curr = prefix[n-k+x] - prefix[2*x];
        ans = max(ans, curr);
    }

    cout << ans << '\n';
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
