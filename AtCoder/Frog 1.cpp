#include <bits/stdc++.h>
using namespace std;
 
int n;
int main() {
  cin>>n;
  vector<long long> ns(n+1), dp(n+1, 0);
  for(int i=0;i<n;++i) cin>>ns[i];
  dp[0] = 0, dp[1] = abs(ns[1] - ns[0]);
  for(int x=2;x<n;++x) {
    dp[x] = min(dp[x-1] + abs(ns[x] - ns[x-1]), dp[x-2] + abs(ns[x] - ns[x-2]));
  }
  cout<<dp[n-1]<<'\n';
}
