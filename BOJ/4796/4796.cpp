#include <iostream>

using namespace std;

int main(){
    int L, P, V;
    int testCase = 0;

    while(1){
        testCase++;
        cin >> L >> P >> V;
        if(L == 0 && P == 0 && V == 0) break;

        int res = 0;

        if(L != 0)
            res = ((V / P) * L) + ((V % P) < L ? (V % P) : L);

        cout << "Case " << testCase << ": " << res << '\n';
    }
    return 0;
}