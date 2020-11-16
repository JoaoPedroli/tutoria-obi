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

const int MAX = 31, mV = 1<<20, mM = 105, INF = 0x3f3f3f3f, OUT = -INF;

int t;
int n, m, u, v;
vvi gr;
vi memo, ordem;

int top_sort(){
    queue<int>fila;
    ordem.clear();
    f(i,1,n+1,1){
        if(!memo[i]){
            fila.push(i);
        }
    }
    while(!fila.empty()){
        int u = fila.front();fila.pop();
        ordem.eb(u);
        for(int v:gr[u]){
            --memo[v];
            if(!memo[v]){
                fila.push(v);
            }
        }
    }
    return ordem.size()==n;
}

int main(){_(0)
    while(cin>>n>>m&&n||m){
        gr = vvi(n+1), memo = vi(n+1, 0);
        w(m){
            cin>>u>>v;
            gr[u].eb(v);
            ++memo[v];
        }
        top_sort();
        for(int v:ordem){
            cout<<v<<' ';
        }
        cout<<'\n';
    }
return 0;}
