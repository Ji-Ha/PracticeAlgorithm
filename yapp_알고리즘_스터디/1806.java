package coding_test;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
    static int N, S;
    static int[] values;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        N = Integer.parseInt(st.nextToken());
        S = Integer.parseInt(st.nextToken());
        values = new int[N];

        st = new StringTokenizer(br.readLine());
        for(int i = 0; i < N; i++)
            values[i] = Integer.parseInt(st.nextToken());

        int answer = find(0);
        System.out.println(answer == Integer.MAX_VALUE ? 0 : answer);
    }

    public static int find(int start) {
        int answer = Integer.MAX_VALUE;
        int left = start;
        int right = start;
        int sum = 0;

        while(true) {
            if(sum >= S) {
                sum -= values[left++];
                answer = Math.min(answer, right - left + 1);
            }
            else if(right == N) break;
            else sum += values[right++];
        }
        return answer;
    }
}