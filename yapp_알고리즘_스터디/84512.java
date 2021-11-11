class Solution {
    public int solution(String word) {
        int answer = word.length();
        String dic = "AEIOU";
        int[] counts = {781, 156, 31, 6, 1};

        for(int i = 0; i < word.length(); i++) {
            int index = dic.indexOf(word.charAt(i));
            answer += counts[i] * index;
        }

        return answer;
    }
}