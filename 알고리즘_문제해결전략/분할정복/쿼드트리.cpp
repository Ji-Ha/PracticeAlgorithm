#include <iostream>
#include <string>
using namespace std;

char board[64][64];

void zip(int y, int x, int length){
  char check = board[y][x];
  string result;

  for(int i = y; i < y + length; i++){
    for(int j = x; j < x + length; j++){
      if(check != board[i][j]){
        cout << "(";
        zip(y, x, length / 2); zip(y, x + length / 2, length / 2);
        zip(y + length / 2, x, length / 2); zip(y + length / 2, x + length / 2, length / 2);
        cout << ")";
        return;
      }
    }
  }

  cout << check;
}

int main(){
  int length = 0;
  cin >> length;
  
  for(int i = 0; i < length; i++){
    cin >> board[i];
  }

  zip(0, 0, length);
  return 0;
}