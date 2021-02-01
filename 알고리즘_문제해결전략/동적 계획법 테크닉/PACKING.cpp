#include <iostream>
#include <algorithm>
#include <string>
#include <memory.h>
#include <vector>
using namespace std;

int n, w;
string name[100];
int volume[100];
int importance[100];
int cache[1000][100];
vector<string> answer;

int solution(int capacity, int item){
  if(item == n) return 0;
  int& res = cache[capacity][item];
  if(res != -1) return res;

  res = solution(capacity, item - 1);

  if(capacity >= volume[item])
    res = max(res, solution(capacity - volume[item], item - 1)) + importance[item];

  return res;
}

void reconstruct(int capacity, int item){
  if(item == n + 1) return;
  if(solution(capacity, item) == solution(capacity, item + 1))
    reconstruct(capacity, item + 1);
  else{
    answer.push_back(name[item]);
    reconstruct(capacity - volume[item], item + 1);
  }
}

void init(){
  memset(cache, -1, sizeof(cache));
  
  answer.clear();
}

int main(){
  int c;
  cin >> c;
  
  while(c--){
    init();
    cin >> n >> w;
    for(int i = 0; i < n; i++)
      cin >> name[i] >> volume[i] >> importance[i];
    
    reconstruct(w, 0);
    cout << solution(w, 0) << " " << answer.size() << '\n';
    for(int i = 0; i < answer.size(); i++)
      cout << answer[i] << "\n";
  }
  return 0;
}