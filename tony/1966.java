package coding_test;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringBuilder sb = new StringBuilder();
    static int N, M;
    static PriorityQueue<Point> pq;
    static Queue<Point> q;

    public static void main(String[] args) throws IOException {
        int t = Integer.parseInt(br.readLine());

        while(t-- > 0) {
            input();
            logic();
        }
        System.out.println(sb.toString());
    }

    private static void logic() throws IOException{
        int answer = 1;
        pq = new PriorityQueue<>(Collections.reverseOrder());
        q = new LinkedList<>();
        StringTokenizer st = new StringTokenizer(br.readLine());

        for(int i = 0; i < N; i++) {
            Point now = new Point(Integer.parseInt(st.nextToken()), false);
            if(i == M)
                now.target = true;

            pq.add(now);
            q.add(now);
        }

        while(!q.isEmpty()) {
            Point max = pq.peek();
            Point now = q.peek();

            if(now.important == max.important) {
                if(now.target) {
                    sb.append(answer).append("\n");
                    break;
                }
                answer++;
                pq.poll();
                q.poll();
            }
            else q.offer(q.poll());

        }
    }

    private static void input() throws IOException {
        StringTokenizer st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());
    }
}

class Point implements Comparable {
    int important;
    boolean target;

    Point(int important, boolean target) {
        this.important = important;
        this.target = target;
    }

    @Override
    public int compareTo(Object o) {
        Point p = (Point) o;
        return this.important > p.important ? 1 : -1;
    }
}