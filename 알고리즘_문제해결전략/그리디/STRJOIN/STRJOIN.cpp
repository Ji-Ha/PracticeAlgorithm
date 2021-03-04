#include <iostream>
#include <queue>
using namespace std;

int solution(priority_queue<int, vector<int>, greater<int> > data){
    int res = 0;
    while(data.size() > 1){
        int first = data.top();
        data.pop();
        int second = data.top();
        data.pop();
        int plus = first + second;
        res += plus;
        data.push(plus);
    }
    return res;
}

int main(){
    int c;
    cin >> c;

    while(c--){
        int n;
        cin >> n;

        priority_queue <int, vector<int>, greater<int> > data;
        for(int i = 0; i < n; i++){
            int temp;
            cin >> temp;
            data.push(temp);
        }

        cout << solution(data) << '\n';
    }
    return 0;
}