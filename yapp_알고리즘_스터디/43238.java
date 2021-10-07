import java.util.*;

// 이걸 이분탐색으로 풀줄이야..
// 생각지도 못한 방식이어서 참고하여 풀었다.
// 풀고나니 인정할 수밖에 없다. 다시풀면 좋겠다.
class Solution {
    public long solution(int n, int[] times) {
        long answer = 0;
        Arrays.sort(times);
        long left = 0, right = (long)n * times[times.length-1];

        while(left <= right) {
            long mid = (left + right)/2;
            long sum = 0;

            for(int i = 0; i < times.length; i++)
                sum += mid/times[i];

            if(sum < n) left = mid+1;
            else {
                right = mid - 1;
                answer = mid;
            }
        }

        return answer;
    }
}