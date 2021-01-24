#include <iostream>
#include <algorithm>
using namespace std;
int board[100000] = {0, };
int N = 0;

int solution(int left, int right){
  if(left == right) return board[left];

  int mid = (left + right) / 2;
  int result = max(solution(left, mid), solution(mid + 1, right));
  
  int low = mid;
  int high = mid + 1;
  int height = min(board[low], board[high]);

  result = max(result, height * 2);

  while(left < low || high < right){
    if(high < right && (low == left || board[low - 1] < board[high + 1])){
      ++high;
      height = min(height, board[high]);
    }
    else {
      --low;
      height = min(height, board[low]);
    }

    result = max(result, height * (high - low + 1));
  }
  return result;
}
int main(){
  cin >> N;

  for(int i = 0; i < N; i++){
    cin >> board[i];
  }
  cout << solution(0, N - 1) << "\n";

  return 0;
}