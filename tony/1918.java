package coding_test;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayDeque;
import java.util.Deque;

public class Main {
    static String line;
    static Deque<Character> stack = new ArrayDeque<>();
    static StringBuilder sb = new StringBuilder();

    public static void main(String[] args) throws IOException {
        input();
        logic();
        System.out.println(sb);
    }

    private static void logic() {
        for (int i = 0; i < line.length(); i++) {
            char now = line.charAt(i);
            if (now >= 'A' && now <= 'Z') {
                sb.append(now);
                continue;
            }

            if(stack.isEmpty()) {
                stack.push(now);
                continue;
            }

            if (now == '(') stack.push(now);
            else if (now == ')') {
                while (!stack.isEmpty() && stack.peekFirst() != '(')
                    sb.append(stack.pop());
                stack.pop();
            }
            else if (now == '*' || now == '/') {
                while (!stack.isEmpty() && (stack.peekFirst() == '*' || stack.peekFirst() == '/'))
                    sb.append(stack.pop());
                stack.push(now);
            }
            else if (now == '+' || now == '-') {
                while (!stack.isEmpty() && stack.peekFirst() != '(')
                    sb.append(stack.pop());
                stack.push(now);
            }
        }
        while(!stack.isEmpty()) sb.append(stack.pop());
    }

    private static void input() throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        line = br.readLine();
    }
}