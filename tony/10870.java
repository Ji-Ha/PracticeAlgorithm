package coding_test;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
    static int N;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        N = Integer.parseInt(br.readLine());
        System.out.println(logic(N));
    }

    private static int logic(int now) {
        if(now == 1) return 1;
        if(now == 0) return 0;
        return logic(now-1) + logic(now-2);
    }
}