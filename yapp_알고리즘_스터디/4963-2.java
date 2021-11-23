package coding_test;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
    public static int[][] map;
    public static boolean[][] visited;
    static int W, H;
    static int[] dx = {-1, 0, 1, -1, 1, -1, 0, 1};
    static int[] dy = {-1, -1, -1, 0, 0, 1, 1, 1};

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;

        while(true) {
            int answer = 0;
            st = new StringTokenizer(br.readLine());
            H = Integer.parseInt(st.nextToken());
            W = Integer.parseInt(st.nextToken());

            if(W == 0 && H == 0) break;
            map = new int[W][H];
            visited = new boolean[W][H];

            for(int i = 0; i < W; i++) {
                st = new StringTokenizer(br.readLine());
                for(int j = 0; j < H; j++) map[i][j] = Integer.parseInt(st.nextToken());
            }

            for(int i = 0; i < W; i++) {
                for(int j = 0; j < H; j++) {
                    if(map[i][j] == 1 && !visited[i][j]) {
                        findIsland(i, j);
                        answer++;
                    }
                }
            }

            System.out.println(answer);
        }
    }

    private static void findIsland(int w, int h) {
        visited[w][h] = true;
        for(int i = 0; i < 8; i++) {
            int nx = w + dx[i];
            int ny = h + dy[i];

            if(canWeGo(nx, ny) && map[nx][ny] == 1 && !visited[nx][ny]) findIsland(nx, ny);
        }
    }

    private static boolean canWeGo(int w, int h) {
        if(w < 0 || w >= W || h < 0 || h >= H) return false;
        return true;
    }
}