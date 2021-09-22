package coding_test;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
    static int N, K;
    static int[] w, v;
    static int[][] dp;

    // dp[][] == dp[물건의 번호][무게]
    // dp[i][j] = dp[i - 1][j] or dp[i - 1][j - w[i]] + v[i]
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        N = Integer.parseInt(st.nextToken());
        K = Integer.parseInt(st.nextToken());

        w = new int[N + 1];
        v = new int[N + 1];
        dp = new int[N + 1][100001];

        for(int i = 1; i <= N; i++) {
            st = new StringTokenizer(br.readLine());
            w[i] = Integer.parseInt(st.nextToken());
            v[i] = Integer.parseInt(st.nextToken());
        }

        for(int i = 1; i <= N; i++) {
            for(int j = 1; j <= K; j++) {
                dp[i][j] = dp[i - 1][j];
                if(j - w[i] >= 0) // 0보다 작으면 불가능해열wp.
                    dp[i][j] = Math.max(dp[i][j], dp[i- 1][j - w[i]] + v[i]);
            }
        }

        System.out.println(dp[N][K]);
    }
}