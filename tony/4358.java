package coding_test;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.text.DecimalFormat;
import java.util.Iterator;
import java.util.Map;
import java.util.TreeMap;

public class Main {
    static int all = 0;
    static TreeMap<String, Integer> trees = new TreeMap<>();
    static StringBuilder sb = new StringBuilder();

    public static void main(String[] args) throws IOException {
        input();
        logic();
        System.out.println(sb);
    }

    private static void input() throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String now;
        while(true) {
            now = br.readLine();
            if(now == null || now.equals("")) return ;
            if(trees.containsKey(now))
                trees.put(now, trees.get(now)+1);
            else
                trees.put(now, 1);
            all++;
        }
    }

    private static void logic() {
        Iterator<Map.Entry<String, Integer>> entries = trees.entrySet().iterator();
        while(entries.hasNext()) {
            Map.Entry<String, Integer> now = entries.next();
            String key = now.getKey();
            double value = now.getValue() / (double)all * 100;
            DecimalFormat df = new DecimalFormat("0.0000");

            sb.append(key + " ").append(df.format(value)).append("\n");
        }
    }
}