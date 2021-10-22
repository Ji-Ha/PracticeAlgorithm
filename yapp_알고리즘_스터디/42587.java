import java.util.*;
import java.awt.*;

class Solution {
    public int solution(int[] priorities, int location) {
        int answer = 0;
        Queue<Point> q = new LinkedList<>();
        PriorityQueue<Integer> pq = new PriorityQueue<>(Collections.reverseOrder());

        for(int i = 0; i < priorities.length; i++) {
            Point now = new Point(i, priorities[i]);
            q.add(now);
            pq.add(priorities[i]);
        }

        while(!q.isEmpty()) {
            Point cur = q.poll();
            if(cur.y < pq.peek())
                q.add(cur);
            else {
                answer++;
                pq.poll();
                if(cur.x == location) break;
            }
        }
        return answer;
    }
}