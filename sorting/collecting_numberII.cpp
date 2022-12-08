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
void solve(){

}
int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n, q;
    cin >> n >> q;
    vi v(n+1), ind(n+1);
    For(i, n){
        cin >> v[i+1];
        ind[v[i+1]] = i+1;
    }
    int ans = 0;
    FOR(i, 1, n+1){
        if(ind[i+1] < ind[i]) ans++;
    }
    while(q--){
        int a,b;
        cin >> a >> b;
        if(a == b){
            cout << ans << '\n';
            continue;
        }
        int x = v[a], y = v[b];
        if(ind[x] < ind[x-1] && ind[x-1] <= b && x-1 != y) ans--;
        if(ind[x] > ind[x-1] && ind[x-1] >= b && x-1 != y) ans++;
        if(ind[x] < ind[x+1] && ind[x+1] <= b && x+1 != y) ans++;
        if(ind[x] > ind[x+1] && ind[x+1] >= b && x+1 != y) ans--;
        if(ind[y] < ind[y-1] && ind[y-1] <= a) ans--;
        if(ind[y] > ind[y-1] && ind[y-1] >= a) ans++;
        if(ind[y] < ind[y+1] && ind[y+1] <= a) ans++;
        if(ind[y] > ind[y+1] && ind[y+1] >= a) ans--;
        swap(v[a], v[b]);
        swap(ind[x], ind[y]);
        cout << ans << '\n';
    }
}