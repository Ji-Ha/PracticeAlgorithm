package coding_test;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayDeque;
import java.util.Deque;
import java.util.StringTokenizer;

public class Main {
    static Deque<Balloon> d = new ArrayDeque<>();
    static StringBuilder sb = new StringBuilder();

    public static void main(String[] args) throws IOException {
        input();
        logic();
        System.out.println(sb);
    }

    private static void logic() {
        while(true) {
            Balloon now = d.pollFirst();
            sb.append(now.order).append(" ");
            if(d.isEmpty()) break;

            if(now.value > 0) {
                for(int i = 0; i < now.value-1; i++)
                    d.addLast(d.pollFirst());
            }
            else {
                for(int i = 0; i < Math.abs(now.value); i++)
                    d.addFirst(d.pollLast());
            }
        }
    }

    private static void input() throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        StringTokenizer st = new StringTokenizer(br.readLine());

        for(int i = 1; i <= n; i++)
            d.addLast(new Balloon(i, Integer.parseInt(st.nextToken())));
    }
}

class Balloon {
    int order;
    int value;

    Balloon(int order, int value) {
        this.order = order;
        this.value = value;
    }
}