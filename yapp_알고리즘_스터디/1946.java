package coding_test;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
    static int[] applicants;
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;
        int t = Integer.parseInt(br.readLine());

        while(t-- > 0) {
            int n = Integer.parseInt(br.readLine());
            applicants = new int[n + 1];
            for(int i = 0; i < n; i++) {
                st = new StringTokenizer(br.readLine());
                applicants[Integer.parseInt(st.nextToken())] = Integer.parseInt(st.nextToken());
            }

            int count = 1;
            int standard = applicants[1];

            for(int j = 2; j <= n; j++) {
                if(standard > applicants[j]) {
                    count++;
                    standard = applicants[j];
                }
            }
            System.out.println(count);
        }
    }
}