package coding_test;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringBuilder sb = new StringBuilder();
    static int N, M;
    static int[][] dp;

    public static void main(String[] args) throws IOException {
        int t = Integer.parseInt(br.readLine());

        for (int i = 0; i < t; i++) {
            input();
            sb.append(logic()).append("\n");
        }
        System.out.println(sb);
    }

    private static int logic() {
        dp = new int[30][30];
        for(int j = 2; j <= N; j++) dp[j][1] = 0;
        for(int j = 1; j <= M; j++) dp[1][j] = j;

        for(int j = 2; j <= N; j++) {
            for(int k = 2; k <= M; k++)
                dp[j][k] = dp[j][k-1] + dp[j-1][k-1];
        }
        return dp[N][M];
    }

    private static void input() throws IOException {
        StringTokenizer st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());
    }
}