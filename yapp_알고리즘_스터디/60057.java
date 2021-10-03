class Solution {
    public int solution(String s) {
        int answer = Integer.MAX_VALUE;

        if(s.length() == 1) return 1;
        for(int i = 1; i <= s.length()/2; i++) {

            String ans = comp(s, i);
            answer = Math.min(answer, ans.length());
        }
        return answer;
    }

    private String comp(String s, int i) {
        int count = 1;
        String com = "";
        String pattern = "";

        for(int j = 0; j <= s.length() + i; j += i) {
            String now;

            if(j >= s.length()) now = "";
            else if(s.length() < j + i) now = s.substring(j);
            else now = s.substring(j, j + i);

            if(j != 0) {
                if(now.equals(pattern)) count++;
                else if(count >= 2) {
                    com += String.valueOf(count) + pattern;
                    count = 1;
                }
                else com += pattern;
            }
            pattern = now;
        }
        return com;
    }

}