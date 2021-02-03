#include <iostream>
#include <string>
#include <algorithm>
#include <memory.h>
using namespace std;

const int MAX = 1000000000 + 1;
const string NEXT_X = "X+YF";
const string NEXT_Y = "FX-Y";
int length[51];

void preCalc(){
  memset(length, 0, sizeof(length));
  length[0] = 1;
  for(int i = 1; i <= 50; i++)
    length[i] = min(MAX, length[i - 1] * 2 + 2);
}

char expand(const string& dragonCurve, int generation, int skip){
  if(generation == 0) {
    return dragonCurve[skip];
  }
  for(int i = 0; i < dragonCurve.size(); i++){
    if(dragonCurve[i] == 'X' || dragonCurve[i] == 'Y'){
      if(skip >= length[generation]) skip -= length[generation];
      else if(dragonCurve[i] == 'X') return expand(NEXT_X, generation - 1, skip);
      else return expand(NEXT_Y, generation - 1, skip);
    }

    else if(skip > 0) skip--;

    else return dragonCurve[i];
  }
  return 'N';
}


int main(){
  int c;
  cin >> c;

  while(c--){
    int n, p, l;
    cin >> n >> p >> l;

    preCalc();
    for(int i = 0; i < l; i++){
      cout << expand("FX", n, (p + i - 1));
    }
    
    cout << '\n';
  }
  return 0;
}