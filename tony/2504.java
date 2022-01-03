package coding_test;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayDeque;
import java.util.Deque;

public class Main {
    public static String line;
    public static int answer = 0;
    public static Deque<Character> d = new ArrayDeque<>();

    public static void main(String[] args) throws IOException {
        input();
        logic();
        System.out.println(!d.isEmpty() ? 0 : answer);
    }

    private static void input() throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        line = br.readLine();
    }

    private static void logic() {
        int temp = 1;
        for(int i = 0; i < line.length(); i++) {
            switch (line.charAt(i)) {
                case '(':
                    d.addFirst('(');
                    temp *= 2;
                    break;
                case '[':
                    d.addFirst('[');
                    temp *= 3;
                    break;
                case ')':
                    if(d.isEmpty() || d.peekFirst() != '(') {
                        answer = 0;
                        return;
                    }
                    if(line.charAt(i-1) == '(') answer += temp;
                    d.pollFirst();
                    temp /= 2;
                    break;
                case ']':
                    if(d.isEmpty() || d.peekFirst() != '[') {
                        answer = 0;
                        return ;
                    }
                    if(line.charAt(i-1) == '[') answer += temp;
                    d.pollFirst();
                    temp /= 3;
                    break;
            }
        }
    }
}