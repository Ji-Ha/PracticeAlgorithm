package coding_test;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
    static int N;
    static int[] dp = new int[1001];

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        N = Integer.parseInt(br.readLine());

        dp[1] = 1;
        for(int i = 1; i < N; i++) {
            if(dp[i+1] == 0) dp[i+1] = 3 - dp[i];
            if(i+3 <= N) dp[i+3] = 3 - dp[i];
        }
        System.out.println(dp[N] % 2 == 0 ? "CY" : "SK");
    }
}