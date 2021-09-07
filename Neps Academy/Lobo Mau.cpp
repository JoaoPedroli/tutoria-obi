#include <bits/stdc++.h>
using namespace std;

int n, m, o, l, anso = 0, ansl = 0, vis[251][251];
string adj[251];

void dfs(int i, int j) {
  if(i<0||i==n||j<0||j==m||vis[i][j]||adj[i][j]=='#') return;
  vis[i][j] = 1;
  if(adj[i][j] == 'v') ++l;
  else if(adj[i][j] == 'k') ++o;
  dfs(i+1,j), dfs(i-1, j), dfs(i, j+1), dfs(i, j-1);
}

int main() {
  cin>>n>>m;
  for(int i=0;i<n;++i) {
    cin>>adj[i];
  }
  for(int i=0;i<n;++i) {
    for(int j=0;j<m;++j) {
      if(!vis[i][j]) {
        l = 0, o = 0, dfs(i,j);
        if(l >= o) ansl += l;
        else anso += o;
      }
    }
  }
  cout<<anso<<' '<<ansl<<'\n';
}
