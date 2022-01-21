package coding_test;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.math.BigInteger;
import java.util.StringTokenizer;

public class Main {
    static int N, M;
    static BigInteger[][] combination;
    public static void main(String[] args) throws IOException {
        logic();
        combination = new BigInteger[N+1][M+1];

        for(int i = 1; i <= N; i++) {
            for(int j = 0; j <= i && j <= M; j++) {
                if(j==0 || j==i) combination[i][j] = new BigInteger("1");
                else combination[i][j] = combination[i-1][j-1].add(combination[i-1][j]);
            }
        }

        System.out.println(combination[N][M]);
    }

    private static void logic() throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());
    }
}