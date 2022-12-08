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
void solve() {

}
int n, m;
bool valid(int i, int j){
    return i >= 0 && i < n && j >= 0 && j < m; 
}
int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> n >> m;
    bool visited[n][m] = {};
    vvc board(n, vc(m));
    pii start, end;
    For(i, n)For(j, m) {
        cin >> board[i][j];
        if (board[i][j] == 'A') {
            start.f = i, start.s = j;
        }
        if (board[i][j] == 'B') {
            end.f = i, end.s = j;
        }
    }
    queue<pii> q;
    q.push(start);
    char dd[5] = "DRUL";
    vvc v(n, vc(m));
    int dir[4][2] = { {1,0},{0,1},{-1,0},{0,-1} };
    bool good = 0;
    while (!q.empty()) {
        pii pos = q.front();
        q.pop();
        if (visited[pos.f][pos.s])continue;
        visited[pos.f][pos.s] = 1;
        if (pos == end) {
            good = 1;
            break;
        }
        For(i, 4) {
            auto d = dir[i];
            char di = dd[i];
            int y = pos.f + d[0], x = pos.s + d[1];
            if(!valid(y, x)) continue;
            if (!visited[y][x] && (board[y][x] == '.' || board[y][x] == 'B')) {
                v[y][x] = di;
                q.push({y, x});
            }
        }
    }
    if(!good)
        cout << "NO\n";
    else{
        string ans;
        pii iter = end;
        do{
            char c = v[iter.f][iter.s];
            ans.push_back(c);
            switch(c){
                case 'L': iter.s++;
                break;
                case 'R': iter.s--;
                break;
                case 'D': iter.f--;
                break;
                case 'U': iter.f++;
                break;
            }
        }while(iter != start);
        reverse(ans.begin(), ans.end());
        cout << "YES\n";
        cout << ans.size() << '\n';
        cout << ans << '\n';
    }
}