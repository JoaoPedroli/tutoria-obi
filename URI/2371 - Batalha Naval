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

const int MAX = 101;
int n, m, ou, x, y, re=0, in;
str ns[MAX];
int vis[MAX][MAX], memo[MAX][MAX];

void dfs(int i, int j){
    if(i==n||i==-1||j==m||j==-1)return;
    if(ns[i][j]=='.' or memo[i][j])return;
    memo[i][j] = 1;
    if(!vis[i][j])in=0;
    dfs(i, j+1), dfs(i, j-1), dfs(i+1, j), dfs(i-1, j);
}

int main(){_(1)
    cin>>n>>m;
    f(i,0,n,1){
        cin>>ns[i];
    }
    cin>>ou;
    f(i,0,ou,1){
        cin>>x>>y;
        --x, --y;
        if(ns[x][y]=='#')vis[x][y] = 1;
    }
    f(i,0,n,1){
        f(j,0,m,1){
            in=2;
            if(ns[i][j]=='#' and vis[i][j] and !memo[i][j])memo[i][j] = 1, in = 1, dfs(i, j+1), dfs(i, j-1), dfs(i+1, j), dfs(i-1, j);
            if(in==1)++re;
        }
    }
    cout<<re<<'\n';
return 0;}
