// Problem: Building an aquarium
//   Codeforces: 1873E
//   Rating: 1100
//   Topic: Binary search on answer
//   Link: https://codeforces.com/problemset/problem/1873/E

//   Approach:
//   Binary search with limits l=0 and r= min(a[i])+x. Check each m by calculating water to be used for it.

//   Time Complexity: O(n log(x+min(a[i]))
//   Space Complexity: O(n)

#include <bits/stdc++.h>
using namespace std;
 
void solve(){
    long long n, x;
    cin>>n>>x;
    vector<long long> a(n);
    long long mini=INT_MAX;
    for(int i=0; i<n; i++){
        cin>>a[i];
        mini=min(mini, a[i]);
    }
    
    long long l=0, r=mini+x;
    long long ans=0;
    while(l<=r){
        bool flag=true;
        long long m = l+(r-l)/2;
        long long curr=0;
        for(int i=0; i<n; i++){
            if(a[i]<m){
                curr+=(m-a[i]);
            }
            if(curr>x){
                flag=false;
                break;
            }
        }
        if(flag){
            ans=m;
            l=m+1;
        }else{
            r=m-1;
        }
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
