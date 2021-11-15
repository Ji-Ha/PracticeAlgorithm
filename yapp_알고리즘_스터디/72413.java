import java.util.*;
class Solution {
    static int MAX = 20000001;
    static int[][] lines;

    public int solution(int n, int s, int a, int b, int[][] fares) {
        lines = new int[n][n];
        for(int[] fare : fares) {
            // 한점에서 다른 한점까지 가는데 걸리는 비용을 저장하는 것.쇼ㅓㅗㅎㄹㅇ   ㅂ   1ㅂ21    ㅂ2ㅈㅂ1   ㅂ1  ₩1ㅂ21   2ㅈㄷㄱ    1   1₩  ₩   ₩1  =-09876[
            lines[fare[0] - 1][fare[1] - 1] = fare[2];
            lines[fare[1] - 1][fare[0] - 1] = fare[2];
        }

        int[] fromStart = dijkstra(s - 1, n);
        int[] fromA = dijkstra(a - 1, n);
        int[] fromB = dijkstra(b - 1, n);
        int answer = MAX;

        for(int i = 0; i < n; i++)
            answer = Math.min(answer, fromStart[i] + fromA[i] + fromB[i]); // a, b, start에서 i까지 가는 거리들의 합. 그중 최소인 친구를 구하는 과정.
        //s에서 합승하지 않는 경우라 하더라도, i가 s가 되는 경우라면 합승하지 않고 이동할 수 있음.

        return answer;
    }

    private int[] dijkstra(int begin, int n) {
        PriorityQueue<int[]> pq = new PriorityQueue<>((x, y) -> x[1] - y[1]);
        pq.add(new int[]{begin, 0});
        int[] result = new int[n];
        Arrays.fill(result, MAX);
        result[begin] = 0;

        while(!pq.isEmpty()) {
            int[] curr = pq.poll();
            if(curr[1] > result[curr[0]]) continue;

            for(int i = 0; i < n; i++) {
                int cost = lines[curr[0]][i] + result[curr[0]];
                if(lines[curr[0]][i] > 0 && result[i] > cost) {
                    result[i] = cost;
                    pq.offer(new int[]{i, cost});
                }
            }
        }
        return result;
    }
}