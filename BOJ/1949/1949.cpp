#include <iostream>
#include <vector>
#include <memory.h>
using namespace std;
int citizen[10001];
vector<int> city[10001];
vector<int> tree[10001];
int cache[10001][2];
bool check[10001];

int usu(int cur, bool flag){
    int &res = cache[cur][flag];
    if(res != -1) return res;
    res = 0;

    for(int i = 0; i < tree[cur].size(); i++){
        int next = tree[cur][i];
        int first = usu(next, false);
        int second = -1;

        if(!flag) second = usu(next, true);
        
        res += max(first, second);
    }
    if(flag) res += citizen[cur];

    return res;
}

void makeTree(int index){
    for(int i = 0; i < city[index].size(); i++){
        int next = city[index][i];
        if(!check[next]){
            tree[index].push_back(next);
            check[next] = true;

            makeTree(next);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, c;
    int u, v;
    cin >> n;

    for(int i = 1; i <= n; i++){
        cin >> c;
        citizen[i] = c;
    }

    for(int i = 0; i < n - 1; i++){
        cin >> u >> v;
        city[u].push_back(v);
        city[v].push_back(u);
    }

    int root = 1;
    check[root] = true;
    makeTree(root);
    memset(cache, -1, sizeof(cache));

    cout << max(usu(1, true), usu(1, false)) << '\n';
    return 0;
}