import java.util.*;

class Solution {
    public int solution(int[] d, int budget) {
        int answer = 0;
        Arrays.sort(d);

        for(int price : d) {
            if(price <= budget) budget -= price;
            else break;
            answer++;
        }
        return answer;
    }
}