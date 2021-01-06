#include <vector>
#include <algorithm>

using namespace std;

vector<int> node;

int getParent(int a){
    if(node[a] == a) return a;
    return node[a] = getParent(node[a]);
}

void unionParent(int a, int b){
    a = getParent(a);
    b = getParent(b);
    if(a<b) node[b] = a;
    else node[a] = b;
}

int find(int a, int b){
    a = getParent(a);
    b = getParent(b);
    if(a==b) return 1;
    return 0;
}

bool com(vector<int> a, vector<int> b){
    return a[2] < b[2];
}

//크루스칼 알고리즘.
int solution(int n, vector<vector<int>> costs) {
    int answer = 0;
    sort(costs.begin(), costs.end(), com);
    
    for(int i = 0 ; i<n;i++)
        node.push_back(i);
    
    for(int i = 0; i<costs.size();i++){
        if(!find(costs[i][0], costs[i][1])){
            answer += costs[i][2];
            unionParent(costs[i][0], costs[i][1]);
        }
    }
    return answer;
}