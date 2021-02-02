#include <iostream>
#include <string>
using namespace std;

int m;
int q; // m == 원문에 출현할 단어의 수, q == 처리해야할 문장의 수
string value[500];
float B[500]; // 문장의 처음에 출현할 확률
float T[500][500]; // i번 단어의 다음에 단어가 j일 확률 
float M[500][500]; // i번 단어가 적힌 조각을 j번 단어로 분류할 확률.
string problem[100];


int main(){
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);

  cin >> m >> q;

  for(int i = 0; i < m; i++)
    cin >> value[i];

  for(int i = 0; i < m; i++){
    for(int j = 0; j < m; j++)
      cin >> T[i][j];
  }

  for(int i = 0; i < m; i++){
    for(int j = 0; j < m; j++)
      cin >> M[i][j];
  }

  int n;
  while(q--){
    cin >> n;
    for(int i = 0; i < n; i++){
      string tmp;
      cin >> tmp;
    }
  }
  return 0;
}