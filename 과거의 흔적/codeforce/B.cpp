#include <iostream>
using namespace std;
int q, d;
int value[10000];

//숫자가 주어졌을 때, nezzar가 좋아하는 수가 그 숫자에 포함되어 있으면 yes, 아니면 no
// 숫자를 빼면서 찾는다.
// 10으로 나누어서 
void solution(){
  for(int i = 0; i < q; i++){
    if(value[i] % 7 == 0){
      cout << "YES\n";
    }
    else if(value[i] >= 70)
      cout << "YES\n";
    else{
      if(value[i] % 10 == 0 && value[i] < 70)
        cout << "NO\n";
      else if(value[i] % 10 == 3 && value[i] < 63)
        cout << "NO\n";
      else if(value[i] % 10 == 6 && value[i] < 56)
        cout << "NO\n";
      else if(value[i] % 10 == 9 && value[i] < 49)
        cout << "NO\n";
      else if(value[i] % 10 == 2 && value[i] < 42)
        cout << "NO\n";
      else if(value[i] % 10 == 5 && value[i] < 35)
        cout << "NO\n";
      else if(value[i] % 10 == 8 && value[i] < 28)
        cout << "NO\n";
      else if(value[i] % 10 == 1 && value[i] < 21)
        cout << "NO\n";
      else if(value[i] % 10 == 4 && value[i] < 14)
        cout << "NO\n";
      else
        cout << "YES\n";
    }
  }
}
int main(){
  int t;
  cin >> t;
  
  while(t--){
    cin >> q >> d;

    for(int i = 0; i < q; i++){
      cin >> value[i];
    }
    solution();
  }
  return 0;
}