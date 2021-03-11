#include <iostream>
using namespace std;
int parent[1000001];

int find(int a){
    if(a == parent[a]) return a;
    return parent[a] = find(parent[a]);
}

void uni(int a, int b){
    int aCheck = find(a);
    int bCheck = find(b);

    if(aCheck > bCheck) parent[aCheck] = bCheck;
    if(aCheck < bCheck) parent[bCheck] = aCheck;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;

    for(int i = 0; i <= n; i++) parent[i] = i;

    while(m--){
        int func;
        int a, b;
        cin >> func >> a >> b;

        if(func == 0){
            uni(a, b);
        }

        if(func == 1){
            if(find(a) == find(b)) cout << "YES" << '\n';
            else cout << "NO" << '\n';
        }
    }
    return 0;
}