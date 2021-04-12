#include <iostream>
#include <vector>
#include <queue>
#include <memory.h>
#include <algorithm>
using namespace std;
vector<int> comp[101];
bool check[101];

int bfs(int start){
    queue<int> q;
    int count = 0;
    memset(check, false, sizeof(check));
    check[start] = true;
    q.push(start);

    while(!q.empty()){
        int node = q.front();
        q.pop();
        for(int i = 0; i < comp[node].size(); i++){
            int next = comp[node][i];
            if(!check[next]){
                count++;
                check[next] = true;
                q.push(next);
            }
        }
    }
    return count;
}

int main(){
    int c;
    int pair;
    cin >> c;
    cin >> pair;

    while(pair--){
        int a, b;
        cin >> a >> b;
        comp[a].push_back(b);
        comp[b].push_back(a);
    }

    for(int i = 0; i < c; i++)
        sort(comp[i].begin(), comp[i].end());

    cout << bfs(1);
    return 0;
}