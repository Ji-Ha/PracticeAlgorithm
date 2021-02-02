#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cstring> //memset
using namespace std;

int total, capacity;        //총 아이템 양과 가방 용량
int volume[100], need[100]; //물건의 부피와 절박도
int cache[1001][100];
string name[100];

int pack(int capacity, int item)
{
  if (item == total)
    return 0;

  int &result = cache[capacity][item];

  if (result != -1)
    return result;

  result = pack(capacity, item + 1);

  if (capacity >= volume[item])
    result = max(result, pack(capacity - volume[item], item + 1) + need[item]);

  return result;
}

//여행 짐싸기 문제의 답 역추적하는 재귀 호출 알고리즘

void reconstruct(int capacity, int item, vector<string> &picked)
{
  if (item == total)
    return;

  if (pack(capacity, item) == pack(capacity, item + 1)) //item을 선택하지 않아도 최대 절박도 동일(즉, item 선택 안해도 된다)
    reconstruct(capacity, item + 1, picked);
  else
  {
    picked.push_back(name[item]); //item 선택
    reconstruct(capacity - volume[item], item + 1, picked);
  }
}

int main(void)
{
  int test_case;
  cin >> test_case;

  for (int i = 0; i < test_case; i++)
  {
    vector<string> picked;
    cin >> total >> capacity;

    for (int j = 0; j < total; j++)
      cin >> name[j] >> volume[j] >> need[j];
    
    memset(cache, -1, sizeof(cache));
    reconstruct(capacity, 0, picked);

    cout << pack(capacity, 0) << " " << picked.size() << endl;

    for (int j = 0; j < picked.size(); j++)
      cout << picked[j] << endl;
  }
  return 0;
}