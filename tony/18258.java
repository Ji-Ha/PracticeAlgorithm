package coding_test;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Deque;
import java.util.LinkedList;
import java.util.StringTokenizer;

public class Main {
    static int N;
    static int backNumber;
    static Deque<Integer> queue = new LinkedList<>();

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;
        StringBuilder sb = new StringBuilder();
        N = Integer.parseInt(br.readLine());

        for(int i = 0; i < N; i++) {
            st = new StringTokenizer(br.readLine());
            String request = st.nextToken();

            switch (request) {
                case "push":
                    push(Integer.parseInt(st.nextToken()));
                    break;
                case "pop":
                    sb.append(pop()).append('\n');
                    break;
                case "size":
                    sb.append(size()).append('\n');
                    break;
                case "empty":
                    sb.append(isEmpty()).append('\n');
                    break;
                case "front":
                    sb.append(front()).append('\n');
                    break;
                case "back":
                    sb.append(back()).append('\n');
                    break;
            }
        }
        System.out.println(sb);
    }

    private static void push(int num) {
        backNumber = num;
        queue.addFirst(num);
    }

    private static int pop() {
        if(queue.isEmpty()) return -1;
        return queue.pollLast();
    }

    private static int size() {
        return queue.size();
    }

    private static int isEmpty() {
        if(queue.isEmpty()) return 1;
        return 0;
    }

    private static int front() {
        if(queue.isEmpty()) return -1;
        return queue.getLast();
    }

    private static int back() {
        if(queue.isEmpty()) return -1;
        return queue.getFirst();
    }
}