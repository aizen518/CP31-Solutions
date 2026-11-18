#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n, m;
    cin>>n>>m;
    vector<int> a(m);
    for(int i=0; i<m; i++) cin>>a[i];

    sort(a.begin(), a.end());
    vector<int> x;
    for(int i=1; i<m; i++){
        int gap=a[i]-a[i-1]-1;
        if(gap){
            x.push_back(gap);
        }
    }
    x.push_back(n-a[m-1]+a[0]-1);
    sort(x.begin(), x.end(), greater<int>());

    int ans=0, t=0;

    for(int i=0; i<x.size(); i++){
        int rem=x[i]-t;

        if(rem<=0) break;

        if(rem<3){
            ans+=1;
            t+=2;
        }else{
            ans+=rem-1;
            t+=4;
        }
    }
    cout<<n-ans<<endl;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin>>t;
    while(t--) solve();
}