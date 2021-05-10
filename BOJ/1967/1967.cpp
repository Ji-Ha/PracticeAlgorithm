#include <iostream>
#include <vector>
#include <memory.h>
using namespace std;

int visited[10001] = {0};
vector<pair<int, int> > node[10001];

int ans = 0;
int end_point = 0;
void dfs(int start, int length){
    if(visited[start]) return;

    visited[start] = 1;

    if(ans < length){
        ans = length;
        end_point = start;
    }

    for(int i = 0; i < node[start].size(); i++){
        dfs(node[start][i].first, length + node[start][i].second);
    }
}

int main(){
    int n;
    cin >> n;

    int parent, child, weight;
    for(int i = 0; i < n - 1; i++){
        cin >> parent >> child >> weight;

        node[parent].push_back(make_pair(child, weight));
        node[child].push_back(make_pair(parent, weight));
    }

    dfs(1, 0);

    ans = 0;
    memset(visited, 0, sizeof(visited));

    dfs(end_point, 0);
    cout << ans << '\n';
    return 0;
}