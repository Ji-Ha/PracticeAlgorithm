#include <iostream>
#include <memory.h>
using namespace std;
int data[10][10];

bool solution(pair<int, int> target, pair<int, int> soma){
    int y = soma.first, x = soma.second;
    if(target == soma) return true;
    if(solution(target, make_pair(y - 1, x))) return true;
    else return false;
}

int main(){
    int t;
    cin >> t;

    while(t--){
        memset(data, -1, sizeof(data));
        pair<int, int> key;
        pair<int, int> treausre;
        pair<int, int> soma;
        int n, m;
        cin >> n >> m;

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                cin >> data[i][j];
                if(data[i][j] == 2) treausre = make_pair(i, j);
                if(data[i][j] == 3) soma = make_pair(i, j);
                if(data[i][j] == 4) key = make_pair(i, j);
            }
        }
        if(solution(key, soma)){
            if(solution(treausre, soma)) cout << "1\n";
            else cout << "0\n";
        }
    }
    return 0;
}