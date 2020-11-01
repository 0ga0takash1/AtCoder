#include <bits/stdc++.h>
#include <string>
using namespace std;

typedef long long ll;
typedef int64_t i6;
typedef std::vector<std::vector<int64_t> > Graph;

#define rep(i, n) for (int64_t i = 0; i < n; ++i)
#define rep2(i, n) for (int64_t i = 1; i <= n; ++i)
#define repb(i, l, n) for (int64_t i = l; i < n; ++i)
#define repb2(i, l, n) for (int64_t i = l; i <= n; ++i)
#define repe(a, b) for (auto&(a) : (b))
#define ALL(v) (v).begin(), (v).end()
#define Sort(x) sort(ALL(x))
#define Sort_rev(x) Sort(x);reverse(ALL(x))
#define mp(a, b) make_pair((a), (b))
#define Push_back(a, b) push_back( mp( (a), (b) ) )

template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1;  } return 0;  }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1;  } return 0;  }
template<typename V,typename T> bool find_num(V v, T num) { if ( find(ALL(v), num) == v.end() ) { return false; } return true; }

const int inf = 0x3fffffff;
const int64_t INF = 0x3fffffffffffffff;
const int64_t MOD = 1e9+7;

int main() {
    string s;
    cin >> s;

    int64_t n = s.length();
    if ( n == 1 ) {
        if ( (s[0]-'0')%8 == 0 ) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
        return 0;
    } else if ( n == 2 ) {
        // int64_t num = atoi(s.c_str());
        int64_t num = stoi(s);
        if ( num%8 == 0 ) {
            cout << "Yes" << endl;
        } else {
            // s = to_string(s[1]);
            // s.append(to_string(s[0]));
            reverse(ALL(s));
            // num = atoi(s.c_str());
            num = stoi(s);
            if ( num%8 == 0 ) {
                cout << "Yes" << endl;
            } else {
                cout << "No" << endl;
            }
        }
        return 0;
    } else {
        std::vector<int64_t> v(10, 0);
        rep(i, n) ++v[s[i]-'0'];

        rep2(i, 9) {
            rep2(j, 9) {
                // rep2(k, 9) {
                for (int64_t k = 2; k <= 8; k += 2) {
                    std::vector<int64_t> v2 = v;
                    if ( v2[i] <= 0 ) continue;
                    --v2[i];
                    if ( v2[j] <= 0 ) continue;
                    --v2[j];
                    if ( v2[k] <= 0 ) continue;
                    int64_t num = 100*i+10*j+k;
                    // cout << "num " << num << endl;
                    if ( num%8 == 0 ) {
                        cout << "Yes" << endl;
                        return 0;
                    }
                }
            }
        }
        cout << "No" << endl;
    }
    /*
    rep(i, n-2) {
        repb(j, i+1, n-1) {
            int64_t num, flag = 0;
            string s2 = "ABC";
            repb(k, j+1, n) {
                // string s2 = s[i]+s[j]+s[k];
                /*
                string s2 = to_string(s[i]);
                s2.append(to_string(s[j]));
                s2.append(to_string(s[k]));

                s2[0] = s[i];
                s2[1] = s[j];
                s2[2] = s[k];
                // num = stoi(s2);
                num = atoi(s2.c_str());
                if ( num%2 == 0 && ((num/2)%100)%4 == 0 ) {
                    flag = 1;
                    break;
                }

                // s2 = s[i]+s[k]+s[j];
                /*
                s2 = to_string(s[i]);
                s2.append(to_string(s[k]));
                s2.append(to_string(s[j]));

                s2[0] = s[i];
                s2[1] = s[k];
                s2[2] = s[j];
                // num = stoi(s2);
                num = atoi(s2.c_str());
                if ( num%2 == 0 && ((num/2)%100)%4 == 0 ) {
                    flag = 1;
                    break;
                }

                // s2 = s[j]+s[i]+s[k];
                /*
                s2 = to_string(s[j]);
                s2.append(to_string(s[i]));
                s2.append(to_string(s[k]));
                s2[0] = s[j];
                s2[1] = s[i];
                s2[2] = s[k];
                // num = stoi(s2);
                num = atoi(s2.c_str());
                if ( num%2 == 0 && ((num/2)%100)%4 == 0 ) {
                    flag = 1;
                    break;
                }

                // s2 = s[j]+s[k]+s[i];
                /*
                s2 = to_string(s[j]);
                s2.append(to_string(s[k]));
                s2.append(to_string(s[i]));
                s2[0] = s[j];
                s2[1] = s[k];
                s2[2] = s[i];
                // num = stoi(s2);
                num = atoi(s2.c_str());
                if ( num%2 == 0 && ((num/2)%100)%4 == 0 ) {
                    flag = 1;
                    break;
                }

                // s2 = s[k]+s[i]+s[j];
                /*
                s2 = to_string(s[k]);
                s2.append(to_string(s[i]));
                s2.append(to_string(s[j]));
                s2[0] = s[k];
                s2[1] = s[i];
                s2[2] = s[j];
                // num = stoi(s2);
                num = atoi(s2.c_str());
                if ( num%2 == 0 && ((num/2)%100)%4 == 0 ) {
                    flag = 1;
                    break;
                }

                // s2 = s[k]+s[j]+s[i];
                /*
                s2 = to_string(s[k]);
                s2.append(to_string(s[j]));
                s2.append(to_string(s[i]));
                s2[0] = s[k];
                s2[1] = s[j];
                s2[2] = s[i];
                // num = stoi(s2);
                num = atoi(s2.c_str());
                if ( num%2 == 0 && ((num/2)%100)%4 == 0 ) {
                    flag = 1;
                    break;
                }
            }

            if (flag) {
                cout << "Yes" << endl;
                return 0;
            }
        }
    }
    cout << "No" << endl;
    */
    return 0;
}
