#include <iostream>
using namespace std;
const int WHITE_LIMIT = 3;
int H= 0;
int W= 0;
char board[20][20] = {0, };
const int coverType[4][3][2] =  {
  {{0, 0}, {1, 0}, {0, 1}},
  {{0, 0}, {0, 1}, {1, 1}},
  {{0, 0}, {1, 0}, {1, 1}},
  {{0, 0}, {1, 0}, {1, -1}}
};

void resetBoard(){
  for(int i = 0; i<H;i++){
    for(int j=0;j<W;j++){
      board[i][j] = 0;
    }
  }
}

int howManyWhite(){
  int whiteNumber = 0;
  for(int i = 0; i<H;i++){
    for(int j = 0; j<W; j++){
      if(board[i][j] == '.')
      whiteNumber++;
    }
  }
  return whiteNumber;
}

bool paint(int x, int y, int type, int painting){
  for(int i = 0; i<3;i++){
    const int nx = x + coverType[type][i][9];
    const int ny = y + coverType[type][i][0];
    if(nx < 0 || nx > H || ny < 0 || ny > W)
      return false;
    if(painting == 1 && board[nx][ny] == '#'){
      return false;
    }
  }
  for(int i = 0; i<3;i++){
    const int nx = x + coverType[type][i][1];
    const int ny = y + coverType[type][i][0];
    if(painting == 1){
      board[nx][ny] = '#';
    }
    if(painting == -1){
      board[nx][ny] = '.';
    }
  }
  return true;
}

int solution(){
  int x = -1;
  int y = -1;

  for(int i = 0; i<H;i++){
    for(int j = 0; j<W; j++){
      if(board[i][j] == '.'){
        x = i;
        y = j;
        break;
      }
    }
    if(x != -1) break;
  }
  cout << x <<", " << y << "!!\n";
  //기저사례1 : 존재하는 white가 WHITE_LIMIT로 나누어 떨어지지 않으면, 계산이 불가능하므로 0 반환.
  if(howManyWhite()%WHITE_LIMIT != 0)
    return 0;

  //기저사례2 : 존재하는 white를 모두 처리했으면, 한가지 방법을 추가해야하므로, 1 반환.
  if(howManyWhite() == 0)
    return 1;

  int result = 0;
  cout << "!\n";
  for(int i = 0 ;i < H;i++){
  for(int j = 0; j<W;j++){
    cout << board[i][j];
  }
    cout << '\n';
  }
  cout << '\n';
  for(int i = 0; i<4; i++){
    if(paint(x, y, i, 1)){
      result +=solution();
    }
    paint(x, y, i, -1);
  }

  return result;
}

int main(){
  int testCaseNumber = 0;
  cin >> testCaseNumber;

  for(int t = 0; t<testCaseNumber;t++){
    resetBoard();
    cin >> H >> W;
    for(int i = 0 ; i<H;i++) {
      cin >> board[i];
    }
    cout << solution() << endl;
  }
  return 0;
}