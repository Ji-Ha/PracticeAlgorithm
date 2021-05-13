#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> tree[50001];
queue<int> q;
bool check[50001];
int depth[50001];
int parent[50001];

int LCA(int first, int second){
    if(depth[first] > depth[second]) swap(first, second);

    while(depth[second] != depth[first])
        second = parent[second];
    
    while(first != second){
        first = parent[first];
        second = parent[second];
    }
    return first;
}

int main(){
    int n, m;
    int u, v;
    cin >> n;

    for(int i = 0; i < n - 1; i++){       
        cin >> u >> v;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }

    check[1] = true;
    q.push(1);
    while(!q.empty()){
        int root = q.front();
        q.pop();
        for(int i = 0; i < tree[root].size(); i++){
            int target = tree[root][i];
            if(!check[target]){
                depth[target] = depth[root] + 1;
                check[target] = true;
                parent[target] = root;
                q.push(target);
            }
        }
    }

    cin >> m;
    for(int i = 0; i < m; i++){
        cin >> u >> v;
        cout << LCA(u, v) << '\n';
    }
    return 0;
}