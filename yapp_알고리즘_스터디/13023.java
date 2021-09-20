package coding_test;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;

public class Main {
    static int N, M, ans;
    static List<Integer>[] friends;
    static boolean[] visited;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());

        friends = new ArrayList[N];
        visited = new boolean[N];

        for(int i = 0; i < N; i++)
            friends[i] = new ArrayList<>();

        for(int i = 0; i < M; i++) {
            st = new StringTokenizer(br.readLine());
            int a = Integer.parseInt(st.nextToken());
            int b = Integer.parseInt(st.nextToken());

            friends[a].add(b);
            friends[b].add(a);
        }
        // 입력 끝!

        // 5명의 친구가 되는지 찾기.
        for(int i = 0; i < N; i++) {
            if(ans == 0)
                DFS(i, 1);
        }

        System.out.println(ans);
    }

    // depth가 5가 되면 끝난다.
    //
    public static void DFS(int start, int depth) {
        if(depth == 5) {
            ans = 1;
            return ;
        }

        visited[start] = true;
        for(int i : friends[start]) {
            int next = i;
            if(!visited[next])
                DFS(next, depth + 1);
        }
        visited[start] = false;
    }
}