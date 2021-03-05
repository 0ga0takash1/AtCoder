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
#define repf(i, l, c, d) for (int64_t i = l; c; i+=d)
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

int64_t adjust_left(int64_t left) {
    if ( left%10000 ) {
        if ( left >= 0 ) {
            return (left/10000+1)*10000;
        } else {
            return (left/10000)*10000;
        }
    }
    return left;
}

int64_t adjust_right(int64_t right) {
    if ( right%10000 ) {
        if ( right >= 0 ) {
            return (right/10000)*10000;
        } else {
            return (right/10000-1)*10000;
        }
    }
    return right;
}

int64_t adjust_bottom(int64_t over_bottom) {
    if ( over_bottom%10000 ) {
        if ( over_bottom >= 0 ) {
            return (over_bottom/10000+1)*10000;
        } else {
            return (over_bottom/10000)*10000;
        }
    }
    return over_bottom;
}

/*
int64_t solve(int64_t x, int64_t y, int64_t r,
                int64_t l_r,
                int64_t over_bottom, int64_t under_top) {
    int64_t ans = 0;
    int64_t num_10000 = 10000;
    if ( l_r >= x ) {
        num_10000 *= -1;
        x += 10000;
    }

    int64_t cnt_over = 1, cnt_under = 1;
    int64_t xxx = l_r-x;
    repf(xx, l_r, xxx*(xx-x) >= 0, num_10000) {
        int64_t yy = over_bottom+(cnt_over-1)*10000;
        while( (xx-x)*(xx-x)+(y-yy)*(y-yy) <= r*r ) {
            ++cnt_over;
            yy += 10000;
        }
        --cnt_over;
        ans += cnt_over;
        if ( cnt_over < 1 ) cnt_over = 1;

        yy = under_top-(cnt_under-1)*10000;
        while( (xx-x)*(xx-x)+(y-yy)*(y-yy) <= r*r ) {
            ++cnt_under;
            yy -= 10000;
        }
        --cnt_under;
        if ( cnt_under < 1 ) cnt_under = 1;
        ans += cnt_under-1;
    }
    return ans;
}

int main() {
    int64_t x = in(), y = in(), r = in();

    int64_t left = adjust_left(x-r), right = adjust_right(x+r), over_bottom = adjust_bottom(y);
    int64_t under_top = over_bottom;

    int64_t ans = 0;
    if ( left == right ) {
        repc2(yy, (y-r)/10000*10000, y+r, 10000) {
            if ((left-x)*(left-x)+(y-yy)*(y-yy) <= r*r) {
                ++ans;
            }
        }
        cout << ans << endl;
        return 0;
    }

    ans += solve(x, y, r, left, over_bottom, under_top);
    ans += solve(x, y, r, right, over_bottom, under_top);
    cout << ans << endl;
    return 0;
}
*/

int main() {
    int64_t x = in(), y = in(), r = in();

    int64_t left = adjust_left(x-r), right = adjust_right(x+r), over_bottom = adjust_bottom(y);
    int64_t under_top = over_bottom;

    int64_t ans = 0;
    if ( left == right ) {
        repc2(yy, (y-r)/10000*10000, y+r, 10000) {
            if ((left-x)*(left-x)+(y-yy)*(y-yy) <= r*r) {
                ++ans;
            }
        }
        cout << ans << endl;
        return 0;
    }

    int64_t cnt_over = 1, cnt_under = 1;

    repc(xx, left, x, 10000) {
        int64_t yy = over_bottom+(cnt_over-1)*10000;
        while( (xx-x)*(xx-x)+(y-yy)*(y-yy) <= r*r ) {
            ++cnt_over;
            yy += 10000;
        }
        --cnt_over;
        ans += cnt_over;
        if ( cnt_over < 1 ) cnt_over = 1;

        yy = under_top-(cnt_under-1)*10000;
        while( (xx-x)*(xx-x)+(y-yy)*(y-yy) <= r*r ) {
            ++cnt_under;
            yy -= 10000;
        }
        --cnt_under;
        if ( cnt_under < 1 ) cnt_under = 1;
        ans += cnt_under-1;
    }

    cnt_over = 1, cnt_under = 1;
    for (int64_t xx = right; xx >= x; xx -= 10000) {
        int64_t yy = over_bottom+(cnt_over-1)*10000;
        while( (xx-x)*(xx-x)+(y-yy)*(y-yy) <= r*r ) {
            ++cnt_over;
            yy += 10000;
        }
        --cnt_over;
        ans += cnt_over;
        if ( cnt_over < 1 ) cnt_over = 1;

        yy = under_top-(cnt_under-1)*10000;
        while( (xx-x)*(xx-x)+(y-yy)*(y-yy) <= r*r ) {
            ++cnt_under;
            yy -= 10000;
        }
        --cnt_under;
        if ( cnt_under < 1 ) cnt_under = 1;
        ans += cnt_under-1;
    }
    cout << ans << endl;
    return 0;
}

/*
int64_t adjust_left(int64_t left) {
/
    if ( left%10000 ) {
        int64_t i = 0;
        if ( left >= 0 ) {
            while(1) {
                if ( i>left ) {
                    left = i;
                    break;
                }
                i += 10000;
            }
        } else {
            while(1) {
                if ( i<left ) {
                    left = i+10000;
                    break;
                }
                i -= 10000;
            }
        }
}*
    if ( left%10000 ) {
        if ( left >= 0 ) {
            return (left/10000+1)*10000;
        } else {
            return (left/10000)*10000;
        }
    }
    return left;
}

int64_t adjust_right(int64_t right) {
/*
    if ( right%10000 ) {
        int64_t i = 0;
        if ( right >= 0 ) {
            while(1) {
                if ( i>right ) {
                    right = i-10000;
                    break;
                }
                i += 10000;
            }
        } else {
            while(1) {
                if ( i<right ) {
                    right = i;
                    break;
                }
                i -= 10000;
            }
        }
    }
*
    if ( right%10000 ) {
        if ( right >= 0 ) {
            return (right/10000)*10000;
        } else {
            return (right/10000-1)*10000;
        }
    }
    return right;
}

int64_t adjust_bottom(int64_t over_bottom) {
/*
    if ( over_bottom%10000 ) {
        int64_t i = 0;
        if ( over_bottom >= 0 ) {
            while(1) {
                if ( i>over_bottom ) {
                    over_bottom = i;
                    break;
                }
                i += 10000;
            }
        } else {
            while(1) {
                if ( i<over_bottom ) {
                    over_bottom = i+10000;
                }
                i -= 10000;
            }
        }
    }
*
    if ( over_bottom%10000 ) {
        if ( over_bottom >= 0 ) {
            return (over_bottom/10000+1)*10000;
        } else {
            return (over_bottom/10000)*10000;
        }
    }
    return over_bottom;
}

int main() {
    int64_t x = in(), y = in(), r = in();

    int64_t left = adjust_left(x-r), right = adjust_right(x+r), over_bottom = adjust_bottom(y);
    int64_t under_top = over_bottom;
    // cout << "l r b t" << left/10000 << " " << right/10000 << " " << over_bottom/10000 << " " << under_top/10000 << endl;

    int64_t ans = 0;
    if ( left == right ) {
        repc2(yy, (y-r)/10000*10000, y+r, 10000) {
            if ((left-x)*(left-x)+(y-yy)*(y-yy) <= r*r) {
                ++ans;
            }
        }
        cout << ans << endl;
        return 0;
    }

    int64_t cnt_over = 1, cnt_under = 1;

    repc(xx, left, x, 10000) {
        int64_t sx = abs(xx-x);

        int64_t yy = over_bottom+(cnt_over-1)*10000;
        while( /*yy <= y+r &&* (xx-x)*(xx-x)+(y-yy)*(y-yy) <= r*r ) {
            ++cnt_over;
            yy += 10000;
        }
        --cnt_over;
        ans += cnt_over;
        if ( cnt_over < 1 ) cnt_over = 1;

        yy = under_top-(cnt_under-1)*10000;
        while( /*yy >= y-r &&* (xx-x)*(xx-x)+(y-yy)*(y-yy) <= r*r ) {
            ++cnt_under;
            yy -= 10000;
        }
        --cnt_under;
        if ( cnt_under < 1 ) cnt_under = 1;
        ans += cnt_under-1;
    }

    cnt_over = 1, cnt_under = 1;
    for (int64_t xx = right; xx >= x; xx -= 10000) {
        int64_t sx = abs(xx-x);

        int64_t yy = over_bottom+(cnt_over-1)*10000;
        while( /*yy <= y+r &&* (xx-x)*(xx-x)+(y-yy)*(y-yy) <= r*r ) {
            ++cnt_over;
            yy += 10000;
        }
        --cnt_over;
        ans += cnt_over;
        if ( cnt_over < 1 ) cnt_over = 1;

        yy = under_top-(cnt_under-1)*10000;
        while( /*yy >= y-r &&* (xx-x)*(xx-x)+(y-yy)*(y-yy) <= r*r ) {
            ++cnt_under;
            yy -= 10000;
        }
        --cnt_under;
        if ( cnt_under < 1 ) cnt_under = 1;
        ans += cnt_under-1;
    }

    // if ( y == 1 ) ans -= 2;

    cout << ans << endl;
    return 0;
}
*/
/*
int main() {
    int64_t x = in(), y = in(), r = in();

    int64_t left = adjust_left(x-r), right = adjust_right(x+r), over_bottom = adjust_bottom(y);
    int64_t under_top = over_bottom;
    // cout << "l r b t" << left/10000 << " " << right/10000 << " " << over_bottom/10000 << " " << under_top/10000 << endl;

    int64_t ans = 0;
    int64_t cnt_over = 1, cnt_under = 1;

    repc(xx, left, x, 10000) {
        // cout << "x: " << xx/10000 << endl;
        int64_t sx = abs(xx-x);

        int64_t yy = over_bottom+(cnt_over-1)*10000;
        /*
        while(1) {
            int64_t sy = abs(y-yy);
            if ( yy > y+r ) {
                if ( sx*sx+(sy-10000)*(sy-10000) <= r*r ) {
                    ans += cnt_over;
                }
                break;
            }

            if ( sx*sx+sy*sy > r*r ) {
                --cnt_over;
                ans += cnt_over;
                break;
            }
            ++cnt_over;
            yy += 10000;
        }

        yy = under_top-(cnt_under-1)*10000;
        while(1) {
            int64_t sy = abs(y-yy);
            if ( yy < y-r ) {
                if ( sx*sx+(sy+10000)*(sy+10000) <= r*r ) {
                    ans += cnt_under-1;
                }
                break;
            }

            if ( sx*sx+sy*sy > r*r ) {
                --cnt_under;
                ans += cnt_under-1;
                break;
            }
            ++cnt_under;
            yy -= 10000;
        }*
        while( yy <= y+r && (xx-x)*(xx-x)+(y-yy)*(y-yy) <= r*r ) {
            ++cnt_over;
            yy += 10000;
        }
        --cnt_over;
        ans += cnt_over;

        yy = under_top-(cnt_under-1)*10000;
        while( yy >= y-r && (xx-x)*(xx-x)+(y-yy)*(y-yy) <= r*r ) {
            ++cnt_under;
            yy -= 10000;
        }
        --cnt_under;
        ans += cnt_under-1;
    }

    cnt_over = 1, cnt_under = 1;
    for (int64_t xx = right; xx >= x; xx -= 10000) {
        // cout << "x2: " << xx/10000 << endl;
        int64_t sx = abs(xx-x);

        int64_t yy = over_bottom+(cnt_over-1)*10000;
        /*
        while(1) {
            int64_t sy = abs(y-yy);
            if ( yy > y+r ) {
                if ( sx*sx+(sy-10000)*(sy-10000) <= r*r ) {
                    ans += cnt_over;
                }
                break;
            }

            if ( sx*sx+sy*sy > r*r ) {
                --cnt_over;
                ans += cnt_over;
                break;
            }
            ++cnt_over;
            yy += 10000;
        }

        yy = under_top-(cnt_under-1)*10000;
        while(1) {
            int64_t sy = abs(y-yy);
            if ( yy < y-r ) {
                if ( sx*sx+(sy+10000)*(sy+10000) <= r*r ) {
                    ans += cnt_under-1;
                }
                break;
            }

            if ( sx*sx+sy*sy > r*r ) {
                --cnt_under;
                ans += cnt_under-1;
                break;
            }
            ++cnt_under;
            yy -= 10000;
        }*
        while( yy <= y+r && (xx-x)*(xx-x)+(y-yy)*(y-yy) <= r*r ) {
            ++cnt_over;
            yy += 10000;
        }
        --cnt_over;
        ans += cnt_over;

        yy = under_top-(cnt_under-1)*10000;
        while( yy >= y-r && (xx-x)*(xx-x)+(y-yy)*(y-yy) <= r*r ) {
            ++cnt_under;
            yy -= 10000;
        }
        --cnt_under;
        ans += cnt_under-1;
    }

    cout << ans << endl;
    return 0;
}
*/
