#include <bits/stdc++.h>
#include <algorithm>
using namespace std;

#define SIZE_OF_ARRAY(array) (sizeof(array)/sizeof(array[0]))

int main(){
    int ans = 0;
    int n,m;
    long unsigned int a_size = 1000000000;
    long unsigned int c_size = 1000000000;
    int A[a_size],B[100000],C[c_size];
    cin >> n >> m;
    for (int i = 0; i < n; i++){
        cin >> A[i];
    }
    sort(A, A + SIZE_OF_ARRAY(A));

    for (int i = 0;i < m; i++){
        cin >> B[i] >> C[i];
    }

    for (int i = 0; i < m; i++){
        for (int j = 0; j < B[i]; j++){
            if ( A[j] < C[i]){
                A[j] = C[i];
            }
        }
    }

    for (int i = 0; i < n; i++){
        ans += A[i];
    }

    cout << ans << endl;
}
