#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9+7;

int n, m;
int main() {

  cin>>n>>m;
  vector<int> coins(n), memo(m+1, 0);
  for(int i = 0; i < n; ++i) cin>>coins[i];
  memo[0] = 1;
  for(int x = 1; x <= m; ++x) {
    for(int c : coins) {
      if(x - c >= 0) {
        (memo[x] += memo[x-c]) %= MOD;
      }
    }
  }
  cout<<memo[m]<<'\n';

return 0;}
