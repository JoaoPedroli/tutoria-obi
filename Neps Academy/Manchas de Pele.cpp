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

const int MAX = 1000;
int n, m, in=0, re=0, gr[MAX][MAX], memo[MAX][MAX];

void dfs(int i, int j){
    if(memo[i][j]||i==n||i==-1||j==m||j==-1)return;
    if(!gr[i][j])return;
    memo[i][j]=1;

    dfs(i, j-1), dfs(i, j+1), dfs(i+1, j), dfs(i-1, j);
}

int main(){_(1)
    cin>>n>>m;
    f(i,0,n,1){
        f(j,0,m,1){
            cin>>gr[i][j];
        }
    }
    f(i,0,n,1){
        f(j,0,m,1){
            if(gr[i][j]==1 and !memo[i][j]){
                dfs(i, j), ++re;
            }
        }
    }
    cout<<re<<'\n';
return 0;}
