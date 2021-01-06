#include <string>
#include <vector>

using namespace std;
//순위.
//플로이드 워셜 알고리즘.
void floyd(int n, vector<vector<bool>>& check){
    for(size_t i = 1; i<=n;i++){//중간 노드
        for(size_t j = 1; j<=n;j++){//시작 노드
            for(size_t k = 1; k<=n;k++){ // 마지막 노드
                if(check[j][i] && check[i][k])
                    check[j][k] = true;
            }
        }
    }
}

int solution(int n, vector<vector<int>> results) {
    int answer = 0;
    vector<vector<bool>> check(n+1, vector<bool>(n+1, false));
    //입력.
    for(auto r:results)
        check[r[0]][r[1]] = true;
    
    //플로이드워셜 알고리즘 start.
    floyd(n, check);
    
    for(size_t i = 1; i<=n;i++){
        int count = 0;
        for(size_t j = 1; j<=n;j++){
            if(check[i][j] || check[j][i])
                count++;
        }
        if(count == n-1) answer++;
    }
    return answer;
}