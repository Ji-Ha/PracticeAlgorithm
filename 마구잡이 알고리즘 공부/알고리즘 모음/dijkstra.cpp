#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#define LIM numeric_limits(int)::max()
//Dijkstra algorithm
//'음의 가중치가 없는' 그래프여야만 함.
//한 노드에서 다른 모든 노드까지의 최단거리를 구하는 알고리즘.
//우선순위 큐(위치, 거리)를 이용한다면 
//elogn만큼의 시간 복잡도를 가진다.(e == 간선의 수, n == 정점의 수)

vector<pair<int, int>> adj[100];
void Dijkstra(int start, vector<int>& dist){
    priority_queue<pair<int, int>> p;
    p.push(make_pair(0, start));
    
    //큐에 데이터가 없을때까지 돈다.
    while(!p.empty()){
        //우선순위 큐이기 때문에,
        //뭐가 제일 작은 노드인지 찾을 필요없이,
        //제일 앞에있는 걸 고르면 됨.
        int cost = -p.top().first;
        int from = p.top().second;
        p.pop();
        
        if(dist[from] < cost) continue;
        
        for(int i = 0; i<adj[from].size();i++){
            int to = adj[from][i].first;
            int distFrom = cost + adj[from][i].second;
            if(distFrom < dist[to]){
                dist[to] = distFrom;
                q.push(make_pair(-distFrom, to));
            }
        }
    }
}