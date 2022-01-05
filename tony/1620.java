package coding_test;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.HashMap;
import java.util.StringTokenizer;

public class Main {
    static int N, M;
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringBuilder sb = new StringBuilder();
    static HashMap<Integer, String> numberEncyclopedia = new HashMap<>();
    static HashMap<String, Integer> nameEncyclopedia = new HashMap<>();

    public static void main(String[] args) throws IOException {
        input();
        logic();
        System.out.println(sb);
    }

    private static void logic() throws IOException {
        for(int i = 0; i < M; i++) {
            String problem = br.readLine();
            if(nameEncyclopedia.containsKey(problem)) {
                sb.append(nameEncyclopedia.get(problem)).append("\n");
                continue;
            }
            int number = Integer.parseInt(problem);
            if(numberEncyclopedia.containsKey(number)) sb.append(numberEncyclopedia.get(number)).append("\n");
        }
    }

    private static void input() throws IOException {
        StringTokenizer st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());

        for(int i = 1; i <= N; i++) {
            String now = br.readLine();
            numberEncyclopedia.put(i, now);
            nameEncyclopedia.put(now, i);
        }

    }
}