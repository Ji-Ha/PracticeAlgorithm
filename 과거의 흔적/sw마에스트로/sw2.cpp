#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> pc[1000];
int result[1000];

int main(){
    int p, n, h;

    cin >> p >> n >> h;

    for(int i = 0; i < n; i++){
        int pcNumber, usingHour;
        cin >> pcNumber >> usingHour;
        if(usingHour <= h) pc[pcNumber].push_back(usingHour);
    }
    for(int i = 0; i < p; i++){
        for(int j = 0; j < pc[i].size(); j++){
            cout << pc[i][j] << "!!!!!!\n";
        }
    }
    for(int i = 1; i <= p; i++){
        sort(pc[i].begin(), pc[i].end(), greater<int>());
        int sum = 0;
        for(int j = 0; j < pc[i].size(); i++){
            if(sum == h) break;
            if(sum + pc[i][j] <= h) sum += pc[i][j];
        }
        cout << i << ' ' << sum * 1000 << '\n';
    }
    return 0;
}