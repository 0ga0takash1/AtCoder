/*---------------------------------------------*/
/*
    ABC167 C
 */
/*---------------------------------------------*/


#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef int64_t i6;

#define rep(i, n) for (ll i = 0; i < n; ++i)
#define rep2(i, n) for (ll i = 1; i <= n; ++i)
#define ALL(v) (v).begin(), (v).end()
#define Sort(x) sort(ALL(x))
#define Sort_rev(x) Sort(x);reverse(ALL(x))

template<typename V,typename T>
T find_num(V v, T num) {
    if ( find(ALL(v), num) == v.end() ) {
        return false;
    } else {
        return true;
    }
}

// π M_PI
// deg = rad*180/M_PI

int num = 0;

void combi(int A[], int p, int w, int n, int r)
{
    if(p > 0) {
        int i;
        for(i = 0;i <= w;i++) {
            A[p] = i;
            combi(A, p-1, w-i, n, r);
        }
    } else {                                              /*  ★   */
        int i, j, m;
        num++;
        // printf("%d:\t", num);
        m = 0;
        for(i = 1;i <= r;i++){
            for(j = 0;j < A[i];j++, m++) printf(" a0");
            printf(" b1");
            m++;
        }
        for(;m < n;m++) printf(" c0");
        printf("\n");
    }
}

int main() {
    ll n, m, x;
    cin >> n >> m >> x;
    ll c[n];
    ll a[n][m];
    rep(i, n) {
        cin >> c[i];

        rep(j, m) {
            cin >> a[i][j];
        }
    }

    ll ans = INT_MAX;
    rep(bit, 1 << n) {
        ll cost = 0;
        std::vector<ll> v(m, 0);
        rep(i, n) {
            if ( bit & (1<<i) ) {
                cost += c[i];
                rep(j, m) {
                    v[j] += a[i][j];
                }
            }

            ll flag = 1;
            rep(j, m) {
                if ( v[j] < x ) {
                    flag = 0;
                    break;
                }
            }
            // cout << "a " << cost << endl;
            if ( flag ) {
                ans = min(ans, cost);
            }
        }
    }

    if ( ans == INT_MAX ) {
        cout << -1 << endl;
    } else {
        cout << ans << endl;
    }
    return 0;

    ////////////////////////////////
    /*
    int n = 5;
    int r = 3;
    int K[128];
    combi(K, r, n-r, n, r);
    return 0;
    */
    /*
    ll n, m, x;
    cin >> n >> m >> x;
    ll c[n];
    // vector<pair<ll, ll> > p;
    ll a[n][m];
    rep(i, n) {
        cin >> c[i];
        // p.push_back( make_pair(c[i], i) );

        rep(j, m) {
            cin >> a[i][j];
        }
    }

    std::vector<ll> v;
    rep2(i, n) {
        std::vector<std::vector<ll> > v2;
        foreach_comb(n, i, [](int *indexes) {
            // std::cout << indexes[0] << ',' << indexes[1] << ',' << indexes[2] << std::endl;
            rep(j, i) {
                v2[v2.size()].push_back(indexes[j]);
            }
        });

        ll able = 0;
        rep(j, v2.size()) {
            std::vector<ll> v3(m, 0);
            ll ans = 0;
            rep(k, v2[j].size()) {
                ans += c[v2[j].at(k)];
                rep(l, m) {
                    v3[l] += a[v2[j].at(k)][l];
                }

                ll able2 = 1;
                rep(j, m) {
                    if ( v[j] < x ) {
                        able2 = 0;
                        break;
                    }
                }
                able = able2;
            }
        }
        if ( able ) {
            v.push_back(ans);
        }
    }

    cout << *min_element(ALL(v)) << endl;*/
    /*
    sort(ALL(p), pair_Cf);
    ll able = 0;
    ll ans = 0;
    std::vector<ll> v(m, 0);
    rep(i, n) {
        ans += p[i].first;
        rep(j, m) {
            v[j] += a[p[i].second][j];
        }

        ll able2 = 1;
        rep(j, m) {
            // cout << m << "a " << v[j] << " ";
            if ( v[j] < x ) {
                able2 = 0;
                break;
            }
        }
        // cout << endl;
        able = able2;

        if ( able ) {
            break;
        }
    }

    if ( !able ) {
        cout << -1 << endl;
    } else {
        cout << ans << endl;
    }
    */
    return 0;
}
