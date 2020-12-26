#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
  int list[] = {1, 2, 3};

  sort(list, list+3);
  
  do{
    cout << list[0] << ' ' << list[1] << ' ' << list[2] << '\n';
  }while (next_permutation(list, list+3));
  
  return 0;
}