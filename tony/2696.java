package coding_test;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Comparator;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

public class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringBuilder sb = new StringBuilder();

    public static void main(String[] args) throws IOException {
        int t = Integer.parseInt(br.readLine());

        for (int i = 0; i < t; i++)
            logic();

        System.out.println(sb);
    }

    private static void logic() throws IOException {
        PriorityQueue<Integer> left = new PriorityQueue<>(Comparator.reverseOrder());
        PriorityQueue<Integer> right = new PriorityQueue<>();
        StringTokenizer st = null;
        int N = Integer.parseInt(br.readLine());
        int count = 0;
        sb.append((N + 1) / 2).append("\n");

        for (int i = 0; i < N; i++) {
            if (i % 10 == 0) st = new StringTokenizer(br.readLine());

            int now = Integer.parseInt(st.nextToken());

            if (left.size() == right.size()) left.add(now);
            else right.add(now);

            if (!right.isEmpty()) {
                if (left.peek() > right.peek()) {
                    int temp1 = left.poll();
                    int temp2 = right.poll();

                    right.offer(temp1);
                    left.offer(temp2);
                }
            }

            if (i % 2 == 0) {
                if (count == 9 || i == N - 1) {
                    sb.append(left.peek()).append("\n");
                    count = 0;
                }
                else sb.append(left.peek()).append(" ");
                count++;
            }
        }
    }
}