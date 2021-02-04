#include <iostream>
using namespace std;

int main(){
  // 토핑 20개가 모두 들어가있는 것을 표한하는 비트마스크.
  int fullPizza = (1 << 20) - 1;

  //p라는 변수로 토핑을 표현할 때, p를 추가하고 싶다면?
  int p = 3;
  int topping = topping | (1 << p);

  // 토핑 목록에 p가 잘 추가되었는지 궁금하다면?
  // 만약 주어진 값이 true 라면 -> 결과값이 1 << p 로 나온다는 걸 알아두기.
  if(topping & (1 << p)) cout << "pepperoni is in" << '\n';

  // 원소의 삭제
  // 이런 식으로 쓴다면, topping에 p라는 요소가 있든 없든 간에 p를 제거할 수 있음.
  topping &= ~(1 << p);

  // 원소의 토글
  // xor 연산을 이용하여, 포함되어 있으면 없애고, 포함되어 있지 않으면 포함한다.
  topping ^= (1 << p);
  return 0;
}