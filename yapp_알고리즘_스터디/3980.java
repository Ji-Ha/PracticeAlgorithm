package coding_test;


import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

// 왜 브루트포스로 했나요?
// 주어지는 데이터의 양이 적어서 브루트 포스로 해도 가능하다 생각.

public class Main {
    static final int PLAYER_NUMBER = 11;
    static int[][] players;
    static boolean[] check;
    static int answer;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;
        int C = Integer.parseInt(br.readLine());

        while(C-- > 0) {
            players = new int[PLAYER_NUMBER][PLAYER_NUMBER];
            check = new boolean[PLAYER_NUMBER];
            answer = Integer.MIN_VALUE;

            for(int i = 0; i < PLAYER_NUMBER; i++) {
                st = new StringTokenizer(br.readLine());
                for(int j = 0; j < PLAYER_NUMBER; j++)
                    players[i][j] = Integer.parseInt(st.nextToken());
            }

            ferguson(0, 0);
            System.out.println(answer);
        }
    }

    //백트래킹
    public static void ferguson(int position, int points) {
        if(position == PLAYER_NUMBER)
            answer = Math.max(answer, points);

        for(int i = 0; i < PLAYER_NUMBER; i++) {
            if(!check[i] && players[i][position] != 0) {
                check[i] = true;
                ferguson(position + 1, points + players[i][position]);
                check[i] = false;
            }
        }
    }
}