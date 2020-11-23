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

const int MAX = 1e3+7, mV = 1<<20, mV2 = 1<<10, mV3 = 105;
const int INF = 0x3f3f3f3f, OUT = -INF, OUT2 = -1, MOD = 1e9+7;

map<str, vs>adj;
map<str, int>memo;
set<str>ns;
int n, qtd;
void bfs(str s){
	queue<str>fila;
	fila.push(s), memo[s] = true;
	while(!fila.empty()){
		str u = fila.front();fila.pop();
		for(str v:adj[u]){
			if(!memo[v]&&memo[u]<=qtd)fila.push(v), ns.insert(v), memo[v]+=memo[u]+1;
		}
	}
}

str u, v;
int main(){_(2)
	cin>>n>>qtd;
	f(i,0,n,1){
		cin>>u>>v;
		adj[u].eb(v), adj[v].eb(u);
		memo[u] = false, memo[v] = false;
	}
	bfs("Rerisson");
	cout<<ns.size()<<'\n';
	for(auto v:ns){
		cout<<v<<'\n';
	}
return 0;}
