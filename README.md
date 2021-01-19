## 알고리즘 공부 과정

    VScode c++ 컴파일 : ctrl + shift + b
                run  : ctrl + shift + t

#### feedback
- 오늘부터 카카오 코딩테스트를 연습해보려고 한다.
첫 번째는 단체사진 찍기.
순열을 사용하여 푸는 방식인데, 내가 순열에 대해서 잘 모르는 것 같다. 참고해서 풀었으니 순열에 대해 다시 공부하는 것으로..!


- 카카오 코딩테스트는 시간이 너무 오래 걸린다.
원인은 내 수준이 아직 낮다고 판단, 군대에서 사놓고 다 안푼 '종만북'으로 목표를 변경하였다.
2달안에 모두 풀고 다시 카카오 코딩테스트로 넘어가겠다.

##### PICNIC
    - 컴퓨터의 연산속도를 기반으로 진행하는 완전탐색을 이용하여 푸는 알고리즘.
    - 알고리즘 문제를 풀 때 처음으로 고려해야하는 기초적인 알고리즘 == 무식하게 풀기(완전탐색)
    - 아무리 무식하게 푼다 그래도 효율적으로 푸는 방법이 있으니 잘 설계해서 풀것.
    
    소풍 같은 경우는, 소풍을 가기위해 짝을 찾는 문제였다.
    
    개선해야할 점(이러한 점 때문에 시간 낭비하였음)
     - 중복을 제거해야한다.( -> 이는 next_permutation을 이용하여 푸는 방법도 다시 해보면 좋을듯)
     - 테스트케이스가 여러개일 수 있으니까 초기화를 잘해줘야한다.



##### BOARACOVER
    - 완전탐색을 이용하여 풀이가 필요한 문제.
    - 중간과 마지막에 좀 헤맸다. 처음 개념은 잘 잡고 갔는데, 코딩하면서 x와 y의 값 혼동으로 인하여 혼선이 있었다.
    - clean code 읽는 것을 코딩테스트에 적용하여 푸는 것은 어떨까 생각해서 refactoring 했다. 나름 나쁘지 않은 것 같다.
    - 앞으로는 차근차근 시간 생각하면서 풀어보기.


##### CLOCKSYNC
    - 무한정하게 돌아가야하는 시계를 보고는 암담했다. 시계는 다시 돌아온다는 생각은 범위를 유한하게 만들었다.
    - 또한, linked를 선언하여 사용함으로써, vector를 쓰지 않고 하는 방식을 사용할 수 있었고, 코드 또한 짧아졌다.
    - 생각을 계속 비틀수만 있다면 충분히 빠르고, 정확하게 풀 수 있을 것 같다.
    - 어렵다.

##### FENCE
    - 처음에 fence 높이를 vector에 저장해서 실행했는데, 이는 시간이 배열로 선언한 것보다 느리다는 문제가 있었다.(시간초과로 문제를 못품)
    - 그래서 전역변수로 배열을 선언하여 사용하여 시간을 단축하였다. **vector가 공간을 효율적으로 쓸 수 있다는 장점이 있지만, 시간을 많이 잡아먹는다라는 것** 을 처음 느낀 것 같다.
    - 그래도 오답..
    - 어쩌면 사소한, 데이터셋의 길이를 -1해서 넘겨주지않아 오답이 떴던 거 였다. 아쉽다ㅠㅠ.

#### FANMEETING
    - 카라츠바 알고리즘으로 풀면 빠르고 정확하게 풀 수 있다는 것을 인지함.
    - 근데 분할정복이라는 게 쓰여서 풀리는건지 의문. 고민중.