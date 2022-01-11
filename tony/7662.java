package coding_test;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;
import java.util.TreeMap;

public class Main {
    static TreeMap<Integer, Integer> numbers;
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringBuilder sb = new StringBuilder();

    public static void main(String[] args) throws IOException {
        int t = Integer.parseInt(br.readLine());

        for(int i = 0; i < t; i++) logic();
        System.out.println(sb);
    }

    private static void logic() throws IOException {
        numbers = new TreeMap<>();

        int k = Integer.parseInt(br.readLine());
        StringTokenizer st;
        for(int j = 0; j < k; j++) {
            st = new StringTokenizer(br.readLine());
            String option = st.nextToken();
            String number = st.nextToken();

            if(option.equals("I"))
                processI(Integer.parseInt(number));

            if(option.equals("D"))
                processD(Integer.parseInt(number));
        }
        if(numbers.isEmpty()) sb.append("EMPTY").append("\n");
        else sb.append(numbers.lastKey()).append(" ").append(numbers.firstKey()).append("\n");
    }

    private static void processI(int number) {
        numbers.put(number, numbers.getOrDefault(number, 0)+1);
    }

    private static void processD(int tag) {
        if(numbers.isEmpty()) return ;
        if(tag == 1) {
            int max = numbers.lastKey();
            if (numbers.get(max) == 1) numbers.remove(max);
            else if (numbers.get(max) > 1) numbers.put(max, numbers.get(max)-1);
        }

        if(tag == -1) {
            int min = numbers.firstKey();
            if (numbers.get(min) == 1) numbers.remove(min);
            else if (numbers.get(min) > 1) numbers.put(min, numbers.get(min)-1);
        }
    }
}