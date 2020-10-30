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

const int BR = 0, CI = 1, PR = 2;

int t, n, m, ou;
char au;
vector<vc> gr;
vi vis;
vc res;

void dfs(int u){
    vis[u] = CI;
    res.pb(char(u));
    for (char v : gr[u]){
        ou=int(v);
        if (vis[ou]==BR){
            dfs(ou);
        }
    }
    vis[u] = PR;
}

char u, v;
int pos, re;
int main(){_(1)
    cin>>t;
    f(z,0,t,1){
        re=0;
        cin>>n>>m;
        gr = vector<vc>(n+97);
        f(i,97,n+97,1)gr[i].eb(char(97));
        f(i,0,m,1){
            cin>>u>>v;
            ou=u;
            if(i==0)pos=ou;
            gr[ou].eb(v);
            gr[int(v)].eb(u);
        }
        vis = vi(n+97, BR);
        cout<<"Case #"<<z+1<<":\n";
        f(i,97,n+97,1){
            if(vis[i]==BR){
                ++re;
                res.clear();
                dfs(i);
                sort(be(res));
                f(i,0,res.size(),1)cout<<res[i]<<',';
                cout<<'\n';
            }
        }
        cout<<re<<" connected components\n\n";
    }
return 0;}
