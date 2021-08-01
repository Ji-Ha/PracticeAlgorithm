#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;
int times[10][10];
int routes[10][10];
int memo[10];

void dfs(){
    
}

int solution(int n, int start, int end, vector<vector<int> > roads, vector<int> traps){
    for(int i = 0; i < 10; i++){
        for(int j = 0; j < 10; j++)
            routes[i][j] = - 1;
    }
    int answer = 0;
    bool flag = true;

    for(int i = 0; i < roads.size(); i++){
        routes[roads[i][0]][roads[i][1]] = 1;
        routes[roads[i][1]][roads[i][0]] = 0;
        times[roads[i][0]][roads[i][1]] = roads[i][2];
        times[roads[i][1]][roads[i][0]] = roads[i][2];
    }

    queue<int> q;
    q.push(start);

    while(!q.empty()){
        int target = q.front();
        q.pop();
        if(target == end) return answer;
        //traps에 target이 존재하면, flag 변경.
        for(int i = 0; i < 10; i++){
            if(routes[target][i] == flag){
                q.push(i);
            }
        }
    }
    return answer;
}

int main(){

    return 0;
}