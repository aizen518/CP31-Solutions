  // Problem: Matryoshkas
  //   Codeforces: 1790D
  //   Rating: 1200
  //   Topic: Greedy and Sorting
  //   Link: https://codeforces.com/problemset/problem/1790/D

  //   Approach:
  //   First by sorting you can easily see how we can make long consecutive chains.
  //   If an integer is missing in between we have to start newly so add its whole frequency.
  //   Else if frequncy of the integer is less than that of previous then just add the difference.
    
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
    sort(a.begin(), a.end());
    
    vector<pair<int,int>> b;
    for(int i=0; i<n; i++){
        int curr=1;
        while(i<n-1 && a[i]==a[i+1]){
            curr++;
            i++;
        }
        b.emplace_back(a[i], curr);
    }
    int x = b[0].second;
    for(int i=1; i<b.size(); i++){
        if(b[i].first > b[i-1].first + 1){
            x += b[i].second;
        }else if(b[i].second > b[i-1].second){
            x += (b[i].second - b[i-1].second);
        }
    }
    cout<<x<<"\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin>>t;
    while(t--) solve();
}