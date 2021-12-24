import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main {
    static int N, K;

    public static void main(String[] args) throws IOException {
        input();
        logic();
    }

    private static void input() throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        K = Integer.parseInt(st.nextToken());
    }

    private static void logic() {
        Queue<Integer> q = init();

        System.out.print("<");
        while(q.size() > 1) {
            for(int i = 0; i < K - 1; i++) q.offer(q.poll());
            System.out.print(q.poll() + ", ");
        }
        System.out.print(q.poll() + ">");
    }

    private static Queue<Integer> init() {
        Queue<Integer> q = new LinkedList<>();
        for(int i = 0; i < N; i++) q.offer(i+1);
        return q;
    }
}