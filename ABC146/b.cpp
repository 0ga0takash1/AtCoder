#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef int64_t i6;

#define rep(i, n) for (ll i = 0; i < n; ++i)
#define Sort(x) sort(x.begin(), x.end())
#define Sort_rev(x) sort(x.begin(), x.end(), greater<int>())
#define ALL(v) (v).begin(), (v).end()

//π M_PI
//deg = rad*180/M_PI

char shift_char(int shift_count, char char_in)
{
    string str = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

	int i, j;
	int num;
	for (i = 0; i < 27; i++){
		if (char_in == str[i]) {
            //num = i;
            break;
        }
	}
	//if (i >= 26) return char_in; /* この行を追加する */

	j = (i + shift_count) % 26;
/*
	if (j < 0) {
		j += 26;
	}
*/
	return str[j];
}

int main() {
    int n;
    string s;
    cin >> n >> s;
    //std::vector<string> v;
    rep(i, s.length()) {
        //v.push_back(shift_char(n, s[i]));
        //cout << v[i];
        char ss = shift_char(n, s[i]);
        cout << ss;
    }
    cout << endl;
    //cout << v << endl;
    return 0;
}
