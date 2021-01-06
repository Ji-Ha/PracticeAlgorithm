#include <vector>
//프로그래머스 네트워크

using namespace std;

//조건을 main에도 연결해야하기 때문에 포인터로 받으셈.
bool dfs(int i, vector<vector<int>>& computers){
    //0이면 돌은거잖아. false
    if(computers[i][i] == 0) return false;
    //0 아니면, 처음 들어온 노드를 다음 노드들이 못쓰게 0으로 초기화.
    computers[i][i] = 0;
    //들어온 노드에서 연결된 모든 노드 또 끄집어 내기.
    for(int j = 0; j<computers.size();j++){
        //재귀로 끄집어 냄.
        if(computers[i][j] == 1)
            dfs(j, computers);
    }
    //다 돌았으면 true
    return true;
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    
    for(int i = 0; i<n;i++){
        //자기 자신 노드는 처음엔 무조건 1, 연결되어 있는 모든 노드들을 끄집어 없앰.
        //그러면서 네트워크 추가
        if(computers[i][i] && dfs(i ,computers)) 
            answer++;
    }
    
    return answer;
}