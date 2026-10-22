  // Problem: Making Equal
  //   Codeforces: 1594C
  //   Rating: 1200
  //   Topic: Greedy and Strings
  //   Link: https://codeforces.com/problemset/problem/1594/C

  //   Approach:
  //   We can run a loop on the string.
  //   If the string is already full of c then just cout 0.
  //   If the last char is c then we can take x=n cause n wont divide any i less than n and make every index c.
  //   Else we can check for every i whether all its multiples are c or not.
  //   When we find such an i we get the answer. 
  //   If we dont get anything then we can just cout n-1 and n cause n-1 will make last char c and n will make every other index c.
    
  //   Time Complexity: O(n logn)
  //   Space Complexity: O(n)
  
#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    char c;
    cin>>n>>c;
    string s;
    cin>>s;

    string x(n, c);
    if(s == x){
        cout<<0<<"\n";
    }else if(s[n-1] == c){
        cout<<1<<"\n";
        cout<<n<<"\n";
    }else{
        for(int i=1; i<=n; i++){
            if(s[i-1] != c) continue;
            bool flag = true;
            for(int j=i; j<=n; j+=i){
                if(s[j-1] != c){
                    flag=false;
                    break;
                }
            }
            if(flag){
                cout<<1<<"\n"<<i+1<<"\n";
                return;
            }
        }
        cout<<2<<"\n"<<n-1<<" "<<n<<"\n";
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin>>t;
    while(t--) solve();
}

