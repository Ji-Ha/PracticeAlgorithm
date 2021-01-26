#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<cassert>
#include<cstring>
using namespace std;
 
//-1은 아직 답이 계산되지 않았음을 의미한다.
//1은 해당 입력들이 서로 대응됨을 의미한다.
//0은 해당 입력들이 서로 대응되지 않음을 으미한다.
int cache[101][101];
//패턴과 문자열
string W, S;
//와일드카드 패턴 W[w...]가 문자열 S[s...]에 대응되는지 여부를 반환한다.
 
bool matchMemoized(int w,int s) {
    //w[pos]와 s[pos]를 맞춰나간다.
    int &ret = cache[w][s];

    if (ret != -1) return ret;
    while (s < S.size() && w < W.size() && (W[w] == '?' || W[w] == S[s])) 
      return ret = matchMemoized(w + 1, s + 1);
    
    //더이상 대응할 수 없으면 왜 while문이 끝났는지 확인한다.
    //2.패턴 끝에 도달해서 끝난경우: 문자열도 끝났어야 함
    if (w == W.size()) return ret = (s == S.size());
    //4. *를 만나서 끝난 경우: *에 몇 글자를 대응해야 할지 재귀 호출하면서 확인한다.
    if (W[w] == '*'){
        if(matchMemoized(w + 1, s) || (s < S.size() && matchMemoized(w, s + 1)))
          return ret = 1;
    }
    //3.이 외의 경우에는 모두 대응되지 않는다.
    return ret = 0;
    
}
 
int main()
{
    int cases;
    cin >> cases;
    while (cases--) {
        cin >> W;
        int n;
        cin >> n;
        vector<string> files;
        for (int i = 0; i < n; i++) {
            memset(cache, -1, sizeof(cache));
            cin >> S;
            if (matchMemoized(0, 0)==1)
                files.push_back(S);
        }
        sort(files.begin(), files.end());
        for (int i = 0; i < files.size(); i++)
            cout << files[i] << endl;
 
    }
 
    return 0;
}