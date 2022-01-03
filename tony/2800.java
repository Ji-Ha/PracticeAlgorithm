package coding_test;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main{
    static String line;
    static Deque<Integer> stack = new ArrayDeque<>();
    static ArrayList<Bracket> brackets = new ArrayList<>();
    static TreeSet<String> answer = new TreeSet<>();
    static boolean[] visited;

    public static void main(String[] args) throws IOException {
        input();
        logic();
    }

    private static void logic() {
        StringBuilder sb = new StringBuilder();
        for(int i = 0; i < line.length(); i++) {
            char now = line.charAt(i);
            if(now == '(') stack.push(i);
            if(now == ')') brackets.add(new Bracket(stack.pop(), i));
        }
        visited = new boolean[line.length()];

        dfs(0);

        answer.remove(line);
        for(String s : answer) sb.append(s).append("\n");

        System.out.println(sb);
    }

    private static void dfs(int depth) {
        if(depth == brackets.size()) {
            StringBuilder sb = new StringBuilder();
            for(int i = 0; i < line.length(); i++) {
                if(!visited[i]) sb.append(line.charAt(i));
            }
            answer.add(sb.toString());
            return ;
        }

        Bracket now = brackets.get(depth);
        visited[now.start] = false;
        visited[now.end] = false;
        dfs(depth+1);
        visited[now.start] = true;
        visited[now.end] = true;
        dfs(depth+1);
    }

    private static void input() throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        line = br.readLine();
    }
}

class Bracket {
    int start;
    int end;
    Bracket(int start, int end) {
        this.start = start;
        this.end = end;
    }
}