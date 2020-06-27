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

int main() {
    int64_t n, m, k;
    cin >> n >> m >> k;
    int64_t a[n];
    std::vector<int64_t> va;
    va.push_back(0);
    rep(i, n) {
        cin >> a[i];
        if ( i == 0 ) {
            va.push_back(a[i]);
        } else {
            va.push_back(a[i]+va.at(va.size()-1));
        }
    }
    int64_t b[m];
    std::vector<int64_t> vb;
    vb.push_back(0);
    rep(i, m) {
        cin >> b[i];
        if ( i == 0 ) {
            vb.push_back(b[i]);
        } else {
            vb.push_back(b[i]+vb.at(vb.size()-1));
        }
    }
/*
    cout << "va" << endl;
    rep(i, va.size()) cout << va.at(i) << " ";
    cout << endl;

    cout << "vb" << endl;
    rep(i, vb.size()) cout << vb.at(i) << " ";
    cout << endl;
*/

    // std::vector<int64_t> ans;
    int64_t num = m;
    int64_t ans = 0;
    rep(i, va.size()) {
        if ( va[i] > k ) break;
        // rep(j, vb.size()) {
        for (int64_t j = num; j >= 0; --j) {
            if ( va[i]+vb[j] <= k ) {
                num = j;
                ans = max(ans, i+j);
                break;
                // ans.push_back(i+j);
                // cout << "a " << i << " " << j << " " << i+j << endl;
            }/* else {
                break;
            }*/
        }
    }

    // Sort_rev(ans);
    cout << ans << endl;
    return 0;
}
/*
    int64_t n, m, k;
    cin >> n >> m >> k;
    queue<int64_t> a;
    std::vector<int64_t> va;
    rep(i, n) {
        int64_t a1;cin >> a1;
        a.push(a1);
        va.push_back(a1);
    }

    queue<int64_t> b;
    std::vector<int64_t> vb;
    rep(i, m) {
        int64_t b1;cin >> b1;
        b.push(b1);
        vb.push_back(b1);
    }


    if ( accumulate(ALL(va), 0LL)+accumulate(ALL(vb), 0LL) <= k ) {
        cout << n+m << endl;
        return 0;
    }

    int64_t ans_apri = 0;
    if ( accumulate(ALL(va), 0LL) <= k ) {
        k -= accumulate(ALL(va), 0LL);
        ans_apri = n;
        if ( k == 0 ) {
            cout << ans_apri << endl;
            return 0;
        }
        int64_t bsum = 0;
        rep(i, m) {
            if ( bsum < k ) {
                bsum += vb[i];
                ans_apri++;
            } else {
                break;
            }
        }
        cout << "ap " << ans_apri << endl;
    }

    int64_t ans_bpri = 0;
    if ( accumulate(ALL(vb), 0LL) <= k ) {
        k -= accumulate(ALL(vb), 0LL);
        ans_bpri = m;
        if ( k == 0 ) {
            cout << ans_bpri << endl;
            return 0;
        }
        int64_t asum = 0;
        rep(i, n) {
            if ( asum < k ) {
                asum += va[i];
                ans_bpri++;
            } else {
                break;
            }
        }
        cout << "bp " << ans_bpri << endl;
    }
    int64_t pri = max(ans_apri, ans_bpri);

    int64_t ans = 0;
    int64_t sum = 0;
    rep(i, n+m) {
        if ( a.front() > k && b.front() > k ) break;

        if ( !a.empty() && !b.empty() ) {
            if ( a.front() <= b.front() ) {
                sum += a.front();
                a.pop();
            } else {
                sum += b.front();
                b.pop();
            }
        } else {
            if ( a.empty() ) {
                sum += b.front();
                b.pop();
            } else if ( b.empty() ) {
                sum += a.front();
                a.pop();
            }
        }

        if ( sum > k ) {
            break;
        } else {
            ans++;
            if ( sum == k ) break;
        }
    }

    int64_t asum = 0;
    int64_t acan = 0;
    rep(i, n) {
        if ( asum+va[i] < k ) {
            asum += va[i];
            acan++;
        } else {
            break;
        }
    }
    // cout << "ac " << acan << endl;
    int64_t bsum = 0;
    int64_t bcan = 0;
    rep(i, m) {
        if ( bsum+vb[i] < k ) {
            bsum += vb[i];
            bcan++;
        } else {
            break;
        }
    }
    // cout << "bc " << bcan << endl;

    int64_t can = max(acan, bcan);
    cout << max(ans, max(pri, can)) << endl;
    return 0;
}
    */

/*
    int64_t n, m, k;
    cin >> n >> m >> k;
    queue<int64_t> a;
    std::vector<int64_t> va;
    // int64_t asum = 0;
    // std::vector<int64_t> v;
    rep(i, n) {
        int64_t a1;cin >> a1;
        a.push(a1);
        va.push_back(a1);
        // asum += a1;
        // v.push_back(a[i]);
    }
    int64_t amin = *min_element(ALL(va));

    queue<int64_t> b;
    std::vector<int64_t> vb;
    // int64_t bsum = 0;
    rep(i, m) {
        int64_t b1;cin >> b1;
        b.push(b1);
        vb.push_back(b1);
        // bsum += b1;
        // v.push_back(b[i]);
    }
    int64_t bmin = *min_element(ALL(b));


    int64_t cost = 0;
    int64_t a_pri = 1;
    int64_t b_pri = 1;
    if ( amin <= bmin ) {
        rep(i, *find(ALL(va), amin)) {
            cost += va[i];
            if ( cost > k ) {
                a_pri = 0;
            }
        }
    } else {
        rep(i, *find(ALL(vb), bmin)) {
            cost += vb[i];
            if ( cost > k ) {
                b_pri = 0;
            }
        }
    }
    // Sort(v);
    int64_t ans = 0;
    int64_t sum = 0;
*/
/*
    if ( a_pri || b_pri ) {

    }
*/
/*
    rep(i, n+m) {
        if ( a.front() > k && b.front() > k ) break;

        if ( !a.empty() && !b.empty() ) {
            if ( a.front() <= b.front() ) {
                sum += a.front();
                // cout << "a " << a.front() << endl;
                a.pop();
            } else {
                sum += b.front();
                // cout << "b " << b.front() << endl;
                b.pop();
            }
        } else {
            if ( a.empty() ) {
                sum += b.front();
                b.pop();
                // cout << "b " << b.front() << endl;
            } else if ( b.empty() ) {
                sum += a.front();
                a.pop();
                // cout << "a " << a.front() << endl;
            }
        }

        if ( sum > k ) {
            break;
        } else {
            ans++;
            if ( sum == k ) break;
        }
    }
    cout << ans << endl;
    return 0;
}
*/
