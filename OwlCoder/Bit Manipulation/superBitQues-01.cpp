
/*
**Problem Statement: Bitwise AND Range Query**

You are given an array `arr` of length `N`. Additionally, there are `q` queries, each represented by the range [L, R], where 0 <= L <= R < N. The task is to find the bitwise AND (&) of all elements in the specified range [L, R] in the array.

Write a function or algorithm to efficiently solve this problem.

**Input:**
- An array `arr` of integers with length N (1 <= N <= 10^5).
- The number of queries `q` (1 <= q <= 10^5).
- For each query, two indices L and R are provided (0 <= L <= R < N).

**Output:**
- For each query, output the bitwise AND of all elements in the specified range [L, R] in the array.

**Example:**
Consider the following example:

```
Input:
arr = [5, 10, 15, 20, 25]
q = 3
Queries:
1. [1, 3]
2. [0, 2]
3. [2, 4]

Output:
1. 10
2. 0
3. 0
```

**Note:**
- In the first query [1, 3], the bitwise AND of elements in the range [10, 15, 20] is 10.
- In the second query [0, 2], the bitwise AND of elements in the range [5, 10, 15] is 0.
- In the third query [2, 4], the bitwise AND of elements in the range [15, 20, 25] is 0.

---
*/




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
    
    int n = 0;
    cin >> n;
    vector<int> nums(n,0);
    for(int i = 0 ; i < n ; i ++) cin >> nums[i];

    //building prefixMatrix
    vector<vector<int>> buildAns(n,vector<int>(32,0));
    for(int i = 0; i < n; i++){
        for(int j = 0 ;j < 32;j++) {
            if((nums[i] & (1 << j)) == 0) {
                if(i == 0) buildAns[i][j]++;
                else buildAns[i][j] = buildAns[i-1][j] + 1;
            } else{
               if(i != 0) buildAns[i][j] = buildAns[i-1][j];
            }
        }
    }

    /*
    //printing prefix Matrix
    for(int i =0; i<n;i++){
        for(int j = 0 ; j < 32;j++){
            cout<<buildAns[i][j]<<" ";
        }cout<<"\n";
    }
    */


    int queries = 0;
    cin >> queries;

    int l= 0, r = 0;
    while(queries--) {
        cin >> l >> r;

        vector<int> ans(32,0);
        int result = 0;
        for(int i=0;i<32;i++) {
            if(l > 0) ans[i] = buildAns[r][i] - buildAns[l-1][i];
            else ans[i] = buildAns[r][i];
            if(ans[i]==0) {
                result += (1<<i);
            }
        }
        cout<<"algorithm answer = "<<result<<"\n";

        //just for testing our answer 
        int testans = nums[l];
        for(int i = l+1; i<=r;i++){
            testans &= nums[i];
        }
        cout<<"Test answer = "<<testans<<"\n";

    }


    return 0;
}