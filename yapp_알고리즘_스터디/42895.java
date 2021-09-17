class Solution {
    static int answer = -1;
    public int solution(int N, int number) {
        cal(N, number, 0, 0);
        return answer;
    }

    // 이 문제를 풀 때 가장 중요한 것은,
    // 다음 수를 어떻게 처리할 것인지 인 것, cal이라는 함수에서도 for문이 가장 중요.
    // 해당하는 자릿수를 늘려주면서 다음 사칙연산으로 보내기 때문에, 모든 경우 체크 가능.
    // 상희님 코드를 참조했음.
    public void cal(int n, int number, int count, int calculation) {
        int next = n;

        if(count > 8) return ;

        if(calculation == number) {
            if(answer == -1 || answer > count)
                answer = count;
            return ;
        }

        for(int i = 1; i < 9 - count; i++) {
            cal(n, number, count + i, calculation + next);
            cal(n, number, count + i, calculation - next);
            cal(n, number, count + i, calculation * next);
            cal(n, number, count + i, calculation / next);
            next = next * 10 + n;
        }
    }
}