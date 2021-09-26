package coding_test;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

// 처음에 올라가고 내려가는 과정을 확인하는 방식을 for문으로 직접 확인하는 방식으로 하지 않아서 답을 찾을 수 없었음.

public class Main {
    static int N, L, answer = 0;
    static int[][] board;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        N = Integer.parseInt(st.nextToken());
        L = Integer.parseInt(st.nextToken());
        board = new int[N][N];

        for(int i = 0; i < N; i++) {
            st = new StringTokenizer(br.readLine());
            for(int j = 0; j < N; j++)
                board[i][j] = Integer.parseInt(st.nextToken());
        }

        for(int i = 0; i < N; i++) {
            if(check(i, false)) answer++;
            if(check(i, true)) answer++;
        }

        System.out.println(answer);
    }

    public static boolean check(int line, boolean vertical) {
        boolean[] visited = new boolean[N];
        int[] list;
        if(!vertical) list = board[line];
        else {

            list = new int[N];
            for(int i = 0; i < N; i++) list[i] = board[i][line];
        }

        for (int j = 0; j < N - 1; j++) {
            if (list[j] == list[j + 1]) continue; // 같으면 계속 가기.
            if (Math.abs(list[j] - list[j + 1]) > 1) return false; // 만약에 차이가 1보다 크다면 끝내야지.
            if (list[j] - list[j + 1] == -1) { // 이게 1 올라가는 것.
                for (int k = j; k > j - L; k--) {
                    if (k < 0 || list[j] != list[k] || visited[k]) return false;
                    visited[k] = true;
                }
            }
            else if (list[j] - list[j + 1] == 1) { //내려가는 것.
                for(int k = j + 1; k <= j + L; k++) {
                    if( k >= N || list[j + 1] != list[k] || visited[k]) return false;
                    visited[k] = true;
                }
            }
        }
        return true;
    }
}