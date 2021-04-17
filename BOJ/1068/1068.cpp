#include <iostream>
#include <vector>
#include <queue>

using namespace std;
vector<int> node[51];
bool check[51];
int target;
int answer = 0;
int n, root;

void bfs(){
    queue<int> q;
    q.push(root);
    if(root == target) return ;

    while(!q.empty()){
        int x = q.front();
        q.pop();
        if(node[x].empty()) answer++;

        for(int i = 0; i < node[x].size(); i++){
            if(node[x][i] == target){
                if(node[x].size() == 1) answer++;
                continue;
            }
            if(!check[node[x][i]]){
                q.push(node[x][i]);
                check[node[x][i]] = true;
            }
        }
    }
}

int main(){
    cin >> n;
    for(int i = 0; i < n; i++){
        int temp;
        cin >> temp;
        if(temp == -1) root = i;
        else node[temp].push_back(i);
    }

    cin >> target;
    node[target].clear();
    bfs();

    cout << answer << '\n';
    return 0;
}