#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef pair<int, ii> iii;

#define vt vector
#define eb emplace_back
#define pb push_back
#define f(i, s, f) for(int i = s; i < f; ++i)
#define fd(i, s, f) for(int i = s; i >= f; --i)
#define r(x, ns) for(auto& x : ns)
#define s(x) int(x.size())
#define be(ns) ns.begin(), ns.end()
#define rbe(ns) ns.rbegin(), ns.rend()
#define gr(type) vt<type>, greater<type>
#define F first
#define S second

const int mVI = 1<<20, mVJ = 1<<10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;
const int MAX = 102;

int iin, jin, ifi, jfi;
vt<vt<int>> vis;
string s1, s2;

int bfs() {
  queue<iii> q;
  q.push({iin, {jin, 0}});
  while(!q.empty()) {
    int x = q.front().F, y = q.front().S.F, d = q.front().S.S; q.pop();

    if(x == ifi && y == jfi) return d;
    if(x<0||y<0||x>7||y>7||vis[x][y]) continue;
    vis[x][y] = 1;

    f(i,-2,3) {
      f(j,-2,3) {
        if(i && j && abs(i) != abs(j)) {
          q.push({x+i, {y+j, d+1}});
        }
      }
    }
  }
  return INF;
}

int main() {
  while(cin>>s1>>s2) {
    vis = vt<vt<int>>(10, vt<int>(10, 0));
    iin = (s1[0] - '0') - 49;
    jin = (s1[1] - '0') - 1;
    ifi = (s2[0] - '0') - 49;
    jfi = (s2[1] - '0') - 1;
    cout<<"To get from "<<s1<<" to "<<s2<<" takes "<<bfs()<<" knight moves."<<'\n';
  }
}
