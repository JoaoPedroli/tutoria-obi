#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9+7;

int n, m;
int main() {

  cin>>n;
  vector<int> memo(n+1), coins = {1, 2, 3, 4, 5, 6};

  memo[0] = 1;
  for(int x = 1; x <= n; ++x) {
    for(int c : coins) {
      if(x - c >= 0) {
        (memo[x] += memo[x - c]) %= MOD;
      }
    }
  }
  cout<<memo[n]<<'\n';

return 0;}
