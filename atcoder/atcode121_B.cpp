#include <iostream>
using namespace std;

int main(){
    int n,m,c;
    int B[20] = {};
    const int MAX = 256;
    int A[MAX][20] = {};
    int sum = 0;
    int num = 0;

    cin >> n >> m >> c;

    for (int i = 0; i < m; i++) {
        cin >> B[i];
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++){
            cin >> A[i][j];
        }
    }

    for (int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            sum += A[i][j] * B[j];
        }
        sum += c;

        if ( sum > 0 ) num++;
        sum = 0;
    }

    cout << num << endl;
}
