#include <iostream>
#include <vector>
using namespace std;
int citizen[10001];
vector<int> city[10001];
bool check[10001];

int dfs(int cur, bool flag){
    int ans = 0;
    check[cur] = true;

    for(int i = 0; i < city[cur].size(); i++){
        int next = city[cur][i];
        if(check[next]) continue;

        if(flag) ans += dfs(next, false);
        else ans += max(dfs(next, false), dfs(next, true) + citizen[next]);
    }

    check[cur] = false;
    return ans;
}

int main(){
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

    cout << max(dfs(1, 0), dfs(1, 1) + citizen[1]) << '\n';
    return 0;
}