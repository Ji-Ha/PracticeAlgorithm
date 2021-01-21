#include <iostream>

using namespace std;

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