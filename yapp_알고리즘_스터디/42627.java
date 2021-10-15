import java.util.*;
class Solution {
    public int solution(int[][] jobs) {
        int answer = 0;
        int end = 0;
        int jobsIndex = 0;
        int count = 0;

        Arrays.sort(jobs, (o1, o2) -> o1[0] - o2[0]);
        PriorityQueue<int[]> pq = new PriorityQueue<>((o1, o2) -> o1[1] - o2[1]);

        while(count < jobs.length) {
            while(jobsIndex < jobs.length && jobs[jobsIndex][0] <= end)
                pq.add(jobs[jobsIndex++]);

            if(pq.isEmpty()) end = jobs[jobsIndex][0];
            else {
                int[] temp = pq.poll();
                answer += temp[1] - temp[0] + end;
                end += temp[1];
                count++;
            }
        }

        return (int) Math.floor(answer / jobs.length);
    }
}