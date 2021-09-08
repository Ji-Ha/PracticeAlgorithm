package coding_test;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;


        int N = Integer.parseInt(br.readLine()); //객차의 수
        int limit; // 소형 기관차가 가지는 최대 객실 수
        int[] trains = new int[N + 1]; //객차에 타고있는 손님들의 수
        int[] sums = new int[N + 1]; //1부터 특정 수까지의 손님들의 합
        int[][] dp = new int[4][N + 1]; //소형 기관차의 수, x객차일 때 가장 많은 승객이 타있는 경우를 dp에 저장.

        st = new StringTokenizer(br.readLine());
        for(int i = 1; i <= N; i++) {
            trains[i] = Integer.parseInt(st.nextToken());
            sums[i] = sums[i - 1] + trains[i];
        }
        limit = Integer.parseInt(br.readLine());

        for(int i = 1; i <= 3; i++) {
            for(int j = i * limit; j <= N; j++)
                dp[i][j] = Math.max(dp[i][j - 1], dp[i - 1][j - limit] + (sums[j] - sums[j - limit]));
                // 점화식. 같은 소형기관차 중 전 객실까지의 승객 수가 많은지, 현재 소형기관차 - 1했을 때의 값 + 제한된 객차의 승객 합 이 더 많은지
        }

        System.out.println(dp[3][N]);
    }
}