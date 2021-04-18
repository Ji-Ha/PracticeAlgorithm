#include <iostream>
#include <vector>
using namespace std;
int arr[1001][1001];

vector<int> solution(int n){
    vector<int> answer;
    int y = 0, x = 0, state = 0, num = 1;

    for(int i = 0; i < n; i++){
        switch(state){
            case 0 :
                for(int j = i; j < n; j++)
                    arr[y++][x] = num++;
                y--;
                x++;
                state = 1;
                break;
            case 1 :
                for(int j = i; j < n; j++)
                    arr[y][x++] = num++;
                y--;
                x -= 2;
                state = 2;
                break;
            case 2 :
                for(int j = i; j < n; j++)
                    arr[y--][x--] = num++;
                y += 2;
                x++;
                state = 0;
                break;
        }
    }

    for(int i = 0; i < n; i++)
        for(int j = 0; j <= i; j++)
            answer.push_back(arr[i][j]);
    
    return answer;
}

int main(){
    int n;
    cin >> n;
    
    for(auto i : solution(n)){
        cout << i << ' ';
    }
    return 0;
}