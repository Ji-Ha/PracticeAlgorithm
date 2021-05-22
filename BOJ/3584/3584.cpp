#include <iostream>
#include <vector>
#include <queue>
#include <memory.h>
using namespace std;
int parent[10001];
int depth[10001];
bool check[10001];

int Fparent(int first, int second){
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
    int t;
    cin >> t;

    while(t--){
        memset(parent, 0, sizeof(parent));
        memset(depth, 0, sizeof(depth));
        memset(check, false, sizeof(check));
        vector<int> tree[10001];
        queue<int> q;
        int n, a, b, r;
        cin >> n;

        for(int i = 0; i < n - 1; i++){
            cin >> a >> b;
            if(i == 0) r = a;
            tree[a].push_back(b);
            tree[b].push_back(a);
        }

        q.push(r);
        check[r] = true;
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
        int c, d;
        cin >> c >> d;
        cout << Fparent(c, d) << "\n";
    }
    return 0;
}