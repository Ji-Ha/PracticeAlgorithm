package coding_test;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
    static int N;
    static int[] stairs, dp;

    public static void main(String[] args) throws IOException {
        input();
        dp = new int[N+1];

        logic(N);

        System.out.println(dp[N]);
    }

    private static int logic(int stair) {
        if(stair <= 0) return 0;
        if(stair == 1) return dp[stair] = stairs[1];
        if(dp[stair]!=0) return dp[stair];

        return dp[stair] = Math.max(logic(stair-2), logic(stair-3)+stairs[stair-1]) + stairs[stair];
    }

    private static void input() throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        N = Integer.parseInt(br.readLine());
        stairs = new int[N+1];

        for(int i = 1; i <= N; i++) stairs[i] = Integer.parseInt(br.readLine());
    }
}