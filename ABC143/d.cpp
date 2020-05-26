#include <bits/stdc++.h>
using namespace std;

#define Sort(x) sort(x.begin(), x.end())
#define Sort_rev(x) sort(x.begin(), x.end(), greater<int>())
#define ll long long

int main() {
    int n;
    cin >> n;
    int l[n];
    std::vector<int> v;
    for (int i = 0; i < n; ++i) {
        cin >> l[i];
        v.push_back(l[i]);
    }
    Sort_rev(v);
    int ans = 0;

    for (int i = 0; i < n-2; ++i) {
        for (int j = i+1; j < n-1; ++j) {
            for (int k = j+1; k < n; ++k) {
                if ( v[i] >= v[j]+v[k] ) {
                    break;
                }
                ans++;
            }
        }
    }

    cout << ans << endl;
    return 0;
}

/*
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> l_l;
typedef pair<int, int> i_i;
template<class T>
inline bool chmax(T &a, T b) {
    if(a < b) {
        a = b;
        return true;
    }
    return false;
}

template<class T>
inline bool chmin(T &a, T b) {
    if(a > b) {
        a = b;
        return true;
    }
    return false;
}

#define EPS (1e-7)
#define INF (1e9)
#define PI (acos(-1))
//const ll mod = 1000000007;
ll N;
ll L[4000];

void input() {
    cin >> N;
    for(int i = 1; i <= N; i++) cin >> L[i];
}

void solve() {
    input();
    vector<ll> v(N);
    for(int i = 0; i < N; i++) v[i] = L[i+1];
    sort(v.begin(), v.end());
    ll ans = 0;
    for(ll mid = N - 1; mid >= 0; mid--) {
        for(ll low = mid - 1; low >= 0; low--) {
            auto itr = lower_bound(v.begin(), v.end(), v[mid] + v[low]);
            ll ng = distance(itr, v.end());
            ans += (N - 1 - mid) - ng;
            //cerr << v[mid] + v[low] << " " << ng << " " << (N-1-mid)-ng << endl;
        }
    }
    cout << ans << endl;
    return;
}

int main() {
    solve();
    return 0;
}
*/
