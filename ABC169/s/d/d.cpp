#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef int64_t i6;
typedef std::vector<std::vector<int64_t> > Graph;

#define rep(i, n) for (int64_t i = 0; i < n; ++i)
#define rep2(i, n) for (int64_t i = 1; i <= n; ++i)
#define ALL(v) (v).begin(), (v).end()
#define Sort(x) sort(ALL(x))
#define Sort_rev(x) Sort(x);reverse(ALL(x))
#define Push_back(p, a, b) (p).push_back( make_pair( (a), (b) ) )

template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1;  } return 0;  }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1;  } return 0;  }
template<typename V,typename T> bool find_num(V v, T num) { if ( find(ALL(v), num) == v.end() ) { return false; } return true; }

// π M_PI
// deg = rad*180/M_PI

vector<pair<int64_t, int64_t> > prime_factorize(int64_t  N) {
    vector<pair<int64_t, int64_t> > res;
    for (int64_t a = 2; a * a <= N; ++a) {
        if (N%a != 0) continue;
        int64_t ex = 0; // 指数

        // 割れる限り割り続ける
        while (N % a == 0) {
            ++ex;
            N /= a;
        }

        // その結果を push
        // res.push_back({a, ex});
        Push_back(res, a, ex);
    }

    // 最後に残った数について
    if (N != 1) Push_back(res, N, 1);
    return res;
}

int main() {
    int64_t n;
    cin >> n;

    /*
    std::vector<int64_t> v(100);
    v[0] = 3;
    for (int64_t i = 2; i <= v.size(); ++i) {
        v[i-1] = v[i-2]+i+1;
    }*/
    // rep(i, v.size()) cout << i << " " << v[i] << endl;


    int64_t ans = 0;
    vector<pair<int64_t, int64_t> > res = prime_factorize(n);
    rep(i, res.size()) {
        int64_t num = res[i].second;
        if ( num <= 2 ) {
            ans++;
            continue;
        }
        int64_t j = 1;
        while (1) {
            if ( num > 2*j ) {
                num -= j;
                ans++;
                ++j;
            } else {
                break;
            }
        }
        ans++;
        /*
        int64_t num = 0;
        rep(j, v.size()) {
            if ( res[i].second == v[j] ) {
                num = 1;
                ans += j+2;
                break;
            }
            if ( res[i].second < v[j] ) break;
        }
        if (!num) ans++;*/
    }
    cout << ans << endl;
    ///////////////////////////////////
    /*
    vector<pair<int64_t, int64_t> > res = prime_factorize(n);
    // cout << n << ":";
    rep(i, res.size()) {
        /*
        rep(j, res[i].second) {
            cout << " " << res[i].first;
        }*//*
        cout << res[i].first << "^" << res[i].second << endl;
    }
    cout << endl;*/
    return 0;
}
