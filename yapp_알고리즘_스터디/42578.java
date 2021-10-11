import java.util.*;
class Solution {
    public int solution(String[][] clothes) {
        int answer = 1;
        Map<String, Integer> category = new HashMap();

        for(String[] cloth : clothes) {
            if(!category.containsKey(cloth[1])) category.put(cloth[1], 1);

            else {
                int temp = category.get(cloth[1]);
                category.put(cloth[1], temp + 1);
            }
        }

        for(String keys: category.keySet())
            answer *= (category.get(keys) + 1);

        //하나도 안입으면 안돼요..!
        return answer - 1;
    }
}