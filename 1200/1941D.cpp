  // Problem: Plus Minus Permutations
  //   Codeforces: 1941D
  //   Rating: 1200
  //   Topic: Sorting, Greedy
  //   Link: https://codeforces.com/problemset/problem/1941/D

  //   Approach:
  //   The index commonly divisible by x and y can be ignored.
  //   Give the other indexes divisible by x the largest elements and y the smallest.
    
  //   Time Complexity: O(1)
  //   Space Complexity: O(1)
  

#include <bits/stdc++.h>
using namespace std;

using ll=long long;

void solve() {
    ll n, x, y;
    cin>>n>>x>>y;

    ll sx, sy;
    ll a = n/x;
    ll b = n/y;
    ll c = (x*y)/(gcd(x, y));
    ll d = n/c;
    a-=d;
    b-=d;

    sx = ((2*n - a + 1)*a)/2;
    sy = ((b + 1)*b)/2;

    cout<<sx-sy<<"\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin>>t;
    while(t--) solve();
}