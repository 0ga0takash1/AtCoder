/*---------------------------------------------*/
/*
    ABC176 D
 */
/*---------------------------------------------*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef int64_t i6;
typedef std::vector<std::vector<int64_t> > Graph;

#define rep(i, n) for (int64_t i = 0; i < n; ++i)
#define rep2(i, n) for (int64_t i = 1; i <= n; ++i)
#define repb(i, l, n) for (int64_t i = l; i < n; ++i)
#define repb2(i, l, n) for (int64_t i = l; i <= n; ++i)
#define ALL(v) (v).begin(), (v).end()
#define Sort(x) sort(ALL(x))
#define Sort_rev(x) Sort(x);reverse(ALL(x))
#define Push_back(p, a, b) (p).push_back( make_pair( (a), (b) ) )

template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1;  } return 0;  }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1;  } return 0;  }
template<typename V,typename T> bool find_num(V v, T num) { if ( find(ALL(v), num) == v.end() ) { return false; } return true; }

void search ( int64_t h, int64_t w,
             int64_t ch, int64_t cw,
             int64_t dh, int64_t dw, Graph G ) {
    std::vector<std::vector<int64_t> > seen( h, std::vector<int64_t>(w, 0) );
    rep(i, h) {
        rep(j, w) {
            if ( G[i][j] == 0 ) {
                seen[i].at(j) = 1;
            }
        }
    }
    queue<pair<int64_t, int64_t> > q;
    q.push(make_pair(ch, cw));
    int64_t ans = 0;
    std::vector<std::vector<pair<int64_t, int64_t>> > see(INF);
    while (1) {
        while ( !q.empty() ) {
            int64_t cch = q.front().first;
            int64_t ccw = q.front().second;
            seen[cch][ccw] = 1;
            q.pop();
            /*
            if ( cch > 0 && seen[cch-1][ccw] == 0 ) {
                q.push(make_pair(cch-1, ccw));
                seen[cch-1][ccw] = 1;
            }
            if ( cch < h-1 && seen[cch+1][ccw] == 0 ) {
                q.push(make_pair(cch+1, ccw));
                seen[cch+1][ccw] = 1;
            }
            if ( ccw > 0 && seen[cch][ccw-1] == 0 ) {
                q.push(make_pair(cch, ccw-1));
                seen[cch][ccw-1] = 1;
            }
            if ( ccw < h-1 && seen[cch][ccw+1] == 0 ) {
                q.push(make_pair(cch, ccw+1));
                seen[cch][ccw+1] = 1;
            }*/
            int64_t hh[] = {-1, 0, 1, 0};
            int64_t ww[] = {0, -1, 0, 1};
            rep(i, 4) {
                if ( 0 <= cch+dh[i] && cch+dh[i] <= h-1 ) {

                }
            }

            if ( seen[dh][dw] ) {
                cout << ans << endl;
                return;
            }
        }
        ans++;
    }


    return;
}

void search2 ( int64_t h, int64_t w,
             int64_t ch, int64_t cw,
             int64_t dh, int64_t dw, Graph G ) {
    std::vector<std::vector<int64_t> > pos_cost( h, std::vector<int64_t>(w, INF) );
    pos_cost[ch][cw] = 0;
    deque<pair<int64_t, int64_t> > q;
    q.emplace_front(ch, cw);
    while ( !q.empty() ) {
        int64_t current_h = q.front().first;
        int64_t current_w = q.front().second;
        if ( G[current_h][current_w] == 0 ) continue;
        int64_t cost = pos_cost[current_h][current_w];
        if ( pos_cost[current_h][current_w] < cost ) {
            /* code */
        }
        q.pop();
        int64_t hh[] = {-1, 0, 1, 0};
        int64_t ww[] = {0, -1, 0, 1};
        rep(i, 4) {
            int64_t sh = current_h+dh[i];
            int64_t sw = current_w+dw[i];
            if ( 0 <= sh && sh <= h-1 && 0 <= sw && sw <= w-1 ) {

            }
        }
    }
    return;
}

int main() {
    int64_t h, w;cin >> h >> w;
    int64_t ch, cw;cin >> ch >> cw;
    int64_t dh, dw;cin >> dh >> dw;
    ch--;cw--;dh--;dw--;
    Graph G(h);
    int64_t alldot = 1;
    rep(i, h) {
        rep(j, w) {
            char s;
            cin >> s;
            if ( s == '.' ) {
                G[i].push_back(1);
            } else if ( s == '#' ) {
                G[i].push_back(0);
                alldot = 0;
            }
        }
    }

    int64_t ans = 0;
    if (!alldot) {
        search(h, w, ch, cw, dh, dw, G);
    }
    cout << ans << endl;
    return 0;
}
