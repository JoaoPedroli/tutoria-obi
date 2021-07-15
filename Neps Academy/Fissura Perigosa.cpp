#include <bits/stdc++.h>
using namespace std;

#define vt vector
typedef vt<int> vi; typedef vt<vi> vvi; typedef vt<string> vs;

#define f(a, b, c) for(int a = b; a < c; ++a)

int n, f;
vs ns;
vvi vis;

void dfs(int i, int j) {
  if(i==n || i<0 || j==n || j<0 || vis[i][j]) return;
  vis[i][j] = 1;
  if(ns[i][j]-'0' <= f) {
    ns[i][j] = '*';
    dfs(i+1, j), dfs(i-1, j), dfs(i, j+1), dfs(i, j-1);
  }
}

int main() {

  cin>>n>>f;
  ns = vs(n), vis = vvi(n, vi(n));
  f(i,0,n) cin>>ns[i];
  dfs(0, 0);
  f(i,0,n) cout<<ns[i]<<'\n';

return 0;}
