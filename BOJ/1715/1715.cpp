#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int main(){
    int N;
    int res = 0;
    cin >> N;

    priority_queue <int, vector<int>, greater<int> > data;

    for(int i = 0; i < N; i++){
        int input;
        cin >> input;
        data.push(input);
    }

    while(data.size() > 1){
        int first = data.top();
        data.pop();
        int second = data.top();
        data.pop();
        res += first + second;
        data.push(first + second);
    }

    cout << res << '\n';
    return 0;
}