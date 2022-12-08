#include<iostream>
#include<vector>
#include<map>
#include<unordered_map>
#include<set>
#include<unordered_set>
#include<string>
#include<queue>
#include<deque>
#include<list>
#include<math.h>
#include<cmath>
#include<algorithm>
#include<string.h>
#include<functional>
#include<stdlib.h>
#include<stdio.h>

using namespace std;
typedef long long ll;
#define vt vector
#define ull unsigned ll
#define ui unsigned int
#define vt vector
#define vc vt<char>
#define vb vt<bool>
#define vi vt<int>
#define vll vt<ll>
#define vvi vt<vi>
#define vvc vt<vc>
#define vvb vt<vb>
#define vvll vt<vll>
#define vpii vt<pair<int,int>>
#define vpll vt<pll>
#define vpci vt<pair<char,int>>
#define pii pair<int,int>
#define pll pair<ll, ll>
#define pci pair<char, int>
#define pic pair<char, char>
#define pcll pair<char, ll>
#define psll pair<string, ll>
#define psi pair<string, int>
#define mii map<int,int>
#define umii unordered_map<int,int>
#define umll unordered_map<ll, ll>
#define umci unordered_map<char, i>
#define umcl unordered_map<char, ll>
#define For(i, n) for(int i = 0 ; i < n ; i++)
#define FOR(i, n , m) for(int i = n ; i < m ; i++)
#define reset(i) memset(i, 0, sizeof(i))
#define pb push_back
#define f first
#define s second
template<class T>
void read(vector<T>& v){
    for(auto&i : v){
        cin >> i;
    }
}
template<class T>
void read(vector<pair<T, T>>& v){
    for(auto&i : v){
        cin >> i.f >> i.s;
    }
}
template<class T>
void read(vector<vector<T>>& v){
    for(auto&i : v){
        for(auto&j : i){
            cin >> j;
        }
    }
}
template<class T>
void sort(vector<T>& v){
    sort(v.begin(), v.end());
}
template<class T>
void sort(vector<T>& v, int flag){
    sort(v.begin(), v.end(), greater<T>());
}
template<class T>
ostream& operator<<(ostream& os, const vector<T>& vec){
    if(vec.size() == 1){
        os << vec[0];
    }else{
        typename vector<T>::const_iterator i;
        for(i = vec.begin(); i != vec.end()-1 ;i++){
            os << *i << " ";
        }
        os << *i;
    }
    os << '\n';
    return os;
}
#define maxn (int)1e5+7
void solve(){

}
vvi g;
bool good = 1;
vi team;
bool vis[maxn];
void dfs(int i, int last, int flag = 0){
    vis[i] = 1;
    if(flag) team[i] = 1;
    else team[i] = 2;
    for(int j : g[i]){
        if(team[i]==team[j]){
            good = 0;
            return;
        }
        else if(!vis[j]){
            dfs(j, i, !flag);
        }
    }
}
int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    g.assign(n+1, vi());
    team.assign(n+1, 0);
    For(i, m){
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    For(i, n){
        if(!vis[i+1]){
            dfs(i+1, 0);
        }
    }
    if(good){
        For(i, n){
            cout << team[i+1] <<' ';
        }
    }else
    cout << "IMPOSSIBLE\n";
}