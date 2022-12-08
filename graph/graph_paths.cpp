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
void read(vector<T>& v) {
    for (auto& i : v) {
        cin >> i;
    }
}
template<class T>
void read(vector<pair<T, T>>& v) {
    for (auto& i : v) {
        cin >> i.f >> i.s;
    }
}
template<class T>
void read(vector<vector<T>>& v) {
    for (auto& i : v) {
        for (auto& j : i) {
            cin >> j;
        }
    }
}
template<class T>
void sort(vector<T>& v) {
    sort(v.begin(), v.end());
}
template<class T>
void sort(vector<T>& v, int flag) {
    sort(v.begin(), v.end(), greater<T>());
}
template<class T>
ostream& operator<<(ostream& os, const vector<T>& vec) {
    if (vec.size() == 1) {
        os << vec[0];
    }
    else {
        typename vector<T>::const_iterator i;
        for (i = vec.begin(); i != vec.end() - 1; i++) {
            os << *i << " ";
        }
        os << *i;
    }
    os << '\n';
    return os;
}
int n, m, k;
const int mod = 1e9 + 7;
vvll mul(vvll& a, vvll& b) {
    vvll ans(n, vll(n));
    For(i, n) {
        For(j, n) {
            ll temp = 0;
            For(k, n) {
                temp = (temp + a[i][k] * b[k][j] % mod) % mod;
            }
            ans[i][j] = temp;
        }
    }
    return ans;
}
vvll p(vvll& g, int po) {
    vvll ans(n, vll(n));
    For(i, n) ans[i][i] = 1;
    while (po) {
        if (po % 2) {
            ans = mul(ans, g);
        }
        g = mul(g, g);
        po /= 2;
    }
    return ans;
}
int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> n >> m >> k;
    vvll g(n, vll(n));
    For(i, m) {
        int a, b;
        cin >> a >> b;
        a--,b--;
        g[a][b]++;
    }
    //g = p(g,2);
    g = p(g, k);
    cout << g[0][n - 1] << '\n';
}