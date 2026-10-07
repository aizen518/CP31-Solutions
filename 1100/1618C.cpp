// Problem: Paint the Array
//   Codeforces: 1618C
//   Rating: 1100
//   Topic: GCD
//   Link: https://codeforces.com/problemset/problem/1618/C

//   Approach:
//   We divide the array into two groups based on index parity.
//   We find the GCD of all elements at even indices and the GCD of all
//   elements at odd indices. Then we check whether the GCD of one group
//   divides any element of the other group.
//   If it doesn't, that GCD is the answer. Otherwise, we try the GCD
//   of the other group. If neither works, the answer is 0.

//   Time Complexity: O(n log(max(a[i])))
//   Space Complexity: O(n)


#include<bits/stdc++.h>
using namespace std;
 
void solve(){
    int n;
    cin>>n;
 
    vector<long long> a(n);
    for(int i=0; i<n; i++) cin>>a[i];
 
    long long gcd1=a[0], gcd2=a[1];
    for(int i=2; i<n; i++){
        if(i%2==0){
            gcd1=gcd(gcd1, a[i]);
        } else{
            gcd2=gcd(gcd2, a[i]);
        }
    }
 
    bool ans=true;
    for(int i=0; i<n; i+=2){
        if(a[i]%gcd2 == 0){
            ans=false;
        }
    }
    if(ans){
        cout<<gcd2<<'\n';
        return;
    }
    ans=true;
    for(int i=1; i<n; i+=2){
        if(a[i]%gcd1 == 0){
            ans=false;
        }
    }
    if(ans){
        cout<<gcd1<<'\n';
        return;
    }
    cout<<0<<'\n';
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}
