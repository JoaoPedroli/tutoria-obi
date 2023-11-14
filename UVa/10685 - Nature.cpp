#include <bits/stdc++.h>
using namespace std;
using ss = string;

struct DSU {
	map<ss, ss> p;
    	map<ss, int> rnk, tam;
	int ma;

	DSU() {
        p.clear(), rnk.clear(), tam.clear();
        ma = 1;
	}

	ss id(ss u) {
		return (p[u] == u ? u : p[u] = id(p[u]));
	}

	bool same(ss u, ss v) {
		return id(u) == id(v);
	}
	
	void join(ss u, ss v) {
		if(same(u, v)) return;
		ss U = id(u), V = id(v);
		if(rnk[U] < rnk[V]) swap(U, V);
		p[U] = V;
		if(rnk[U] == rnk[V]) ++rnk[V];
		tam[V] += tam[U];
        	ma = max(ma, tam[V]);
	}
};

int main() {
  cin.tie(nullptr)->sync_with_stdio(0);

  int n, m;
  while(cin>>n>>m && n || m) {
    ss s;
    DSU dsu;
    for(int i = 0; i < n; ++i) {
      cin>>s;
      dsu.p[s] = s;
      dsu.tam[s] = 1;
      dsu.rnk[s] = 0;
    }
    ss u, v;
    for(int i = 0; i < m; ++i) {
      cin>>u>>v;
      dsu.join(u, v);
    }
    cout<<dsu.ma<<'\n';
  }
}
