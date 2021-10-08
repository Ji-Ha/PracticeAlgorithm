package coding_test;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
    static int N, M, ans = Integer.MAX_VALUE;
    static int[] memories, costs;
    static int[][] dp;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());
        dp = new int[N][10000001];
        memories = new int[N + 1];
        costs = new int[N];

        st = new StringTokenizer(br.readLine());
        for(int i = 0; i < N; i++) memories[i] = Integer.parseInt(st.nextToken());
        st = new StringTokenizer(br.readLine());
        for(int i = 0; i < N; i++) costs[i] = Integer.parseInt(st.nextToken());

        for(int i = 0; i< N; i++) {
            int cost = costs[i];
            int memory = memories[i];

            for(int j = 0; j <= 10000; j++) {
                if(i == 0) {
                    if(j >= cost) dp[i][j] = memory;
                }
                else {
                    if(j >= cost) dp[i][j] = Math.max(dp[i - 1][j - cost] + memory, dp[i - 1][j]);
                    else dp[i][j] = dp[i - 1][j];
                }

                if(dp[i][j] >= M) ans = Math.min(ans, j);
            }
        }

        System.out.println(ans);
    }
}