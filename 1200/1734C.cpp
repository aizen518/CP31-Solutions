  // Problem: Removing Smallest Elements
  //   Codeforces: 1734C
  //   Rating: 1200
  //   Topic: Greedy and Maths
  //   Link: https://codeforces.com/problemset/problem/1734/C

  //   Approach:
  //   We can run a loop on the string.
  //   If the number is not to be removed we can simply go to the next number. 
  //   If the number is to be removed we remove it and go to the next multiple of that number. 
  //   For convinience we mantain a bool vector to know which number is removed or not.
    
  //   Time Complexity: O(n)
  //   Space Complexity: O(n)
  
#include <bits/stdc++.h>
using namespace std;

using ll=long long;

void solve() {
    int n;
    cin>>n;
    string s;
    cin>>s;
    vector<bool> r(n+1, false);
    ll ans = 0;
    for(int i=1; i<=n; i++){
        for(int j=i; j<=n; j+=i){
            if(s[j-1] == '1') break;
            else if(r[j]) continue;
            else{
                r[j]=true;
                ans += (1ll*i);
            }
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

