package coding_test;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) throws IOException {
        int target, num;
        int[][] list;
        int[] dp;
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;

        target = Integer.parseInt(br.readLine());
        num = Integer.parseInt(br.readLine());
        list = new int[num][2];
        dp = new int[target + 1];

        for(int i = 0; i < num; i++) {
            st = new StringTokenizer(br.readLine());
            list[i][0] = Integer.parseInt(st.nextToken());
            list[i][1] = Integer.parseInt(st.nextToken());
        }

        dp[0] = 1;

        for(int i = 0; i < num; i++) {
            int base = list[i][0];
            for(int j = target; j >= base; j--) {
                for(int k = 1; k <= list[i][1]; k++) {
                    if(j - base * k < 0) break;
                    dp[j] += dp[j - base * k];
                }
            }
        }
        System.out.println(dp[target]);
    }
}