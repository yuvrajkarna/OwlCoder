#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>  
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair<int,int> p32;
typedef pair<ll,ll> p64;
typedef pair<double,double> pdd;
typedef vector<ll> v64;
typedef vector<int> v32;
typedef vector<vector<int> > vv32;
typedef vector<vector<ll> > vv64;
typedef vector<vector<p64> > vvp64;
typedef vector<p64> vp64;
typedef vector<p32> vp32;
ll MOD = 998244353;
double eps = 1e-12;
#define forn(i,e) for(ll i = 0; i < e; i++)
#define forsn(i,s,e) for(ll i = s; i < e; i++)
#define rforn(i,s) for(ll i = s; i >= 0; i--)
#define rforsn(i,s,e) for(ll i = s; i >= e; i--)
#define mp make_pair
#define INF 2e18
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((ll)(x).size())
 

int main()
{
    fast_cin();
    int t;
    cin >> t;
    int n = 0;
    for(int it=1;it<=t;it++) {
        cin >> n;
        vector<int> a(n,0), b(n,0);
        for(int i=0;i<n;i++) cin >> a[i];
        for(int i=0;i<n;i++) cin >> b[i];

        sort(a.begin(),a.end());
        sort(b.begin(),b.end(),greater<int>());

        int previous = -1, flag = 0;
        for(int i = 0; i< n;i++){
            if(previous == -1  || a[i]+b[i] == previous) {
                previous = a[i] + b[i];
            }
            else {
                cout<<"-1\n";
                flag = 1;
                break;
            }
        }
        if(flag == 0){
            for(int i = 0 ;i < n; i++) cout<<a[i]<<" ";
            cout<<"\n";
            for(int i = 0 ;i < n; i++) cout<<b[i]<<" ";
            cout<<"\n";
        }
        

    }
    return 0;
}