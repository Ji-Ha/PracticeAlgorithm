package coding_test;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

// 투 포인터.
// 초반에 자료형 때문에 4번 정도 틀렸다.
// 입력받는 값을 저장하는 waters같은 경우는 그냥 int로 해도 되지 않나? 라는 생각이 계속 든다.

public class Main {
    static int N;
    static long answer = Long.MAX_VALUE;
    static long[] waters, aList = new long[3];

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;
        System.out.println(Integer.MAX_VALUE);
        N = Integer.parseInt(br.readLine());
        waters = new long[N];

        st = new StringTokenizer(br.readLine());
        for(int i = 0; i < N; i++)
            waters[i] = Integer.parseInt(st.nextToken());
        Arrays.sort(waters);

        for(int i = 0; i < N; i++) {
            long sum;
            int left = i + 1;
            int right = N - 1;

            while(left < right) {
                sum = waters[i] + waters[left] + waters[right];
                if(answer >= Math.abs(sum)) {
                    aList = new long[]{waters[i], waters[left], waters[right]};
                    answer = Math.abs(sum);
                }

                if(sum < 0) left += 1;
                else if(sum > 0) right -= 1;
                else
                    break;
            }
        }
        for(int i = 0; i < 3; i++)
            System.out.println(aList[i]);
    }
}