package coding_test;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Comparator;
import java.util.PriorityQueue;

public class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringBuilder sb = new StringBuilder();
    static int N;
    static PriorityQueue<Integer> heap = new PriorityQueue<>(Comparator.reverseOrder());

    public static void main(String[] args) throws IOException {
        input();
        logic();
        System.out.println(sb);
    }
    private static void input() throws IOException {
        N = Integer.parseInt(br.readLine());
    }

    private static void logic() throws IOException {
        for(int i = 0; i < N; i++) {
            int now = Integer.parseInt(br.readLine());
            if(now == 0) {
                if(heap.isEmpty()) sb.append("0").append("\n");
                else sb.append(heap.poll()).append("\n");
            }
            else heap.add(now);
        }
    }
}