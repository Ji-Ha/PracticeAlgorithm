package coding_test;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
    static int N;
    static long[] numbers = new long[91];

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        N = Integer.parseInt(br.readLine());
        numbers[0] = 0;
        numbers[1] = 1;
        System.out.println(logic(N));
    }

    private static long logic(int now) {
        if(now == 1) return 1;
        if(now == 0) return 0;
        if(numbers[now] != 0) return numbers[now];
        numbers[now] = logic(now-1) + logic(now-2);
        return numbers[now];
    }
}