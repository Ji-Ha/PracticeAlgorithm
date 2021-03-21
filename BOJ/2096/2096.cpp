#include <iostream>
#include <memory.h>
#include <algorithm>
using namespace std;
int n;
int value[3];
int maxValue[2][3], minValue[2][3];

int main(){
    cin >> n;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < 3; j++) cin >> value[j];
        if(i == 0){
            for(int t = 0; t < 3; t++) maxValue[1][t] = minValue[1][t] = value[t];
        }
        else{
            maxValue[1][0] = max(maxValue[0][0], maxValue[0][1]) + value[0];
            maxValue[1][1] = max(max(maxValue[0][0], maxValue[0][1]), maxValue[0][2]) + value[1];
            maxValue[1][2] = max(maxValue[0][1], maxValue[0][2]) + value[2];

            minValue[1][0] = min(minValue[0][0], minValue[0][1]) + value[0];
            minValue[1][1] = min(min(minValue[0][0], minValue[0][1]), minValue[0][2]) + value[1];
            minValue[1][2] = min(minValue[0][1], minValue[0][2]) + value[2];
        }
        for(int t = 0; t < 3; t++){
            maxValue[0][t] = maxValue[1][t];
            minValue[0][t] = minValue[1][t];
        }
    }
    int ansMax = max(max(maxValue[0][0], maxValue[0][1]), maxValue[0][2]);
    int ansMin = min(min(minValue[0][0], minValue[0][1]), minValue[0][2]);


    cout << ansMax << ' ' << ansMin << '\n';
    return 0;
}