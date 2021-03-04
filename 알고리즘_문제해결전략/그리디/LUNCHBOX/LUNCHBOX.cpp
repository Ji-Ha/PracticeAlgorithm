#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int C, N;
int E[10000], M[10000];

int solution(){
    vector<pair<int,int> > order;

    for(int i = 0; i < N; i++)
        order.push_back(make_pair(-E[i], i));
    sort(order.begin(), order.end());

    int ret = 0, beginEat = 0;
    for(int i = 0; i < N; i++){
        int box = order[i].second;
        beginEat += M[box];
        ret = max(ret, beginEat + E[box]);
    }
    return ret;
}

int main(){
    cin >> C;

    while(C--){
        cin >> N;
        for(int i = 0; i < N; i++)
            cin >> M[i];
        for(int i = 0; i < N; i++)
            cin >> E[i];

        cout << solution() << '\n';
    }
    return 0;
}