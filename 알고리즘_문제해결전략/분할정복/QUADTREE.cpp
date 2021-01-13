#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

const int QUADRANT = 4;

string split(string splitQuadTree, int start){
  return splitQuadTree.substr(start, splitQuadTree.length());
}

string result(string quadTree){
  bool end = true;
  string up;
  string down;

  for(int i = 0; i<quadTree.length();i++){
    if(quadTree[i] == 'x'){
      result(split(quadTree, i));
      end = false;
    }
  }
}

int main(){
  int testCase = 0;
  cin >> testCase;

  for(int i = 0; i<testCase; i++){
    string quadTree;
    cin >> quadTree;
    result(quadTree);
  }
  return 0;
}