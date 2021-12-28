package coding_test;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;

public class Main {
    static int N;
    static Queue<Integer> q = new LinkedList<>();

    public static void main(String[] args) throws IOException {
        logic();
    }

    private static void logic() throws IOException {
        input();
        for(int i = 1; i <= N; i++) q.offer(i);

        while(q.size() > 1) {
            q.poll();
            q.add(q.poll());
        }

        System.out.println(q.peek());
    }

    private static void input() throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        N = Integer.parseInt(br.readLine());
    }
}