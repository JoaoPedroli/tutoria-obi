#include<bits/stdc++.h>

using namespace std;

#define dist(xa, ya, xb, yb) (pow((xa-xb),2)+pow((ya-yb),2))

int n, m, sum = 0;
vector<pair<int, int>> points;
vector<int> adj[1002], vis(1002);

void dfs(int u) {
  if(vis[u]) return;
  vis[u] = 1, ++sum;
  for(int& v:adj[u]) {
    dfs(v);
  }
}

int u, v;
int main() {
  cin>>n>>m;
  for(int i=0;i<n;++i) {
    cin>>u>>v;
    points.emplace_back(u, v);
    for(int j=0;j<i;++j) {
      if(dist(points[j].first, points[j].second, u, v) <= m*m) {
        adj[i].emplace_back(j);
        adj[j].emplace_back(i);
      }
    }
  }
  dfs(1);
  cout<<(sum == n ? "S\n" : "N\n");
}
