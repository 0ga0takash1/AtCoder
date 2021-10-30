#if !__INCLUDE_LEVEL__
#include __FILE__

// π acos(-1)
// deg = rad*180/M_PI

double deg_to_rad( double deg ) {
    return (deg*acos(-1))/180;
}

double rad_to_deg( double rad ) {
    return (rad*180)/acos(-1);
}

const int inf = 0x3fffffff;
const int64_t INF = 0x3fffffffffffffff;
const string ABC = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
const string abc = "abcdefghijklmnopqrstuvwxyz";

/*----------------------------------------------------------------------*/
void Alphabet (char s) {
    if (s >= 'a' && s <= 'z') {
        cout << "small" << endl;
    } else if(s >= 'A' && s <= 'Z') {
        cout << "large" << endl;
    } else if(s >= '0') {
        cout << "number" << endl;
    }
    return;
}
/*----------------------------------------------------------------------*/
// 辞書順改造
void modify_dic_order () {
    string new_order;
    cin >> new_order;
    std::vector<int64_t> new_o(26);
    rep(i, new_order.length()) {
        new_o[new_order[i]-'a'] = i;
    }
    in1(n);
    Graph S(n);
    repi(v, S) {
        string s;
        cin >> s;
        repi(c, s) v.push_back(new_o[c-'a']);
    }
    Sort(S);
    repi(ans, S) {
        repi(a, ans) cout << new_order[a];
        cout << endl;
    }
    return;
}
/*----------------------------------------------------------------------*/
// 最大公約数
// gcd(a, b) == 1 でaとbは互いに素
int64_t gcd(int64_t a, int64_t b) {
    return b ? gcd(b, a%b) : a;
}

int64_t ngcd(vector<int64_t> a){
    int res;
    res = a[0];
    for(int64_t i = 1; i < a.size() && res != 1; i++) {
        res = gcd(a[i], res);
    }
    return res;
}

// a以上b以下の組(n, m)でGCD(n, m)の最大値c
int64_t arc_GCD(int64_t left, int64_t right) {
    rep_(res, right) {
        if ( (left+res-1)/res < right/res ) {
            return res;
        }
    }
    return 1;
}
/*----------------------------------------------------------------------*/
// 最小公倍数
int64_t lcm(int64_t a, int64_t b) {
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
bool isPrime(int64_t x) {
    int64_t i;
    if(x < 2)return 0;
    else if(x == 2) return 1;
    if(x%2 == 0) return 0;
    for(i = 3; i*i <= x; i += 2) if(x%i == 0) return 0;
    return 1;
}
/*----------------------------------------------------------------------*/
// 桁和
int64_t digsum(int64_t n) {
    int res = 0;
    while(n > 0) {
        res += n%10;
        n /= 10;
    }
    return res;
}
/*----------------------------------------------------------------------*/
// 約数列挙
vector<int64_t> enum_div(int64_t n) {
    vector<int64_t> ret;
    for(int64_t i = 1; i*i <= n; ++i){
        if(n%i == 0){
            ret.push_back(i);
            if(i*i != n){
                ret.push_back(n/i);
            }
        }
    }
    Sort(ret);
    return ret;
}
/*----------------------------------------------------------------------*/
// 素因数分解
vector<pair<int64_t, int64_t> > prime_factorize(int64_t N) {
    vector<pair<int64_t, int64_t> > res;
    for (int64_t a = 2; a * a <= N; ++a) {
        if (N % a != 0) continue;
        int64_t ex = 0;

        while (N % a == 0) {
            ++ex;
            N /= a;
        }

        res.push_back({a, ex});
    }

    if (N != 1) res.push_back({N, 1});
    return res;
}
/*----------------------------------------------------------------------*/
// 素因数分解、約数の個数
int64_t div_num (int64_t n) {
    vector<int64_t> x(n+1);
	int64_t num = n;
    int64_t ans = 1;

    repb2(i, 2, n) {
		while (num%i == 0) {
			x.at(i)++;
			num /= i;
		}
	}

    repb2(i, 2, n) {
		ans *= x.at(i)+1;
	}
    return ans;
}
/*----------------------------------------------------------------------*/
// n進数変換
std::vector<int64_t> change_base(int64_t a, int64_t base) {
    std::vector<int64_t> res;
    if( a == 0 ) {
        res.push_back(0);
        return res;
    }
    while(a){
        int64_t rest = a%base;
        res.push_back(rest);
        a /= base;
    }
    reverse(ALL(res));
    return res;
}

// stringとchange_base()した数を比較
bool Compare_string_number ( string s, vector<int64_t> v ) {
    if ( v.size() > s.size() ) return true;
    if ( v.size() < s.size() ) return false;

    rep(i, s.size()) {
        int64_t a = ctoi(s[i]), b = v[i];//atoi(v[i].c_str());
        if ( a > b ) {
            return false;
        } else if ( a < b ) {
            return true;
        }
    }
    return true;
}
/*----------------------------------------------------------------------*/
// A*B*C = nとなるnから、A,B,Cの組み合わせ
int64_t ABC_n (int64_t n) {
    int64_t ans = 0;
    rep2(a, n) {
        for (int64_t b = 1; a*b <= n; ++b) {
            ans += n/a/b;
        }
    }
    return ans;
}
/*----------------------------------------------------------------------*/
// 点(x, y)を点(ox, oy)を中心に半時計回りにtheta回転した座標を返す
// first = x, second = y
pair<long double, long double> rotate ( long double x, long double y,
                                        long double ox, long double oy,
                                        long double theta) {
    x -= ox;
    y -= oy;
    return {x*cos(theta)-y*sin(theta)+ox, y*cos(theta)+x*sin(theta)+oy};
}
/*----------------------------------------------------------------------*/
// aコの0とbコの1の並び替えの総数
// (a+b)!/a!b!
int64_t ab_a_b (int64_t a, int64_t b) {
    int64_t res = 1, to_not_mul = min(a, b);
    rep_b2(i, a+b, max(a, b)) {
        if ( to_not_mul == 1 ) {
            res *= i;
        } else {
            if ( !(i%to_not_mul) ) {
                res *= i/to_not_mul;
                --to_not_mul;
            } else {
                res *= i;
            }
            while ( !(res%to_not_mul) && to_not_mul != 1 ) {
                res /= to_not_mul;
                --to_not_mul;
            }
        }
    }
    return res;
}
/*----------------------------------------------------------------------*/
// 整数nのd桁以下の切り捨て
// truncate(123456789, 3) == 123456000
// truncate(123456789, 5) == 123400000
int64_t truncate (int64_t n, int64_t d) {
    int64_t ten = pow(10, d);
    if ( n%ten ) n/=ten;n*=ten;
    return n;
}

// 整数nのd桁以下の四捨五入
// rounding(123456789, 5) == 123500000
// rounding(123456789, 6) == 123000000
int64_t rounding(int64_t n, int64_t d) {
    int64_t ten = pow(10, d);
    if ( n%ten ) {
        n += 5*pow(10, d-1);
        n/=ten;n*=ten;
    }
    return n;
}

// 整数nのd桁以下の切り上げ
// round_up(123456789, 2) == 123456800
// round_up(123456789, 5) == 123500000
int64_t round_up(int64_t n, int64_t d) {
    int64_t ten = pow(10, d);
    if ( n%ten ) {
        n += pow(10, d);
        n/=ten;n*=ten;
    }
    return n;
}

// ガウス記号
// floor_func(5, 2) == [2.5] == 2
int64_t floor_func(int64_t a, int64_t b) {
    return ((a-1)/b)+1;
}
/*----------------------------------------------------------------------*/
// エラトステネスのふるい
std::vector<int64_t> Eratosthenes( int64_t n ) {
    std::vector<int64_t> is_prime(n+1, 1);

    std::vector<int64_t> P;
    repb2(i, 2, n) {
        if( is_prime[i] ) {
            for( int j = 2 * i; j <= n; j += i ) is_prime[j] = 0;
            P.push_back(i);
        }
    }
    return P;
}
/*----------------------------------------------------------------------*/

int64_t nCr(int64_t n , int64_t r) {
    if ( n == r || n == 1 || r == 0 ) {
        return 1;
    }

    r = min(r, n-r);
    if ( r == 1 ) {
        return n;
    } else {
        std::vector<std::vector<int64_t> > v(n + 1,std::vector<int64_t>(n + 1, 0));
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
// MOD
const int64_t MOD = 1e9+7;

int64_t Mod(int64_t a, int64_t mod) {
    return (a%mod + mod)%mod;
}

int64_t pow_mod(int64_t x, int64_t n, int64_t mod) {
    int64_t res = 1;
    while(n > 0) {
        if (n & 1) {
            res = res*x%mod;
        }
        x = x*x%mod;
        n >>= 1;
    }
    return res;
}

int64_t extGCD(int64_t a, int64_t b, int64_t &x, int64_t &y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    int64_t d = extGCD(b, a%b, y, x);
    y -= a / b * x;
    return d;
}

int64_t modinv(int64_t a, int64_t mod) {
    int64_t x, y;
    extGCD(a, mod, x, y);
    return Mod(x, mod);
}

int64_t nCr_mod(int64_t n, int64_t r, int64_t mod) {
    if ( n == r || n == 1 || r == 0 ) {
        return 1;
    }

    r = min(r, n-r);
    if ( r == 1 ) {
        return n;
    } else {
        int64_t n_to_n_r = n;
        int64_t r_to_1 = r;
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

bool pc(pair<int64_t, int64_t> a, pair<int64_t, int64_t> b) {
    // まずsecond
    if ( a.second != b.second ) return a.second < b.second;

    // secondが同じときはfirst
    if ( a.first != b.first ) return a.first < b.first;
    else return true;
}

bool pcr(pair<int64_t, int64_t> a, pair<int64_t, int64_t> b) {
    // まずsecond
    if ( a.second != b.second ) return a.second > b.second;

    // secondが同じときはfirst
    if ( a.first != b.first ) return a.first < b.first;
    else return true;
}

/*----------------------------------------------------------------------*/

void permutation(int64_t num, bool rev) {
    std::vector<int64_t> v;
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
    int64_t x;
    int64_t y;
    int64_t depth;
};
queue<Corr> q;
void BFS(vector<vector<int64_t> > grid) {
    // 既に探索の場所を1，探索していなかったら0を格納する配列
    vector<vector<int64_t> > ispassed(grid.size(), vector<int64_t>(grid[0].size(), false));
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
    return;
}
/*----------------------------------------------------------------------*/

typedef std::vector<std::vector<int64_t> > Graph;

void bfs ( Graph G ) {
    std::vector<int64_t> seen(G.size(), 0);
    queue<int64_t> q;
    int64_t start_num = 0;
    q.push(start_num);
    while ( !q.empty() ) {
        int64_t num = q.front();
        seen[num] = 1;
        q.pop();
        rep(i, G[num].size()) {
            int64_t see = G[num].at(i);
            if ( seen[see] == 0 ) {
                q.push(see);
                seen[see] = 1;
            }
        }
    }
}

vector<int64_t> seen(INF, 0);
void dfs(Graph G, int v) {
    seen[v] = true; // v を訪問済にする

    // v から行ける各頂点 next_v について
    repi(next_v, G[v]) {
        if (seen[next_v]) continue; // next_v が探索済だったらスルー
        dfs(G, next_v);
    }
    /*
    for (auto next_v : G[v]) {
        if (seen[next_v]) continue; // next_v が探索済だったらスルー
        dfs(G, next_v); // 再帰的に探索
    }*/
    /*
    rep(i, G[v].size()) {
        if (seen[G[v].at(i)]) continue; // next_v が探索済だったらスルー
        dfs(G, G[v].at(i)); // 再帰的に探索
    }*/
}
/*----------------------------------------------------------------------*/
// UnionFind
struct UnionFind {
    //自身が親であれば、その集合に属する頂点数に-1を掛けたもの
    //そうでなければ親のid
    vector<int64_t> r;

    UnionFind(int64_t N) {
        r = vector<int64_t>(N, -1);
    }

    int64_t root(int64_t x) {
        if (r[x] < 0) return x;
        return r[x] = root(r[x]);
    }

    bool unite(int64_t x, int64_t y) {
        x = root(x);
        y = root(y);
        if (x == y) return false;
        if (r[x] > r[y]) swap(x, y);
        r[x] += r[y];
        r[y] = x;
        return true;
    }

    int64_t size(int64_t x) {
        return -r[root(x)];
    }
};
/*----------------------------------------------------------------------*/
// ダイクストラ
class DIJKSTRA {
    public:
        int64_t V;

        struct dk_edge {
            int64_t to;
            int64_t cost;
        };

        typedef pair<int64_t, int64_t> PI;  // firstは最短距離、secondは頂点の番号
        vector<vector<dk_edge>> G;
        vector<int64_t> d;      //これ答え。d[i]:=V[i]までの最短距離
        vector<int64_t> prev;  //経路復元

        DIJKSTRA(int64_t size) {
            V = size;
            G = vector<vector<dk_edge>>(V);
            prev = vector<int64_t>(V, -1);
        }

        void add(int64_t from, int64_t to, int64_t cost) {
            dk_edge e = {to, cost};
            G[from].push_back(e);
        }

        void dijkstra(int64_t s) {
            // greater<P>を指定することでfirstが小さい順に取り出せるようにする
            priority_queue<PI, vector<PI>, greater<PI>> que;
            d = vector<int64_t>(V, INF);
            d[s] = 0;
            que.push(PI(0, s));

            while (!que.empty()) {
                PI p = que.top();
                que.pop();
                int64_t v = p.second;
                if (d[v] < p.first) continue;
                rep(i, G[v].size()) {
                    dk_edge e = G[v][i];
                    if (d[e.to] > d[v] + e.cost) {
                        d[e.to] = d[v] + e.cost;
                        prev[e.to] = v;
                        que.push(PI(d[e.to], e.to));
                    }
                }
            }
        }

        vector<int64_t> get_path(int64_t t) {
            vector<int64_t> path;
            for (; t != -1; t = prev[t]) {
                // tがsになるまでprev[t]をたどっていく
                path.push_back(t);
            }
            //このままだとt->sの順になっているので逆順にする
            reverse(path.begin(), path.end());
            return path;
        }

        void show(void) {
            for (int i = 0; i < d.size(); i++) cout << d[i] << " ";
            cout << endl;
        }
};

/*----------------------------------------------------------------------*/
// 45 度回転 マンハッタン距離
/*
zi = xi+yi, wi = xi−yi とすると、
|xi−xj| + |yi−yj| = max(|zi−zj|, |wi−wj|)
 */
 /*----------------------------------------------------------------------*/
// bit全探索
int64_t bit_search (int64_t n, int64_t k, int64_t c[], int64_t d[]) {
    int64_t k2 = 1 << k; // 2^k通りの配分が考えられる

    // bit全探索、桁が0だったらc、1だったらdに配分する
    rep(s, k2) {
        // それぞれの数に対応する皿づくり
        std::vector<int64_t> dish(n+1, 0);
        rep(i, k) {
            //iのj桁目 が0ならc、1ならdを選ぶ
            if ( s>>i & 1 ) {
                ++dish[d[i]];
            } else {
                ++dish[c[i]];
            }
        }

        // 以下

    }
    return 0;
}
/*----------------------------------------------------------------------*/
// 二分探索
int64_t Binary_search () {
    int64_t ok = 0, ng = INF;
    while ( ok+1 < ng ) {
        int64_t num = (ok+ng)/2;
        if ( /*条件*/1 ) ok = num;
        else ng = num;
    }
    return ok;
}
/*----------------------------------------------------------------------*/

int main() {
    return 0;
}

#else
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef int64_t i6;
typedef std::vector<std::vector<int64_t> > Graph;

#define in1(n) int64_t n;cin >> n;
#define in2(n, m) int64_t n, m;cin >> n >> m;
#define in3(n, m, k) int64_t n, m, k;cin >> n >> m >> k;
#define in4(a, b, c, d) int64_t a, b, c, d;cin >> a >> b >> c >> d;
#define rep(i, n) for (int64_t i = 0; i < n; ++i)
#define rep2(i, n) for (int64_t i = 1; i <= n; ++i)
#define repb(i, l, n) for (int64_t i = l; i < n; ++i)
#define repb2(i, l, n) for (int64_t i = l; i <= n; ++i)
#define repc(i, l, n, d) for (int64_t i = l; i < n; i+=d)
#define repc2(i, l, n, d) for (int64_t i = l; i <= n; i+=d)
/*
#define rep_(i, r) for (int64_t i = r; i > 0; --i)
#define rep_2(i, r) for (int64_t i = r; i >= 0; --i)
#define rep_b(i, r, l) for (int64_t i = r; i > l; --i)
#define rep_b2(i, r, l) for (int64_t i = r; i >= l; --i)
#define rep_c(i, r, l, d) for (int64_t i = r; i > l; i-=d)
#define rep_c2(i, r, l, d) for (int64_t i = r; i >= l; i-=d)
*/
#define rep_(i, r) for (int64_t i = r-1; i >= 0; --i)
#define rep_2(i, r) for (int64_t i = r; i > 0; --i)
#define rep_b(i, r, l) for (int64_t i = r; i >= l; --i)
#define rep_b2(i, r, l) for (int64_t i = r; i > l; --i)
#define rep_c(i, r, l, d) for (int64_t i = r; i >= l; i-=d)
#define rep_c2(i, r, l, d) for (int64_t i = r; i > l; i-=d)
#define repf(i, l, c, d) for (int64_t i = l; c; i+=d)
#define repi(a, b) for (auto&(a) : (b))
#define ALL(v) (v).begin(), (v).end()
#define Sort(x) sort(ALL(x))
#define Sort_rev(x) Sort(x);reverse(ALL(x))
#define Sort_pair(x, p) sort(ALL(x), (p))
#define vector2(a, n, k) std::vector<std::vector<int64_t>> a(n, std::vector<int64_t>(k))
#define mp(a, b) make_pair((a), (b))
#define Push_back(a, b) push_back( mp( (a), (b) ) )
// #define Push_back(p, a, b) (p).push_back( make_pair( (a), (b) ) )
#define ctoi(c) ((c)-'0')

template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1;  } return 0;  }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1;  } return 0;  }
template<typename V,typename T> bool find_num(V v, T num) { if ( find(ALL(v), num) == v.end() ) { return false; } return true; }
template<typename map,typename T> bool find_map(map m, T num) { auto itr = m.find(num); if ( itr == m.end() ) { return false; } return true; }

#endif
