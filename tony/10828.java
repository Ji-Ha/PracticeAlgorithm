package coding_test;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.StringTokenizer;

public class Main {
    static int N;
    static LinkedList<String> s = new LinkedList<>();

    public static void main(String[] args) throws IOException {
        input();
    }

    private static void input() throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        N = Integer.parseInt(br.readLine());

        for(int i = 0; i < N; i++) logic(br.readLine());
    }

    private static void logic(String line) {
        StringTokenizer st;
        st = new StringTokenizer(line);

        switch(st.nextToken()) {
            case "push":
                String num = st.nextToken();
                s.push(num);
                break;
            case "pop":
                if(s.isEmpty()) System.out.println("-1");
                else System.out.println(s.pop());
                break;
            case "size":
                System.out.println(s.size());
                break;
            case "empty":
                System.out.println(s.isEmpty() ? 1 : 0);
                break;
            case "top":
                if(s.isEmpty()) System.out.println("-1");
                else System.out.println(s.peek());
                break;
        }
    }
}