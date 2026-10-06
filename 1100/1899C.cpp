  // Problem: Quests
  //   Codeforces: 1899C
  //   Rating: 1100
  //   Topic: Prefix sum, sorting
  //   Link: https://codeforces.com/problemset/problem/1899/C

  //   Approach:
  //   Modified Kadane algorithm by comparing a[i] and a[i-1] for every iteration
  //   If they have same parity we simply start another array from that pt and modify ans by taking maximum of current and new.
  //   If they have different parity we modify curr as maximum of curr+a[i] and a[i] and modify ans .
    
  //   Time Complexity: O(n)
  //   Space Complexity: O(n)


#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin >> n;

    vector<long long> a(n);

    for(int i = 0; i < n; i++){
        cin >> a[i];
    }

    long long curr=a[0], ans=a[0];

    for(int i=1; i<n; i++){

        if(abs(a[i])%2 != abs(a[i-1])%2){
            curr=max(curr+a[i], a[i]);
        }else{
            curr=a[i];
        }
        ans=max(ans, curr);
    }
    cout<<ans<<"\n";
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
