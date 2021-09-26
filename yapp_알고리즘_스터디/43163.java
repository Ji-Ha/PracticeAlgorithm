class Solution {
    static int answer = Integer.MAX_VALUE;
    static boolean[] used;
    static String t;
    static String[] w;
    public int solution(String begin, String target, String[] words) {
        t = target;
        used = new boolean[words.length];
        w = words;

        for(int i = 0; i < w.length; i++){
            used[i] = true;
            DFS(0, begin, i);
            used[i] = false;
        }

        return answer == Integer.MAX_VALUE ? 0 : answer;
    }

    public void DFS(int count, String now, int point) {
        if(now.equals(t)) {
            if(answer > count) answer = count;
            return ;
        }

        for(int i = 0; i < w.length; i++) {
            if(!used[i] && check(now, w[i])) {
                used[i] = true;
                DFS(count + 1, w[i], i);
                used[i] = false;
            }
        }
    }

    public boolean check(String now, String next) {
        int count = 0;

        for(int i = 0; i < now.length(); i++) {
            if(now.charAt(i) != next.charAt(i)) count++;
        }

        return count == 1 ? true : false;
    }
}