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

const int MAX = 11, mV = 1<<20, mV2 = 1<<10, mV3 = 105;
const int INF = 0x3f3f3f3f, OUT = -INF, OUT2 = -1, MOD = 1e9+7;

vvi adj, soma;
int pic, pjc, pis, pjs;
str posi, posj;
void bfs(int i, int j){
	queue<ii>fila;
	fila.push({i, j});	
	while(!fila.empty()){
		int iu = fila.front().ft, ju = fila.front().se;fila.pop();
		if(iu==pis&&ju==pjs){
			cout<<"To get from "<<posi[0]<<posi[1]<<" to "<<posj[0]<<posj[1]<<" takes "<<soma[iu][ju]<<" knight moves.\n";
			return;
		}
		adj[iu][ju] = 1;
		//j para 2
		if((iu+1<=8&&ju+2<=8)&&!adj[iu+1][ju+2])fila.push({iu+1, ju+2}), soma[iu+1][ju+2] = soma[iu][ju]+1;
		if((iu+1<=8&&ju-2>=1)&&!adj[iu+1][ju-2])fila.push({iu+1, ju-2}), soma[iu+1][ju-2] = soma[iu][ju]+1;
		if((iu-1>=1&&ju+2<=8)&&!adj[iu-1][ju+2])fila.push({iu-1, ju+2}), soma[iu-1][ju+2] = soma[iu][ju]+1;
		if((iu-1>=1&&ju-2>=1)&&!adj[iu-1][ju-2])fila.push({iu-1, ju-2}), soma[iu-1][ju-2] = soma[iu][ju]+1;
		//i para 2
		if((iu+2<=8&&ju+1<=8)&&!adj[iu+2][ju+1])fila.push({iu+2, ju+1}), soma[iu+2][ju+1] = soma[iu][ju]+1;
		if((iu+2<=8&&ju-1>=1)&&!adj[iu+2][ju-1])fila.push({iu+2, ju-1}), soma[iu+2][ju-1] = soma[iu][ju]+1;
		if((iu-2>=1&&ju+1<=8)&&!adj[iu-2][ju+1])fila.push({iu-2, ju+1}), soma[iu-2][ju+1] = soma[iu][ju]+1;
		if((iu-2>=1&&ju-1>=1)&&!adj[iu-2][ju-1])fila.push({iu-2, ju-1}), soma[iu-2][ju-1] = soma[iu][ju]+1;
	}
}

int main(){_(2)
	while(cin>>posi>>posj){
		adj = vvi(9, vi(9)), soma = vvi(9, vi(9));
		pic = ctoi(posi[1]), pjc = int(posi[0])-96;
		pis = ctoi(posj[1]), pjs = int(posj[0])-96;
		bfs(pic, pjc);
	}
return 0;}
