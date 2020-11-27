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

#define sz(x) ((int) (x).size())
const int MAX = 1e3+7, mV = 1<<20, mV2 = 1<<10, mV3 = 105;
const int INF = 0x3f3f3f3f, OUT = -INF, OUT2 = -1, MOD = 1e9+7;

struct vetor
{
    double x, y;
    vetor operator +(vetor q) const {
        return {x + q.x, y + q.y};
    }
    vetor operator -(vetor q) const {
        return {x - q.x, y - q.y};
    }
    double operator ~() const {
        return hypot(x, y);
    }
    double operator *(vetor q) const {
        return x*q.x + y*q.y;
    }
    double operator ^(vetor q) const {
        return x*q.y - y*q.x;
    }
    int operator <(vetor q) const {
        return (x<q.x || (x == q.x && y < q.y));
    }
    int operator !=(vetor q) const {
        return x!=q.x&&y!=q.y;
    }
    int operator ==(vetor q) const {
        return x==q.x&&y==q.y;
    }
};

double distance(vetor p1, vetor p2) 
{ 
    return hypot(p1.x - p2.x, p1.y - p2.y);
}

int cw(vetor a, vetor b, vetor c){
    return (((b-a)^(c-b)) < 0);
}

int ccw(vetor a, vetor b, vetor c){
    return (((b-a)^(c-b)) > 0);
}

vetor p1, p2, p;
vt<vetor> cima, baixo, a, convex_hull;
int n;
double re;
set<vetor> pontos;

int main(){_(2)
    while(cin>>n&&n){
        re=0;
        f(i,0,n,1){
            cin >> p.x >> p.y;
            pontos.insert(p);
        }

        for (auto v : pontos){
            a.eb(v);
        }
        
        n = sz(a);

        sort(a.begin(), a.end());

        p1 = a[0]; p2 = a.back();

        cima.eb(p1), baixo.eb(p1);

        f(i,1,n,1){
            if (i==n-1 || cw(cima[sz(cima)-1], a[i], p2)){
                while (sz(cima) >=2 && !cw(cima[sz(cima)-2] , cima[sz(cima)-1], a[i])){
                    cima.pop_back();
                }
                cima.eb(a[i]);
            }
            if (i==n-1 || ccw(baixo[sz(baixo)-1], a[i], p2)){
                while (sz(baixo) >=2 && !ccw(baixo[sz(baixo)-2] , baixo[sz(baixo)-1], a[i])){
                    baixo.pop_back();
                }
                baixo.eb(a[i]);
            }
        }

        f(i,0,sz(cima),1){
            convex_hull.eb(cima[i]);
        }
        fd(i,sz(baixo)-2,1,1){
            convex_hull.eb(baixo[i]);
        }

        convex_hull.eb(convex_hull[0]);
        f(i,0,sz(convex_hull)-1,1){
            re += distance(convex_hull[i], convex_hull[i+1]);
        }
        cout<<"Tera que comprar uma fita de tamanho "<<re<<".\n";
        
        pontos.clear(), convex_hull.clear(), cima.clear(), baixo.clear(), a.clear();
    }
return 0;}
