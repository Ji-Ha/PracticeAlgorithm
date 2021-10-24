package coding_test;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
    public static int H, W;
    public static int[] blocks;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        H = Integer.parseInt(st.nextToken());
        W = Integer.parseInt(st.nextToken());
        blocks = new int[W];

        st = new StringTokenizer(br.readLine());
        for(int i = 0; i < W; i++)
            blocks[i] = Integer.parseInt(st.nextToken());

        // 왼쪽 오른쪽에서 제일 큰 친구들을 찾는다.
        // 그 후에 그 중 작은 친구를 찾아서 현재 위치에 있는 블럭 크기만큼 빼서 값을 구한다.
        int sum = 0;
        for(int i = 0; i < W; i++) {
            int left = i;
            int right = i;
            for(int l = i; l >= 0; l--) {
                if(blocks[l] > blocks[left]) left = l;
            }
            for(int r = i; r < W; r++) {
                if(blocks[r] > blocks[right]) right = r;
            }

            int size = Math.min(blocks[left], blocks[right]) - blocks[i];
            if(size > 0) sum += size;
        }
        System.out.println(sum);
    }
}