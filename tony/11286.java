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
    static PriorityQueue<Number> heap = new PriorityQueue<>();

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
                else sb.append(heap.poll().value).append("\n");
            }
            else heap.add(new Number(now, Math.abs(now)));
        }
    }
}

class Number implements Comparable<Number> {
    int value;
    int abs;

    Number(int value, int abs) {
        this.value = value;
        this.abs = abs;
    }

    @Override
    public int compareTo(Number o) {
        if(this.abs == o.abs) return this.value >= o.value ? 1 : -1;
        return this.abs >= o.abs ? 1 : -1;
    }
}