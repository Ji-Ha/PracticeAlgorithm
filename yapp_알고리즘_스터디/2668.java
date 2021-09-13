package coding_test;


import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;

public class Main {
    static int N, start;
    static int[] numbers;
    static boolean[] visited;
    static ArrayList<Integer> answer = new ArrayList<>();

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        N = Integer.parseInt(br.readLine());
        numbers = new int[N + 1];
        visited = new boolean[N + 1];

        for(int i = 1; i <= N; i++)
            numbers[i] = Integer.parseInt(br.readLine());


        for(int i = 1; i <= N; i++) {
            start = i;
            visited[i] = true;
            DFS(i);
            visited[i] = false;
        }
        Collections.sort(answer);

        System.out.println(answer.size());
        for(int ans : answer)
            System.out.println(ans);
    }

    // 싸이클을 만들수만 있으면 된다. 한 싸이클에 포함되는 모든 수를 구하기 보다는
    // for문을 돌면서 해당하는 수가 싸이클을 만들 수 있는 수인지, 그렇다면 포함되고 아니라면 넘어가는 식의 DFS
    public static void DFS(int now) {
        if(!visited[numbers[now]]) {
            visited[numbers[now]] = true;
            DFS(numbers[now]);
            visited[numbers[now]] = false;
        }
        if(start == numbers[now]) {
            answer.add(start);
        }
    }
}