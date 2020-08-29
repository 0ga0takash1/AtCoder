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

const int64_t MOD = 1e9 + 7;

int64_t ans = 0;

template<class T>
void combination(const vector<T>& seed, int target_size,
                 bool (*callback)(const vector<T>&),
                 std::vector<int64_t> v, int64_t ans ) {
    vector<int64_t> indices(target_size);
    const int seed_size = seed.size();
    int start_index = 0;
    int size = 0;

    while (size >= 0) {
        for (int i = start_index; i < seed_size; ++i) {
            indices[size++] = i;
            if (size == target_size) {
                vector<T> comb(target_size);
                vector<T> comb2(target_size);
                for (int x = 0; x < target_size; ++x) {
                    comb[x] = seed[indices[x]];
                    comb2[x] = v[comb[x]];
                }
                if (callback(comb2)) return;
                // ans += callback(comb2);
                break;
            }
        }
        --size;
        if (size < 0) break;
        start_index = indices[size] + 1;
    }
    cout << ans << endl;
}

///////////////// How to use

bool my_callback(const vector<int>& comb) {
    int n = comb.size();
    int64_t num = 1;
    for (int i=0; i<n; ++i) {
        num *= comb[i]%MOD;
    }
    ans += num;
    return false;
}

int main() {
    int64_t n;
    cin >> n;
    std::vector<int64_t> a(n);
    rep(i, n) {
        cin >> a[i];
    }

    vector<int> vals(n);
    rep(i, n) {
        vals.push_back(i);
    }

    combination(vals, 2, my_callback, a, ans);
    return 0;
}

/*
void recursive_comb(int *indexes, int s, int rest, std::function<void(int *)> f) {
  if (rest == 0) {
    f(indexes);
  } else {
    if (s < 0) return;
    recursive_comb(indexes, s - 1, rest, f);
    indexes[rest - 1] = s;
    recursive_comb(indexes, s - 1, rest - 1, f);
  }
}

// nCkの組み合わせに対して処理を実行する
void foreach_comb(int n, int k, std::function<void(int *)> f) {
  int indexes[k];
  recursive_comb(indexes, n - 1, k, f);
}

int main() {
    int64_t n;
    cin >> n;
    std::vector<int64_t> a(n);
    rep(i, n) {
        cin >> a[i];
    }
    int64_t ans = 0;
    foreach_comb(n, 2, [](int *indexes) {
        // std::cout << indexes[0] << ',' << indexes[1] << ',' << indexes[2] << std::endl;
        ans += indexes[0]*indexes[1];
    });
    cout << ans << endl;
    return 0;
}
*/
/*
int main() {
    int64_t n;
    cin >> n;
    std::vector<int64_t> a(n);
    rep(i, n) {
        cin >> a[i];
    }
    std::vector<int64_t> v;
    rep(i, num) {
        v.push_back(i);
    }


    return 0;
}
*/
