#include <iostream>

using namespace std;
const int ANSWER_SIZE = 3;
int board[2187][2187] = {0, };
int result[ANSWER_SIZE] = {0, };

void solution(int y, int x, int size){
  int check = board[y][x];
  for(int i = y; i < y + size; i++){
    for(int j = x; j < x + size; j++){
      if(check != board[i][j]){
        solution(y, x, size / 3); solution(y, x + (size / 3), size / 3); solution(y, x + (size / 3) * 2, size / 3);
        solution(y + (size / 3), x, size / 3); solution(y + (size / 3), x + (size / 3), size / 3); solution(y + + (size / 3), x + (size / 3) * 2, size / 3);
        solution(y + (size / 3) * 2, x, size / 3); solution(y + (size / 3) * 2, x + (size / 3), size / 3); solution(y + (size / 3) * 2, x + (size / 3) * 2, size / 3);
        return;
      }
    }
  }
  if(check == -1)
    result[0]++;
  if(check == 0)
    result[1]++;
  if(check == 1)
    result[2]++;
}

int main(){
  int size = 0;
  cin >> size;

  for(int i = 0; i < size; i++){
    for(int j = 0; j < size; j++)
      cin >> board[i][j];
  }

  solution(0, 0, size);

  for(int i = 0; i < ANSWER_SIZE; i++){
    cout << result[i] << '\n';
  }
  return 0;
}