#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int main(){
    priority_queue <pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > lines;
    int n;
    cin >> n;

    for(int i = 0; i < n; i++){
        int x, y;
        cin >> x >> y;
        lines.push(make_pair(x, y));
    }

    int start = lines.top().first;
    int end = lines.top().second;
    int longestLine = end - start + 1;
    lines.pop();

    while(!lines.empty()){
        int nextX = lines.top().first;
        int nextY = lines.top().second;

        if(end >= nextX){
            end = nextY;
        }
        else{
            longestLine = max(longestLine, end - start + 1);
            start = nextX;
            end = nextY;
        }
        lines.pop();
    }

    cout << longestLine << '\n';
    return 0;
}