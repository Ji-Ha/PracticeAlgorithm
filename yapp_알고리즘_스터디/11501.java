package coding_test;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;
        int t = Integer.parseInt(br.readLine());

        while(t-- > 0) {
            int n = Integer.parseInt(br.readLine());
            int[] stocks = new int[n + 1];
            int max = 0;
            long sum = 0;
            st = new StringTokenizer(br.readLine());

            for(int i = 0; i < n; i++) stocks[i] = Integer.parseInt(st.nextToken());

            for(int i = n - 1; i >= 0; i--) {
                if(stocks[i] > max)
                    max = stocks[i];
                else sum += max - stocks[i];
            }
            System.out.println(sum);
        }
    }
}