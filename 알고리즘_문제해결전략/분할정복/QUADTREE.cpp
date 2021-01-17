#include <iostream>
#include <string>

using namespace std;

string solution(string::iterator& it){
  char head = *it;
  ++it;

  if(head == 'b' || head == 'w')
    return string(1, head);

  string upperLeft = solution(it);
  string upperRight = solution(it);
  string lowerLeft = solution(it);
  string lowerRight = solution(it);

  return string("x") + lowerLeft + lowerRight + upperLeft + upperRight;
}

int main(){
  int testCase = 0;
  string str;
  cin >> testCase;

  for(int t = 0; t < testCase; t++){
    
    cin >> str;
    string::iterator it = str.begin();
    cout << solution(it) << endl;
  }
  return 0;
}