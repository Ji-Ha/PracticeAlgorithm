package coding_test;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

// 1. 빈칸이라면, 어떤 값이 들어가야하는지 찾는 함수를 만든다. 가로, 세로, 상자 확인
// 2. 넣었으면, 함수를 호출함 -> 재귀로.
// 3. 모든 수를 다 넣었다면 출력.

// ps. 다 돌렸으니 출력해! 에서는 원래 return ; 으로 끝내려하였지만, 문제에서 1개의 답만 원하였기 때문에 exit으로 바꾸었다.
// exit을 쓰면 안좋다고 생각하는데, 이를 개선할 방법이 일단은 떠오르지 않는다.

// 밥먹고 와서 고공.
public class Main {
    static int[][] board = new int[9][9]; // 보드 전체

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;

        for(int i = 0; i < 9; i++) {
            st = new StringTokenizer(br.readLine());
            for(int j = 0; j < 9; j++) board[i][j] = Integer.parseInt(st.nextToken());
        }

        fillBoard(0, 0);
    }

    public static void fillBoard(int x, int y) {
        if(y == 9) {
            fillBoard(x + 1, 0);
            return ;
        }

        if(x == 9) {
            // 다 돌았으니 출력해!
            for(int i = 0; i < 9; i++) {
                for(int j = 0; j < 9; j++)
                    System.out.print(board[i][j] + " ");
                System.out.println();
            }
            System.exit(0);
        }

        if(board[x][y] == 0) {
            for(int i = 1; i <= 9; i++) {
                if(check(x, y, i)) {
                    board[x][y] = i;
                    fillBoard(x, y + 1);
                }
            }
            board[x][y] = 0;
            return ;
        }

        fillBoard(x, y + 1);
    }

    public static boolean check(int x, int y, int value) {
        // 가로줄 확인.
        for(int i = 0; i < 9; i++)
            if(board[i][y] == value) return false;

        // 세로줄 확인.
        for(int i = 0; i < 9; i++)
            if(board[x][i] == value) return false;

        // 상자 확인.
        int boxX = (x/3) * 3;
        int boxY = (y/3) * 3;

        for(int i = boxX; i < boxX + 3; i++) {
            for(int j = boxY; j < boxY + 3; j++) {
                if(board[i][j] == value) return false;
            }
        }

        return true;
    }
}