#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int cache[19683];

bool isFinished(const vector<string>& board, char turn){
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            if(board[i][j] != turn) break;
            if(j == 2) return true;
        }
    }

    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            if(board[j][i] != turn) break;
            if(j == 2) return true;
        }
    }

    for(int i = 0; i < 3; i++){
        if(board[i][i] != turn) break;
        if(i == 2) return true;
    }

    for(int i = 0; i < 3; i++){
        if(board[i][2 - i] != turn) break;
        if(i == 2) return true;
    }
    return false;
}

int bijection(const vector<string>& board){
    int res = 0;
    for(int y = 0; y < 3; y++){
        for(int x = 0; x < 3; x++){
            res = res * 3;
            if(board[y][x] == 'o') res++;
            if(board[y][x] == 'x') res += 2;
        }
    }
    return res;
}

int canWin(vector<string>& board, char turn){
    if(isFinished(board, 'o' + 'x' - turn)) return -1;
    int& res = cache[bijection(board)];
    if(res != - 2) return res;

    int minValue = 2;
    for(int y = 0; y < 3; y++){
        for(int x = 0; x < 3; x++){
            if(board[y][x] == '.'){
                board[y][x] = turn;
                minValue = min(minValue, canWin(board, 'o' - 'x' - turn));
                board[y][x] = '.';
            }
        }
    }

    if(minValue == 2 || minValue == 0) return res = 0;

    return res = -minValue;
}

int main(){
    int c;
    cin >> c;

    while(c--){
        vector<string> board;
        board.clear();
        for(int i = 0; i < 19683; i++)
            cache[i] = -2;
        
        int placed = 0;
        for(int i = 0; i < 3; i++){
            string input;
            cin >> input;
            for(int k = 0; k < 3; k++){
                if(input[k] != '.') placed++;
            }
            board.push_back(input);
        }

        char start = 'x';
        if(placed % 2 == 1) start = 'o';
        int result = canWin(board, start);

        if(result == -1) cout << (char)('x' + 'o' - start) << '\n';
        if(result == 0) cout << "TIE\n";
        if(result == 1) cout << start << '\n';
    }
    return 0;
}