#include <iostream>

using namespace std;

// 엄청 깔끔한 코드인 것 같다.
// 처음 생각할 때는 부분부분을 주고 받는 분할정복일 줄 알고 좀 시간이 걸렸다.
void solution(int i, int j, int num){
  if((i / num) % 3 == 1 && (j / num) % 3 == 1){
    cout << ' ';
  }
  else{
    if(num / 3 == 0)
      cout << '*';
    else
      solution(i, j, num / 3);
  }
}

int main(){
  int num;
  cin >> num;

  for(int i = 0; i < num; i++){
    for(int j = 0; j < num; j++){
      solution(i, j, num);
    }
    cout << '\n';
  }
  return 0;
}