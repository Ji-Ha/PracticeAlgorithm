package coding_test;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
    static int N, M;
    static boolean[] used;
    static int[] answer;
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());
        used = new boolean[N + 1];
        answer = new int[M];

        DFS(0);
    }

    public static void DFS(int depth) {
        if(depth == M) {
            for(int i = 0; i < M; i++)
                System.out.print(answer[i] + " ");
            System.out.println();
            return ;
        }

        for(int i = 1; i <= N; i++) {
            if(used[i]) continue;
            used[i] = true;
            answer[depth] = i;
            DFS(depth + 1);
            used[i] = false;
        }
    }
}