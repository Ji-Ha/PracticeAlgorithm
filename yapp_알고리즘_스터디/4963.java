package coding_test;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
    static int w, h, answer;
    static int[] dx = {0, 0, 1, -1, -1, 1, -1, 1};
    static int[] dy = {1, -1, 0, 0, 1, 1, -1, -1};
    static int[][] map;
    static boolean[][] visited;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        while((w = Integer.parseInt(st.nextToken())) != 0 && (h = Integer.parseInt(st.nextToken())) != 0) {
            answer = 0;
            map = new int[h][w];
            visited = new boolean[h][w];

            for(int i = 0; i < h; i++) {
                st = new StringTokenizer(br.readLine());
                for(int j = 0; j < w; j++)
                    map[i][j] = Integer.parseInt(st.nextToken());
            }

            for(int i = 0; i < h; i++) {
                for(int j = 0; j < w; j++) {
                    if(map[i][j] == 1 && !visited[i][j]) {
                        answer++;
                        DFS(i, j);
                    }
                }
            }

            System.out.println(answer);
            st = new StringTokenizer(br.readLine());
        }
    }

    public static void DFS(int i, int j) {
        visited[i][j] = true;
        for(int k = 0; k < 8; k++) {
            int nx = i + dx[k];
            int ny = j + dy[k];

            if(nx < 0 || ny < 0 || nx >= h || ny >= w) continue;
            if(map[nx][ny] == 1 && !visited[nx][ny]) DFS(nx, ny);
        }
    }
}