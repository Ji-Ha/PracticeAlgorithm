package coding_test;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;

public class Main {
    static int N;
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    public static void main(String[] args) throws IOException {
        logic();
    }

    private static void logic() throws IOException {
        N = Integer.parseInt(input());
        for(int i = 0; i < N; i++) {
            if(checkVps(input())) System.out.println("YES");
            else System.out.println("NO");
        }
    }

    private static boolean checkVps(String line) {
        Queue<Character> q = new LinkedList<>();
        for(int i = 0; i < line.length(); i++) {
            if(line.charAt(i) == '(') q.add('(');
            else {
                if(q.isEmpty()) return false;
                else q.poll();
            }
        }
        return q.isEmpty();
    }

    private static String input() throws IOException {
        return br.readLine();
    }
}