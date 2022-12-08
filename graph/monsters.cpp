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
#include<fstream>
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
void solve(){

}
int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    //ifstream ff;
    //ff.open("C:/C programs/cses/graph/test_input.txt");
    //ff >> n >> m;
    vvc v(n, vc(m));
    // For(i, n){
    //     For(j, m){
    //         ff >> v[i][j];
    //     }
    // }
    read(v);
    pii a;
    vpii mon;
    For(i, n){
        For(j, m){
            if(v[i][j] == 'A'){
                a = {i, j};
            }else if(v[i][j] == 'M'){
                mon.pb({i, j});
            }
        }
    }
    queue<pair<pii, int>> q;
    for(auto m : mon){
        q.push({m, 0});
    }
    auto valid = [&](int i, int j){
        return i >= 0  && i < n && j >= 0 && j < m;
    };
    int dir[4][2] = {{1,0},{0,-1},{-1,0},{0,1}};
    vvi visited(n, vi(m));
    For(i, n){
        For(j, m){
            if(v[i][j] == '#') visited[i][j] = -1;
            else
            visited[i][j] = 2147483647;
        }
    }
    //cout << "HIHI";
    while(!q.empty()){
        auto temp = q.front();
        q.pop();
        int step = temp.s;
        auto pos = temp.f;
        //cout << pos.f << ' ' << pos.s <<' '<<step <<  '\n';
        if(visited[pos.f][pos.s] <= step) continue;
        visited[pos.f][pos.s] = step;
        for(auto d : dir){
            int i = d[0] + pos.f;
            int j = d[1] + pos.s;
            if(valid(i, j) &&visited[i][j] == 2147483647 && (v[i][j] == '.' || v[i][j] == 'A')){
                q.push({{i,j}, step+1});
            }
        }
    }
    // For(i, n){
    //     For(j, m){
    //         cout << visited[i][j] <<' ';
    //     }cout << '\n';
    // }
    q.push({a, 0});
    vvc path(n, vc(m));
    bool good = 0;
    char dirr[] = "DLUR";
    pii end;
    vvb walked(n, vb(m));
    while(!q.empty()){
        auto temp = q.front();
        q.pop();
        int step = temp.s;
        auto pos = temp.f;
        if(pos.f==0||pos.f==n-1||pos.s==0||pos.s==m-1){
            good = 1;
            end = pos;
            break;
        }
        if(walked[pos.f][pos.s]) continue;
        walked[pos.f][pos.s] = 1;
        For(k, 4){
            auto d = dir[k];
            int i = d[0]+pos.f, j = d[1]+pos.s;
            if(valid(i, j) && !walked[i][j]){
                if(visited[i][j]>step+1){
                    path[i][j] = dirr[k];
                    q.push({{i, j}, step+1});
                }
            }
        }
    }
    if(good){
        cout << "YES\n"; 
        string p;
        while(end != a){
            p.push_back(path[end.f][end.s]);
            switch(path[end.f][end.s]){
                case 'U':
                    end.f++;
                    break;
                case 'D':
                    end.f--;
                    break;
                case 'R':
                    end.s--;
                    break;
                case 'L':
                    end.s++;
                    break;
            }
        }
        cout << p.size() << '\n';
        reverse(p.begin(), p.end());
        cout << p;
        return 0;
    }
    cout << "NO\n";
}