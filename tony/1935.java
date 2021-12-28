package coding_test;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Stack;
import java.util.regex.Pattern;

public class Main {
    static int N;
    static String expression;
    static double[] numbers;

    public static void main(String[] args) throws IOException {
        logic();
    }

    private static void logic() throws IOException {
        input();
        Stack<Double> s = new Stack<>();

        for(int i = 0; i < expression.length(); i++) {
            char now = expression.charAt(i);
            if('A' <= now && now <= 'Z') s.push(numbers[now - 'A']);
            else {
                double second = s.pop();
                double first = s.pop();

                if(now == '+') s.push(first + second);
                if(now == '-') s.push(first - second);
                if(now == '*') s.push(first * second);
                if(now == '/') s.push(first / second);
            }
        }
        System.out.printf("%.2f", s.peek());
    }

    private static void input() throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        N = Integer.parseInt(br.readLine());
        numbers = new double[N];

        expression = br.readLine();

        for(int i = 0; i < N; i++) numbers[i] = Integer.parseInt(br.readLine());
    }
}