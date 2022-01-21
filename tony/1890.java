package coding_test;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
    static int N;
    static long[][] dp;
    static int[][] board;

    public static void main(String[] args) throws IOException {
        input();
        logic();
        System.out.println(dp[N-1][N-1]);
    }

    private static void logic() {
        dp[0][0] = 1;
        for(int i = 0; i < N; i++) {
            for(int j = 0; j < N; j++) {
                if(board[i][j] == 0) return;
                int now = board[i][j];
                if(i+now < N) dp[i+now][j] += dp[i][j];
                if(j+now < N) dp[i][j+now] += dp[i][j];
            }
        }
    }

    private static void input() throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;
        N = Integer.parseInt(br.readLine());
        board = new int[N][N];
        dp = new long[N][N];

        for(int i = 0; i < N; i++) {
            st = new StringTokenizer(br.readLine());
            for(int j = 0; j < N; j++) board[i][j] = Integer.parseInt(st.nextToken());
        }
    }
}