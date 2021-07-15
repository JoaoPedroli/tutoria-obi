#include <bits/stdc++.h>
using namespace std;

#define vt vector
typedef vt<int> vi; typedef vt<vi> vvi; typedef vt<string> vs;

#define f(a, b, c) for(int a = b; a < c; ++a)
#define be(x) x.begin(), x.end()

int n, m;
vs ns(51);
vvi vis;

void dfs(int i, int j) {
  if(i==n||i<0||j==m||j<0||ns[i][j]=='X'||vis[i][j]) return;
  vis[i][j] = 1, ns[i][j] = 'T';
  dfs(i+1, j), dfs(i-1, j), dfs(i, j+1), dfs(i, j-1);
}

int main() {

  while(cin>>n>>m&&n&&m) {
    vis = vvi(n, vi(m));
    f(i,0,n) cin>>ns[i];
    f(i,0,n)
      f(j,0,m)
        if(ns[i][j] == 'T' && !vis[i][j]) dfs(i, j);
    f(i,0,n) cout<<ns[i]<<'\n';
    cout<<'\n';
  }

return 0;}
