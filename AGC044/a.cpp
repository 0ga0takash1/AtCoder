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

map< int64_t, int > prime_factor(int64_t n) {
  map< int64_t, int > ret;
  for(int64_t i = 2; i * i <= n; i++) {
    while(n % i == 0) {
      ret[i]++;
      n /= i;
    }
  }
  if(n != 1) ret[n] = 1;
  return ret;
}

i6 func( i6 n, i6 a, i6 b, i6 c, i6 d ) {
    i6 ans = d;
    i6 num = 1;
    
    while ( ans != n ) {

    }
    return ans;
    return 0;
}

int main() {
    i6 t;
    cin >> t;
    std::vector<i6> n(t), a(t), b(t), c(t), d(t);
    vector<pair<i6, i6> > p;
    rep(i, t) {
        cin >> n[i] >> a[i] >> b[i] >> c[i] >> d[i];
        i6 num = n[i];
        i6 coin = 0;
        while ( (num%2 != 0) && (num%3 != 0) && (num%5 != 0) ) {
            if ( num%2 == 0 ) {
                num /= 2;
                coin += a[i];
            } else if ( num%3 == 0 ) {
                num /= 3;
                coin += b[i];
            } else if ( num%5 == 0 ) {
                num /= 5;
                coin += c[i];
            }
        }

        p.push_back( make_pair(num, coin) );
    }

    rep(i, t) {
        i6 num = p[i].first;
        i6 ans = p[i].second;
        ans += func(num, a[i], b[i], c[i], d[i]);
        cout << ans << endl;
    }
    return 0;
}
