#include <bits/stdc++.h>
using namespace std;

#define Sort(x) sort(x.begin(), x.end())
#define Sort_rev(x) sort(x.begin(), x.end(), greater<int>())

long long gcd(long long a, long long b)
{
/*
	while(b != 0){
    	a %= b;
    	swap(a,b);
	}
	return a;
*/
	if (a%b==0) {
		return(b);
	} else {
		return(gcd(b,a%b));
	}
}

int main() {
    long long a, b;
    cin >> a >> b;
	long long ans = 1;
	long long c = gcd(a, b);
/*
    for (int i = 1; i <= gcd(a, b); ++i) {
        if ( a%i == 0 && b%i == 0 ) {
			if ( IsPrime(i)) {
	            ans++;
	        }
        }
    }
*/
	for (long long i = 2; i*i <= c; ++i) {
		if ( c%i == 0 ) {
			ans++;
			while ( c%i == 0 ) {
				c /= i;
			}
		}
	}

	if ( c != 1 ) {
		ans++;
	}
    cout << ans << endl;
    return 0;
}
