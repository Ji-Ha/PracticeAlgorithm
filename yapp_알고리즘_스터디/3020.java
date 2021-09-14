package coding_test;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

// 처음엔 누적합을 for문을 사용해서 구했음 --> 시간초과
// 누적합을 통한 시간복잡도 최소화.
public class Main {
    static int N, H, count, answer = Integer.MAX_VALUE; // 길이, 높이
    static int[] gmites, ctites; // 누적합, 석순, 종유석
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        H = Integer.parseInt(st.nextToken());

        gmites = new int[H + 1];
        ctites = new int[H + 1];

        for(int i = 0; i < N/2; i++) {
            gmites[Integer.parseInt(br.readLine())] += 1;
            ctites[Integer.parseInt(br.readLine())] += 1;
        }

        // 누적 장애물들의 합.
        for(int i = 1; i <= H; i++) {
            gmites[i] = gmites[i - 1] + gmites[i];
            ctites[i] = ctites[i - 1] + ctites[i];
        }

        for(int i = 1; i <= H; i++) {
            int obstacle = 0; // 높이가 i일 때, 장애물들의 합
            obstacle += (gmites[H] - gmites[i - 1]); // 석순 장애물
            obstacle += (ctites[H] - ctites[H - i]); // 종유석 장애물

            if(answer > obstacle) {
                answer = obstacle;
                count = 1;
            }
            else if(obstacle == answer) count++;
        }

        System.out.println(answer + " " + count);
    }
}