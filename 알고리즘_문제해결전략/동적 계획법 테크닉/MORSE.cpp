#include <iostream>
#include <string>
using namespace std;
int k;
int skip;

void generate(int n, int m, string s){
  if(n == 0 && m == 0){
    cout << s << '\n';
    return;
  }

  if(n > 0) generate(n - 1, m, s + "-");
  if(m > 0) generate(n, m - 1, s + "o");
}

int main(){
  int c;
  cin >> c;

  while(c--){
    int n, m;
    cin >> n >> m >> k;
    
    generate(n, m, "");
  }
  return 0;
}