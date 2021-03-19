#include <iostream>
using namespace std;
int m, n;
int value[500][500];
bool checker[500][500];

int solution(int y, int x){
    // 기저사례 1.
    if(y >= m || x >= n || y < 0 || x < 0) return 0;
    // 기저사례 2.
    //if(checker[y][x]) return 0;

    if(y == m - 1 && x == n - 1) return 1;

    //checker[y][x] = true;

    if(value[y + 1][x] < value[y][x]) return solution(y + 1, x);
    if(value[y - 1][x] < value[y][x]) return solution(y - 1, x);
    if(value[y][x + 1] < value[y][x]) return solution(y, x + 1);
    if(value[y][x - 1] < value[y][x]) return solution(y, x - 1);

    return 0;
}

int main(){
    cin >> m >> n;
    int answer = 0;

    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++) cin >> value[m][n];
    }

    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++) answer += solution(i, j);
    }

    cout << answer << '\n';
    return 0;
}