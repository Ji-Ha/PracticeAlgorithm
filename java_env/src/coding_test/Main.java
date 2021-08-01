package coding_test;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {
    static int N, K;
    static int ans = 0;
    static int[] students;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int limit;

        N = Integer.parseInt(st.nextToken());
        K = Integer.parseInt(st.nextToken());
        students = new int[N];
        limit = (int) Math.ceil((double) N / K);

        st = new StringTokenizer(br.readLine());
        for(int i = 0; i < N; i++)
            students[i] = Integer.parseInt(st.nextToken());
        Arrays.sort(students);

        for(int i = 0; i < N; i += limit) {
            int end = (limit - 1);
            if(end + i >= N) {
                ans += students[N - 1] - students[i];
                break;
            }
            ans += students[end + i] - students[i];
        }
        System.out.println(ans);
    }
}