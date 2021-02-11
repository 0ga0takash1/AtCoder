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
#define repi(a, b) for (auto&(a) : (b))
#define ALL(v) (v).begin(), (v).end()
#define Sort(x) sort(ALL(x))
#define Sort_rev(x) Sort(x);reverse(ALL(x))
#define Sort_pair(x, p) sort(ALL(x), (p))
#define mp(a, b) make_pair((a), (b))
#define Push_back(a, b) push_back( mp( (a), (b) ) )
#define ctoi(c) (c)-'0'

template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1;  } return 0;  }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1;  } return 0;  }
template<typename V,typename T> bool find_num(V v, T num) { if ( find(ALL(v), num) == v.end() ) { return false; } return true; }

const int inf = 0x3fffffff;
const int64_t INF = 0x3fffffffffffffff;
const int64_t MOD = 1e9+7;

int64_t in() {
    double in;
    cin >> in;
    in *= 10000;
    return round(in);
}

int main() {
    int64_t x = in(), y = in(), r = in();

    // for (int64_t xx = (x-r)/10000; xx < x/10000; ++xx) {
    int64_t left = x-r, right = x+r;
    if ( left%10000 ) {
        int64_t i = 0;
        if ( x-r >= 0 ) {
            // repc2(i, 0, x-r, 10000) {
            while(1) {
                if ( i>left ) {
                    left = i;
                    break;
                }
                i += 10000;
            }
        } else {
            // for (int64_t i = 0; i >= x-r; i -= 10000) {
            while(1) {
                if ( i<left ) {
                    left = i+10000;
                    break;
                }
                i -= 10000;
            }
        }
    }
    if ( right%10000 ) {
        int64_t i = 0;
        if ( x+r >= 0 ) {
            // repc2(i, 0, x+r, 10000) {
            while(1) {
                if ( i>right ) {
                    right = i-10000;
                    break;
                }
                i += 10000;
            }
        } else {
            // for (int64_t i = 0; i >= x-r; i -= 10000) {
            while(1) {
                if ( i<right ) {
                    right = i;
                    break;
                }
                i -= 10000;
            }
        }
    }

    int64_t over_bottom = y;
    if ( over_bottom%10000 ) {
        int64_t i = 0;
        if ( over_bottom >= 0 ) {
            while(1) {
                if ( i>y ) {
                    over_bottom = i-10000;
                    break;
                }
                i += 10000;
            }
        } else {
            while(1) {
                if ( i<y ) {
                    over_bottom = i;
                }
                i -= 10000;
            }
        }
    }
    int64_t under_top = over_bottom-10000;
    // cout << "l r b t" << left << " " << right << " " << over_bottom << " " << under_top << endl;

    int64_t ans = 0;
    int64_t cnt_over = 0, cnt_under = 0;
    repc(xx, left, x, 10000) {
        int64_t sx = abs(xx-x);
        repc2(yy, over_bottom+cnt_over*10000, y+r, 10000) {
            int64_t sy = abs(y-yy);
            if ( sx*sx+sy*sy > r*r ) {
                ans += cnt_over;
                if ( over_bottom == y ) ++ans;
                continue;
            }
            // cout << "axx" << xx << " ayy" << yy << endl;
            ++cnt_over;
        }

        for (int64_t yy = under_top-cnt_under*10000; yy >= y-r; yy -= 10000) {
            int64_t sy = abs(y-yy);
            if ( sx*sx+sy*sy > r*r ) {
                ans += cnt_under;
                if ( over_bottom != y ) ++ans;
                continue;
            }
            // cout << "bxx" << xx << " byy" << yy << endl;
            ++cnt_under;
        }
    }
    // cout << "a" << ans << endl;

    cnt_over = 0, cnt_under = 0;
    for (int64_t xx = right; xx >= x; xx -= 10000) {
        int64_t sx = abs(xx-x);
        repc2(yy, over_bottom+cnt_over*10000, y+r, 10000) {
            int64_t sy = abs(y-yy);
            if ( sx*sx+sy*sy > r*r ) {
                ans += cnt_over;
                if ( over_bottom == y ) ++ans;
                continue;
            }
            // cout << "cxx" << xx << " cyy" << yy << endl;
            ++cnt_over;
        }

        for (int64_t yy = under_top-cnt_under*10000; yy >= y-r; yy -= 10000) {
            int64_t sy = abs(y-yy);
            if ( sx*sx+sy*sy > r*r ) {
                ans += cnt_under;
                if ( over_bottom != y ) ++ans;
                continue;
            }
            // cout << "dxx" << xx << " dyy" << yy << endl;
            ++cnt_under;
        }
    }

    /*
    repc(xx, (x-r)-(x-r)%1000, x, 10000) {
        int64_t sx = abs(xx-x);
        // for (int64_t yy = y/10000+cnt_over; yy <= (y+r)/10000; ++yy) {
        repc2(yy, (y+cnt_over*10000)-(y+cnt_over*10000)%1000, y+r, 10000) {
            int64_t sy = abs(y-yy);
            if ( sx*sx+sy*sy > r*r ) {
                ans += cnt_over;
                continue;
            }
            // if ( !xx%1000 && !yy%1000 ) {
                // cout << "axx" << xx << " ayy" << yy << endl;
                ++cnt_over;
            // }
        }

        for (int64_t yy = (y-cnt_under*10000)-(y-cnt_under*10000)%1000; yy >= y-r; yy -= 10000) {
            int64_t sy = abs(y-yy);
            if ( sx*sx+sy*sy > r*r ) {
                // ans += max(cnt_under-1, (int64_t)0);
                ans += cnt_under;
                continue;
            }
            // if ( !xx%1000 && !yy%1000 ) {
                // cout << "bxx" << xx << " byy" << yy << endl;
                ++cnt_under;
            // }
        }
    }
    // cout << "a" << ans << endl;

    cnt_over = 0, cnt_under = 1;
    for (int64_t xx = (x+r)-(x+r)%1000; xx >= x; xx -= 10000) {
        int64_t sx = abs(xx-x);
        // for (int64_t yy = y+cnt_over*10000; yy <= y+r; yy += 10000) {
        repc2(yy, (y+cnt_over*10000)-(y+cnt_over*10000)%1000, y+r, 10000) {
            int64_t sy = abs(y-yy);
            if ( sx*sx+sy*sy > r*r ) {
                ans += cnt_over;
                continue;
            }
            // if ( !xx%1000 && !yy%1000 ) {
                // cout << "cxx" << xx << " cyy" << yy << endl;
                ++cnt_over;
            // }
        }

        for (int64_t yy = (y-cnt_under*10000)-(y-cnt_under*10000)%1000; yy >= y-r; yy -= 10000) {
            int64_t sy = abs(y-yy);
            if ( sx*sx+sy*sy > r*r ) {
                // ans += max(cnt_under-1, (int64_t)0);
                ans += cnt_under;
                continue;
            }
            // if ( !xx%1000 && !yy%1000 ) {
                // cout << "dxx" << xx << " dyy" << yy << endl;
                ++cnt_under;
            // }
        }
    }
    */
    cout << ans << endl;
    return 0;
}

/*
int main() {
    int64_t x = in(), y = in(), r = in();
    // x %= 10000;y %= 10000;r %= 10000;

    int64_t ans = 0;
    int64_t cnt_over = 0, cnt_under = 0;
    // repb(xx, x-r, x) {
    for (int64_t xx = (x-r)/10000; xx < x/10000; ++xx) {
        int64_t sx = abs(xx*10000-x);
        // repb2(yy, y+cnt_over, y+r) {
        for (int64_t yy = y/10000+cnt_over; yy <= (y+r)/10000; ++yy) {
            int64_t sy = abs(y-yy*10000);
            if ( sx*sx+sy*sy > r*r ) {
                ans += cnt_over;
                continue;
            }
            ++cnt_over;
        }

        for (int64_t yy = y/10000-cnt_under; yy >= (y-r)/10000; --yy) {
            int64_t sy = abs(y-yy);
            if ( sx*sx+sy*sy > r*r ) {
                ans += max(cnt_under-1, (int64_t)0);
                continue;
            }
            ++cnt_under;
        }
    }

    cnt_over = 0, cnt_under = 0;
    for (int64_t xx = (x+r)/10000; xx >= x/10000; --xx) {
        int64_t sx = abs(xx-x);
        // repb2(yy, y+cnt_over, y+r) {
        for (int64_t yy = y/10000+cnt_over; yy <= (y+r)/10000; ++yy) {
            int64_t sy = abs(y-yy);
            if ( sx*sx+sy*sy > r*r ) {
                ans += cnt_over;
                continue;
            }
            ++cnt_over;
        }

        for (int64_t yy = y/10000-cnt_under; yy >= (y-r)/10000; --yy) {
            int64_t sy = abs(y-yy);
            if ( sx*sx+sy*sy > r*r ) {
                ans += max(cnt_under-1, (int64_t)0);
                continue;
            }
            ++cnt_under;
        }
    }
    cout << ans << endl;
    return 0;
}
*/
/*
int main() {
    double x, y, r;
    cin >> x >> y >> r;
    x *= 10000;y *= 10000;r *= 10000;
    int64_t ans = 0;
    int64_t cnt_over = 0, cnt_under = 0;
    repb(xx, x-r, x) {
        double sx = abs(xx-x);
        repb2(yy, y+cnt_over, y+r) {
            double sy = abs(y-yy);
            if ( sx*sx+sy*sy > r*r ) {
                ans += cnt_over;
                break;
            }
            ++cnt_over;
        }

        for (int64_t yy = y-cnt_under; yy >= y-r; --yy) {
            double sy = abs(y-yy);
            if ( sx*sx+sy*sy > r*r ) {
                ans += cnt_under-1;
                break;
            }
            ++cnt_under;
        }
    }

    cnt_over = 0, cnt_under = 0;
    for (int64_t xx = x+r; xx >= x; --xx) {
        double sx = abs(xx-x);
        repb2(yy, y+cnt_over, y+r) {
            double sy = abs(y-yy);
            if ( sx*sx+sy*sy > r*r ) {
                ans += cnt_over;
                break;
            }
            ++cnt_over;
        }

        for (int64_t yy = y-cnt_under; yy >= y-r; --yy) {
            double sy = abs(y-yy);
            if ( sx*sx+sy*sy > r*r ) {
                ans += cnt_under-1;
                break;
            }
            ++cnt_under;
        }
    }
    cout << ans << endl;
    return 0;
}
*/

/*
int main() {
    double x, y, r;
    cin >> x >> y >> r;
    int64_t ans = 0;
    repb2(xx, x-r, x+r) {
        double sx = abs(xx-x);

        int64_t left = y-r, right = y+r;
        // repb2(yy, left, y+r) {
        while (1) {
            double sy = abs(y-left);
            if ( sx*sx+sy*sy <= r*r ) {
                break;
            }
            ++left;
        }
        while (1) {
            double sy = abs(right-y);
            if ( sx*sx+sy*sy <= r*r ) {
                break;
            }
            --right;
        }
        ans += right-left+1;
        /*
        repb2(yy, y-r, y+r) {
            double sx = abs(xx-x), sy = abs(yy-y);
            if ( sx*sx+sy*sy <= r*r ) {
                // cout << "a" << xx << " " << yy << endl;
                ++ans;
            }
        }

    }
    cout << ans << endl;
    return 0;
}
*/
