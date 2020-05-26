#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef int64_t i6;

#define rep(i, n) for (ll i = 0; i < n; ++i)
#define rep2(i, n) for (ll i = 1; i <= n; ++i)
#define Sort(x) sort(x.begin(), x.end())
#define Sort_rev(x) sort(x.begin(), x.end(), greater<int>())
#define ALL(v) (v).begin(), (v).end()

// π M_PI
// deg = rad*180/M_PI

double deg_to_rad( double deg ) {
    return (deg*M_PI)/180;
}

double rad_to_deg( double rad ) {
    return (rad*180)/M_PI;
}

const int inf = 0x3fffffff;
const ll INF = 0x3fffffffffffffff;
const string ABC = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
const string abc = "abcdefghijklmnopqrstuvwxyz";

/*----------------------------------------------------------------------*/
// 最大公約数
ll gcd(ll a, ll b) {
    return b ? gcd(b, a%b) : a;
}

ll ngcd(vector<ll> a){
    int res;
    res = a[0];
    for(ll i = 1; i < a.size() && res != 1; i++) {
        res = gcd(a[i], res);
    }
    return res;
}
/*----------------------------------------------------------------------*/
// 最小公倍数
ll lcm(ll a, ll b) {
    return a / gcd(a, b) * b;
}

int nlcm(vector<int> numbers) {
    int res;
    res = numbers[0];
    for (int i = 1; i < numbers.size(); i++) {
        res = lcm(res, numbers[i]);
    }
    return res;
}
/*----------------------------------------------------------------------*/
// 素数判定
bool isPrime(ll x) {
    int i;
    if(x < 2)return 0;
    else if(x == 2) return 1;
    if(x%2 == 0) return 0;
    for(i = 3; i*i <= x; i += 2) if(x%i == 0) return 0;
    return 1;
}
/*----------------------------------------------------------------------*/
// 桁和
ll digsum(ll n) {
    int res = 0;
    while(n > 0) {
        res += n%10;
        n /= 10;
    }
    return res;
}
/*----------------------------------------------------------------------*/
// 約数列挙
vector<ll> enum_div(ll n) {
    vector<ll> ret;
    for(int i = 1 ; i*i <= n ; ++i){
        if(n%i == 0){
            ret.push_back(i);
            if(i != 1 && i*i != n){
                ret.push_back(n/i);
            }
        }
    }
    return ret;
}
/*----------------------------------------------------------------------*/

ll nCr(ll n , ll r) {
    if ( n == r || n == 1 || r == 0 ) {
        return 1;
    }

    r = min(r, n-r);
    if ( r == 1 ) {
        return n;
    } else {
        std::vector<std::vector<ll> > v(n + 1,std::vector<ll>(n + 1, 0));
        for (int i = 0; i < v.size(); i++) {
            v[i][0] = 1;
            v[i][i] = 1;
        }
        for (int j = 1; j < v.size(); j++) {
            for (int k = 1; k < j; k++) {
                v[j][k] = (v[j - 1][k - 1] + v[j - 1][k]);
            }
        }
        return v[n][r];
    }
}
/*----------------------------------------------------------------------*/

const ll MOD = 1e9 + 7;

ll Mod(ll a, ll mod) {
    return (a%mod + mod)%mod;
}

ll pow_mod(ll x, ll n, ll mod) {
    ll res = 1;
    while(n > 0) {
        if (n & 1) {
            res = res*x%mod;
        }
        x = x*x%mod;
        n >>= 1;
    }
    return res;
}

ll extGCD(ll a, ll b, ll &x, ll &y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    ll d = extGCD(b, a%b, y, x);
    y -= a / b * x;
    return d;
}

ll modinv(ll a, ll mod) {
    ll x, y;
    extGCD(a, mod, x, y);
    return Mod(x, mod);
}

ll nCr_mod(ll n, ll r, ll mod) {
    if ( n == r || n == 1 || r == 0 ) {
        return 1;
    }

    r = min(r, n-r);
    if ( r == 1 ) {
        return n;
    } else {
        ll n_to_n_r = n;
        ll r_to_1 = r;
        rep2(i, r-1) {
            n_to_n_r *= n-i;
            n_to_n_r %= mod;
            r_to_1 *= r-i;
            r_to_1 %= mod;
        }
        // r_to_1 = pow_mod(r_to_1, mod-2, mod);
        r_to_1 = modinv(r_to_1, MOD);
        return n_to_n_r*r_to_1%mod;
    }
}
/*----------------------------------------------------------------------*/

bool pairCompare(const pair<string, ll>& firstElof, const pair<string, ll>& secondElof) {
    return firstElof.second < secondElof.second;
}

bool pairCompareRev(const pair<string, ll>& firstElof, const pair<string, ll>& secondElof) {
    return firstElof.second > secondElof.second;
}

bool pairCompare(const pair<ll, ll>& firstElof, const pair<ll, ll>& secondElof) {
    return firstElof.first < secondElof.first;
}

bool pairCompareRev(const pair<ll, ll>& firstElof, const pair<ll, ll>& secondElof) {
    return firstElof.first > secondElof.first;
}

// vector<pair<int, int> > pairs;
// pairs.push_back( make_pair(a, b) );
// sort(ALL(pairs), pairCompare);
// reverse(ALL(v));
/*----------------------------------------------------------------------*/

void permutation(ll num, bool rev) {
    std::vector<ll> v;
    rep(i, num) {
        v.push_back(i);
    }

    if (!rev) {
        do {
            rep(i, num) {
                cout << v[i] << " ";
            }
        } while(next_permutation(ALL(v)));
    } else {
        do {
            rep(i, num) {
                cout << v[i] << " ";
            }
        } while(prev_permutation(ALL(v)));
    }
    cout << endl;
}
/*----------------------------------------------------------------------*/
// 幅優先探索

// 各座標に格納したい情報を構造体にする
// 今回はX座標,Y座標,深さ(距離)を記述している
struct Corr {
    ll x;
    ll y;
    ll depth;
};
queue<Corr> q;
ll bfs(vector<vector<ll> > grid) {
    // 既に探索の場所を1，探索していなかったら0を格納する配列
    vector<vector<ll> > ispassed(grid.size(), vector<ll>(grid[0].size(), false));
    // このような記述をしておくと，この後のfor文が綺麗にかける
    int dx[8] = {1, 0, -1, 0};
    int dy[8] = {0, 1, 0, -1};
    while(!q.empty()) {
        Corr now = q.front();q.pop();
        /*
            今いる座標は(x,y)=(now.x, now.y)で，深さ(距離)はnow.depthである
            ここで，今いる座標がゴール(探索対象)なのか判定する
        */
        for(int i = 0; i < 4; i++) {
            int nextx = now.x + dx[i];
            int nexty = now.y + dy[i];

            // 次に探索する場所のX座標がはみ出した時
            if(nextx >= grid[0].size()) continue;
            if(nextx < 0) continue;

            // 次に探索する場所のY座標がはみ出した時
            if(nexty >= grid.size()) continue;
            if(nexty < 0) continue;

            // 次に探索する場所が既に探索済みの場合
            if(ispassed[nexty][nextx]) continue;

            ispassed[nexty][nextx] = true;
            Corr next = {nextx, nexty, now.depth+1};
            q.push(next);
        }
    }
}
/*----------------------------------------------------------------------*/

int main() {
    return 0;
}
