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

const int MAX = 1e3+1, mV = 1<<20, mM = 401, INF = 0x3f3f3f3f, OUT = -INF;

int n, m, p;
int dist[mM][mM];
int u, v;

void fw(int n){
    f(k,1,n+1,1)
        f(i,1,n+1,1)
            f(j,1,n+1,1)
                dist[i][j] = min(dist[i][j], dist[i][k]+dist[k][j]);
}

int main(){_(0)
    cin>>n>>m>>p;
    f(i,1,n+1,1){
        f(j,1,n+1,1){
            dist[i][j] = (i!=j?INF:0);
        }
    }
    w(m){
        cin>>u>>v;
        dist[u][v]=1, dist[v][u]=1;
    }
    fw(n);
    w(p){
        cin>>u>>v;
        cout<<((dist[u][v]!=INF)?"Lets que lets":"Deu ruim")<<'\n';
    }
return 0;}
