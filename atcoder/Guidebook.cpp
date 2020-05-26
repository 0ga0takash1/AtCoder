#include <bits/stdc++.h>
using namespace std;

void foo(const char* String) {
    std::vector<char*> vec;
    for (int i = 0; String[i] != '\0';) {
        int len = mblen(&String[i], MB_CUR_MAX);
        char* buf = new char[len+1];
        buf[len] = 0;
        memcpy(buf, &String[i], len);
        vec.push_back(buf);
        i+=len;
    }
}

int main(){
    int n,P[100];
    int num[100];
    int num_temp,store_temp;
    cin >> n;
    char* S[100],temp;
    vector<const char*> vec_S;
    for (int i = 0; i < n; i++){
        cin >> *S[i] >> P[i];
        num[i] = i;
    }
    for (int i = 0; i < n; i++){
        foo(S[i]);
    }
    /*
    for(int i = 1; i < n; i++){
        for(int j = 1; j < n; j++){
            if( strcmp(S[j-1], S[j]) > 0){
                strcpy(tmp, S[j-1]);
                strcpy(S[j-1], S[j]);
                strcpy(S[j], tmp);

                num_temp = P[j-1];
                P[j-1] = P[j];
                P[j] = num_temp;

                store_temp = num[j-1];
                num[j-1] = num[j];
                num[j] = store_temp;
            }
        }
    }
*/
    sort(vec_S.begin(), vec_S.end(), [](const char *strA, const char *strB) {
        return std::strcmp(strA, strB) < 0;
    });
    for(int i = 1; i < n; i++){
        if ( strcmp(vec_S[i-1], vec_S[i]) == 0 ){
            if ( P[i-1] < P[i] ) {
                num_temp = P[i-1];
                P[i-1] = P[i];
                P[i] = num_temp;

                store_temp = num[i-1];
                num[i-1] = num[i];
                num[i] = store_temp;
            }
        }
    }
    for (int i = 0; i < n; i++){
        cout << num[i] << endl;
    }
}
