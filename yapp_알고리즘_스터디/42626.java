import java.util.*;
class Solution {
    public int solution(int[] scoville, int K) {
        int answer = 0;
        PriorityQueue<Integer> pq = new PriorityQueue<>();

        for(int i : scoville) pq.add(i);

        while(pq.peek() < K) {
            if(pq.size() == 1) {
                answer = -1;
                break;
            }
            int first = pq.poll();
            int second = pq.poll();
            int scoviller = first + second * 2;
            pq.add(scoviller);
            answer++;
        }
        return answer == 0 ? -1 : answer;
    }
}