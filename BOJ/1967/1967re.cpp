#include <iostream>
#include <vector>
#include <memory.h>
using namespace std;

vector<pair<int, int> > tree[10001];
bool visited[10001];
int ans = 0;
int end_point = 0;

void dfs(int start, int length){
    if(visited[start]) return;
    visited[start] = true;

    if(ans < length){
        ans = length;
        end_point = start;
    }

    for(int i = 0; i < tree[start].size(); i++){
        dfs(tree[start][i].first, tree[start][i].second + length);
    }
}
int main(){
    int n;
    cin >> n;
    
    int parent, child, weight;
    for(int i = 0; i < n - 1; i++){
        cin >> parent >> child >> weight;
        tree[parent].push_back(make_pair(child, weight));
        tree[child].push_back(make_pair(parent, weight));
    }

    dfs(1, 0);
    ans = 0;
    memset(visited, false, sizeof(visited));
    dfs(end_point, 0);

    cout << ans;
    return 0;
}