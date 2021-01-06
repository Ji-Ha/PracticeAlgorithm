#include <string>
#include <vector>
#include <algorithm>
//처음엔 다익스트라로 풀어보려했지만,
//bfs로 푸는게 쉽기도하고, 시간도 짧다는걸 깨달음.
//쉽지않아서 참고하여 풀었음.
using namespace std;
vector <int> dist;

void bfs(int target, vector<vector<int>>& value, vector<int> q){
    vector <int> nq;
    while(!q.empty()){
        int num = q.front();
        q.erase(q.begin());
        for(int i = 2; i<value.size();i++){
            if(value[num][i] == 1 && dist[i] == 0){
                dist[i] = target;
                nq.push_back(i);
            }
        }
    }
    if(!nq.empty())
        bfs(target+1, value, nq);
}

int solution(int n, vector<vector<int>> edge) {
    int answer = 0;
    dist.resize(n+1);
    vector<vector<int>> value(n+1, vector<int>( n+1));
    fill(dist.begin(), dist.end(), 0);
    
    //쌍방향 저장.
    for(int i = 0; i<edge.size();i++){
        value[edge[i][0]][edge[i][1]] = 1;
        value[edge[i][1]][edge[i][0]] = 1;
    }
    
    
    bfs(1, value,  {1} );
    int m = *max_element(dist.begin(), dist.end());
    for(int i = 1 ; i < dist.size();i++){
        if(dist[i] == m)
            answer++;
    }
    return answer;
}