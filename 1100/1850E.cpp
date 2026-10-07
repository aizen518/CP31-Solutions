  // Problem: Cardboard for pictures
  //   Codeforces: 1850E
  //   Rating: 1100
  //   Topic: Binary search
  //   Link: https://codeforces.com/problemset/problem/1850/E

  //   Approach:
  //   Binary search on answer.
  //   We check if m is valid or not by adding thesheet used for every painting into sum and comparing sum with c.
    
  //   Time Complexity: O(n logc + n logn)
  //   Space Complexity: O(n)


#include <bits/stdc++.h>
using namespace std;

void solve(){
    long long n, c;
    cin>>n>>c;
    vector<long long> v(n);
    for(int i=0; i<n; i++)  cin>>v[i];
    sort(v.begin(), v.end(), greater<int>());
    long long l=0, r=sqrt(c);
    long long m, w=0;
    bool flag=true;
    while(l<=r){
        flag=true;
        m =l+(r-l)/2;
        long long sum=0;
        for(int i=0; i<n; i++){
            sum+=((v[i]+m+m)*(v[i]+m+m));
            if(sum>c){
                flag=false;
                break;
            }
        }
        if(flag){
            w=m;
            l=m+1;
        }
        else{
            r=m-1;
        }
    }
    cout<<w<<"\n";
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
