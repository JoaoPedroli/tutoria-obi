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

const int MAX = 1e5, mV = 1<<20, mV2 = 1<<10, mV3 = 105;
const int INF = 0x3f3f3f3f, OUT = -INF, OUT2 = -1, MOD = 1e9+7;

int pai[mV], enemy[mV];
int n, m, op;

//union-find
int id(int u){
    return (pai[u]==u) ? u : pai[u] = id(pai[u]);
}
void join(int u, int v){
    u = id(u), v = id(v);
    if(u == v || !u || !v)return;
    pai[v] = u;
}

////////
void are_friends(int u, int v)
{
    cout<<(id(u) == id(v)?'1':'0')<<'\n';
}
void are_enemies(int u, int v)
{
    u = id(u), v = id(v);
    cout<<((id(enemy[u]) == v || id(enemy[v]) == u)?'1':'0')<<'\n';
}
void join_friends(int u, int v)
{
    u = id(u), v = id(v);
    int enemyU = id(enemy[u]), enemyV = id(enemy[v]);
    if(enemyU == v || enemyV == u){ //são inimigos logo não podem ser amigos
        cout<<-1<<'\n';
        return;
    }

    join(u, v), join(enemyU, enemyV);
    enemyU = id(enemyU), enemyV = id(enemyV);

    if(enemyU) enemy[id(u)] = enemyU;
    else enemy[id(u)] = enemyV;
}
void join_enemies(int u, int v)
{
    u = id(u), v = id(v);

    if(u == v){ //são amigos logo não podem ser inimigos
        cout<<-1<<'\n';
        return;
    }

    join(enemy[u], v), join(enemy[v], u);

    u = id(u), v = id(v);
    enemy[u] = v, enemy[v] = u;
}
////////

int u, v;
int main(){_(2)
    cin>>n;
    f(i,1,n+1,1){
        pai[i] = i, enemy[i] = false;
    }
    while(cin>>op>>u>>v&&op||u||v){
        ++u, ++v;
        switch (op){
            case 1:
                join_friends(u, v);break;
            case 2:
                join_enemies(u, v);break;
            case 3:
                are_friends(u, v);break;
            default:
                are_enemies(u, v);break;
        }
    }
return 0;}
