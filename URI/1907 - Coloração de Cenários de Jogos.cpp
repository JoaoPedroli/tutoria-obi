#include <bits/stdc++.h>
using namespace std;

# define vt vector
# define pque priority_queue 
typedef long long ll;typedef long double lld;typedef string str;typedef pair<double, double> dd;
typedef vt<int> vi;typedef vt<vt<int>> vvi;typedef vt<double> vd;typedef vt<ll> vll;typedef pair<int,int> ii;
typedef vt<lld> vld;typedef vt<char> vc;typedef vt<str> vs;typedef vt<ii> vii;typedef vt<vii> vvii;
# define f(i,a,b,c) for(ll i=a;i<b;i+=c)
# define fd(i,a,b,c) for(ll i=a;i>=b;i-=c)
# define w(x) while(x--)
# define ctoi(a) (a-'0')
# define pb push_back
# define eb emplace_back
# define lb lower_bound
# define ub upper_bound
# define ts to_string
# define len(x) x.length()
# define be(x) x.begin(), x.end()   
# define rbe(x) x.rbegin(), x.rend()    
# define bb(x, y) binary_search(be(x), y)
# define _(x) cout.precision(x);cout.setf(ios::fixed);
# define ft first
# define se second
# define mdc(a, b) __gcd(a, b)

const int MAX = 1e3+25, mV = 1<<20, mV2 = 1<<10, mV3 = 105;
const int INF = 0x3f3f3f3f, OUT = -INF, OUT2 = -1, MOD = 1300031;

str adj[MAX];
int n, m, u, v, w, re=0;

void bfs(int i, int j){
	queue<ii>fila;
	fila.push({i, j});
	while(!fila.empty()){
		int iu = fila.front().ft, ju = fila.front().se;fila.pop();
		if(iu==n||iu==-1||ju==m||ju==-1)continue;
		if(adj[iu][ju]=='o')continue;
		adj[iu][ju] = 'o';
		fila.push({iu+1, ju}), fila.push({iu, ju+1}), fila.push({iu-1, ju}), fila.push({iu, ju-1});
	}
}

int main(){_(2)
	cin>>n>>m;
	f(i,0,n,1){
		cin>>adj[i];
	}
	f(i,0,n,1){
		f(j,0,m,1){
			if(adj[i][j]=='.')bfs(i, j), ++re;
		}
	}
	cout<<re<<'\n';
return 0;}
