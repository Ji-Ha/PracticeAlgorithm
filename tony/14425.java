package coding_test;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;
import java.util.TreeMap;

public class Main{
    static TreeMap<String, Integer> map = new TreeMap<>();
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static int N, M, answer = 0;

    public static void main(String[] args) throws IOException {
        input();
        logic();
        System.out.println(answer);
    }

    private static void logic() throws IOException {
        for(int i = 0; i < M; i++) {
            if(map.containsKey(br.readLine())) answer++;
        }
    }

    private static void input() throws IOException {
        StringTokenizer st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());

        for(int i = 0; i < N; i++) map.put(br.readLine(), 1);
    }
}