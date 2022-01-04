package coding_test;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayDeque;
import java.util.Deque;
import java.util.StringTokenizer;

public class Main {
    static Point[] tops;
    static int[] answer;
    static int N;
    static Deque<Point> stack = new ArrayDeque<>();

    public static void main(String[] args) throws IOException {
        input();
        logic();
        output();
    }

    private static void output() {
        StringBuilder sb = new StringBuilder();
        for(int i = 0; i < N; i++)
            sb.append(answer[i]).append(" ");
        System.out.println(sb);
    }

    private static void logic() {
        stack.push(tops[N-1]);
        int now;

        for(int i = N-2; i >= 0; i--) {
            now = tops[i].value;
            while(!stack.isEmpty() && stack.peekFirst().value <= now) {
                Point p = stack.pollFirst();
                answer[p.location] = i + 1;
            }
            stack.push(tops[i]);
        }
    }

    private static void input() throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;
        N = Integer.parseInt(br.readLine());
        tops = new Point[N];
        answer = new int[N];

        st = new StringTokenizer(br.readLine());
        for(int i = 0; i < N; i++)
            tops[i] = new Point(i, Integer.parseInt(st.nextToken()));
    }
}

class Point{
    int location;
    int value;
    Point(int location, int value) {
        this.location = location;
        this.value = value;
    }
}