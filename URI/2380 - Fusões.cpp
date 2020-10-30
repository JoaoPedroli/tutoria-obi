#include <bits/stdc++.h>
using namespace std;

typedef long long ll;typedef long double lld;typedef string str;typedef pair<double, double> dd;
typedef vector<int> vi;typedef vector<vector<int>> vvi;typedef vector<double> vd;typedef vector<ll> vll;
typedef vector<lld> vld;typedef vector<char> vc;typedef vector<str> vs;typedef pair<int,int> ii;
# define f(i,a,b,c) for(ll i=a;i<b;i+=c)
# define fd(i,a,b,c) for(ll i=a;i>=b;i-=c)
# define w(x) while(x--)
# define ctoi(a) (a-'0')
# define pb push_back
# define eb emplace_back
# define lb lower_bound
# define ub upper_bound
# define len(x) x.length()
# define be(x) x.begin(), x.end()
# define rbe(x) x.rbegin(), x.rend()
# define _(x) cout.precision(x);cout.setf(ios::fixed);
# define ft first
# define se second

int n, k, pai[1<<20];

void init(int n){
    f(i,0,n+1,1){
        pai[i]=i;
    }
}

int find(int u){
    if(u==pai[u])return pai[u];
    return find(pai[u]);
}

void join(int u, int v){
    u = find(u), v = find(v);
    pai[v] = u;
}

int x, y;
char op;

int main(){_(1)
    cin>>n>>k;
    init(n);
    f(i,0,k,1){
        cin>>op>>x>>y;
        if(op=='F'){
            join(x, y);
        }else{
            cout<<(find(x)==find(y) ? "S\n" : "N\n");
        }
    }
return 0;}
