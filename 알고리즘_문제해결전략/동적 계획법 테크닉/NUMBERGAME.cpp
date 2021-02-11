#include <iostream>
#include <algorithm>
using namespace std;
const int EMPTY = -987654321;
int value[50];
int cache[50][50];

int solution(int left, int right){
    if(left > right) return 0;
    int& res = cache[left][right];
    if(res != EMPTY) return res;

    res = max(value[left] - solution(left + 1, right), value[right] - solution(left, right - 1));

    if(right - left + 1 >= 2){
        res = max(res, -solution(left + 2, right));
        res = max(res, -solution(left, right - 2));
    }

    return res;
}

int main(){
    int c;
    cin >> c;

    while(c--){
        for(int i = 0; i < 50; i++){
            for(int j = 0; j < 50; j++)
                cache[i][j] = EMPTY;
        }

        int n;
        cin >> n;
        for(int i = 0; i < n; i++)
            cin >> value[i];
        cout << "답 -> \n";
        cout << solution(0, n - 1) << "!!!!!!\n";
    }
    return 0;
}