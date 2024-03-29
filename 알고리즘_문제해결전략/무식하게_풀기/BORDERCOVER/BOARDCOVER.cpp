#include <iostream>
#include <vector>
#include <string>
using namespace std;

const int TYPE_BLOCK_NUMBER = 3;
const int TYPE_NUMBER = 4;
const int X = 1;
const int Y = 1;

const int coverType[4][3][2] = {
    {{0, 0}, {1, 0}, {0, 1}},
    {{0, 0}, {0, 1}, {1, 1}},
    {{0, 0}, {1, 0}, {1, 1}},
    {{0, 0}, {1, 0}, {1, -1}}
};

bool set(vector<vector<int>> &board, int y, int x, int type, int delta){
  bool ok = true;
  for (int i = 0; i < TYPE_BLOCK_NUMBER; i++)
  {
    int ny = y + coverType[type][i][Y];
    int nx = x + coverType[type][i][X];

    if(ny < 0 || ny >= board.size() || nx < 0 || nx >= board[0].size())
      ok = false;
    else if((board[ny][nx] += delta) > 1)
      ok = false;
  }
  return ok;
}

int cover(vector<vector<int>> &board){
  int y = -1;
  int x = -1;

  for (int i = 0; i < board.size(); i++){
    for (int j = 0; j < board[i].size(); j++){
      if (board[i][j] == 0){
        y = i;
        x = j;
        break;
      }
    }
    if (y != -1)
      break;
  }

  //기저사례 : 모든 타일이 검은색이면 1 return.
  if (y == -1)
    return 1;
  
  int result = 0;
  for (int type = 0; type < TYPE_NUMBER; type++){
    if (set(board, y, x, type, 1))
      result += cover(board);
    set(board, y, x, type, -1);
  }
  return result;
}

int main(){
  int testCase = 0;
  cin >> testCase;

  int y, x;
  for (int t = 0; t < testCase; t++){
    cin >> y >> x;
    vector<vector<int>> board(y, vector<int>(x, 0));
    string tmp;

    for (int i = 0; i < y; i++){
      cin >> tmp;
      for (int j = 0; j < tmp.size(); j++){
        if (tmp[j] == '#')
          board[i][j] = 1;
      }
    }
    cout << cover(board) << endl;
  }
  return 0;
}