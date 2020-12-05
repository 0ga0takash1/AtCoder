#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef std::vector<std::vector<int64_t> > Graph;

#define rep(i, n) for (int64_t i = 0; i < n; ++i)
#define rep2(i, n) for (int64_t i = 1; i <= n; ++i)
#define repb(i, l, n) for (int64_t i = l; i < n; ++i)
#define repb2(i, l, n) for (int64_t i = l; i <= n; ++i)
#define repc(i, l, n, d) for (int64_t i = l; i < n; i+=d)
#define repc2(i, l, n, d) for (int64_t i = l; i <= n; i+=d)
#define repe(a, b) for (auto&(a) : (b))
#define ALL(v) (v).begin(), (v).end()
#define Sort(x) sort(ALL(x))
#define Sort_rev(x) Sort(x);reverse(ALL(x))
#define mp(a, b) make_pair((a), (b))
#define Push_back(a, b) push_back( mp( (a), (b) ) )
#define ctoi(c) (c)-'0'

template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1;  } return 0;  }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1;  } return 0;  }
template<typename V,typename T> bool find_num(V v, T num) { if ( find(ALL(v), num) == v.end() ) { return false; } return true; }

const int inf = 0x3fffffff;
const int64_t INF = 0x3fffffffffffffff;
const int64_t MOD = 1e9+7;

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

bool isPrime(int64_t x) {
    int64_t i;
    if(x < 2)return 0;
    else if(x == 2) return 1;
    if(x%2 == 0) return 0;
    for(i = 3; i*i <= x; i += 2) if(x%i == 0) return 0;
    return 1;
}

int64_t gcd(int64_t a, int64_t b) {
    return b ? gcd(b, a%b) : a;
}

int64_t lcm(int64_t a, int64_t b) {
    return a / gcd(a, b) * b;
}

int64_t nlcm(vector<int64_t> numbers) {
    int64_t res;
    res = numbers[0];
    for (int64_t i = 1; i < numbers.size(); i++) {
        res = lcm(res, numbers[i]);
    }
    return res;
}

int main() {
    int64_t n;
    cin >> n;
    /*
    int64_t ans = n+1;
    while (1) {
        int64_t f = 1;
        repb2(j, 2, n) {
            if ( ans%j != 1 ) {
                f = 0;
                break;
            }
        }
        if (f) {
            cout << ans << endl;
            return 0;
        }
        ans += n;
        if ( ans > 1e13 ) {
            break;
        }
    }
    */

    /*
    repc2(i, n+1, 1e13, n) {
        // cout << "a:" << i << endl;
        int64_t f = 1;
        repb2(j, 2, n) {
            if ( i%j != 1 ) {
                f = 0;
                break;
            }
        }
        if (f) {
            cout << i << endl;
            return 0;
        }
    }*/

    /*
    std::vector<int64_t> v = Eratosthenes(1e13);
    rep(i, v.size()) {
        int64_t f = 1;
        repb2(j, 2, n) {
            if ( v[i]%j != 1 ) {
                f = 0;
                break;
            }
        }
        if (f) {
            cout << v[i] << endl;
            return 0;
        }
    }
    */

    std::vector<int64_t> v;
    rep2(i, n) {
        v.push_back(i);
    }
    int64_t ans = nlcm(v);
    cout << ans+1 << endl;
    return 0;
}
