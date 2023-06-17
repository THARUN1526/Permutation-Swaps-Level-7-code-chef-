#include<bits/stdc++.h>
#include<sstream>
using namespace std;
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
//using namespace __gnu_pbds;
//typedef tree<int,null_type,less_equal<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
const long long INF=1'000'000'000'000'000'000;
const int inf = 1e9;
const long long mod = 1e9+7;
const int N = 1e6+8;
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);
#define T() int tt; cin>>tt; while(tt--)
#define ll long long
#define prec cout<<fixed<<setprecision(15);
#define ld long double  
#define pii pair<int, int>
#define pll pair<ll, ll>
#define pipi pair<int, pair<int, int>>
#define vii vector<int>
#define F first
#define S second
#define fill(v,p) memset(v, p, sizeof(v))
// #define print(v) for(auto &z : v)cout<<z<<" ";cout<<'\n';
#define all(v) v.begin(), v.end()
#define PI 3.141592653589793
#define rank asdf
int up[N][25];
int n, q;
int main()
{
   IOS
   T(){
      cin>>n;
      vector<int>a(n), p(n), par(n);
      for(int i = 0; i < n; i++){
         cin>>a[i];
         a[i]--;
      }
      unordered_map<int, int>pos;
      for(int i = 0; i < n; i++){
         pos[a[i]] = i;
      }
      for(int i = 0; i < n; i++){
         cin>>p[i];
         p[i]--;
         par[p[i]] = i;
      }
      cin>>q;
      for(int i = 0; i < n; i++){
         up[i][0] = par[i];
      }
      for(int j = 1; j <= 19; j++){
         for(int i = 0; i < n; i++){
            int pp = up[i][j-1];
            up[i][j] = up[pp][j-1];
         }
      }
      int cnt = 0, op, x, y;
      for(int i = 0; i < q; i++){
         cin>>op;
         if(op == 1)cnt++;
         else if(op == 2){
            cin>>x>>y;
            x--, y--;
            int e1 = x, e2 = y;
            for(int j = 0; j <= 19; j++){
               if(cnt&(1<<j)){
                  e1 = up[e1][j];
                  e2 = up[e2][j];
               }
            }
            int p1 = pos[e1], p2 = pos[e2];
            swap(a[e1], a[e2]);
         }
         else{
            cin>>x;
            x--;
            for(int j = 0; j <= 19; j++){
               if(cnt&(1<<j)){
                  x = up[x][j];
               }
            }
            cout<<a[x]+1<<'\n';
         }
         // for(auto it: a)cout<<it<<" ";cout<<'\n';
      }
   }
} 