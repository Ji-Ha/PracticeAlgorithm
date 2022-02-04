package coding_test;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
    static int C, N;
    static City[] cities;
    static int[] dp;

    public static void main(String[] args) throws IOException {
        input();
        logic();
    }

    private static void logic() {
        for(int i = 1; i <= 100001; i++) {
            for(int j = 0; j < N; j++) {
                if(cities[j].getCost() <= i)
                    dp[i] = Math.max(dp[i], dp[i-cities[j].getCost()] + cities[j].getCitizen());
            }
            if(dp[i] >= C) {
                System.out.println(i);
                break;
            }
        }
    }

    private static void input() throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        C = Integer.parseInt(st.nextToken());
        N = Integer.parseInt(st.nextToken());
        dp = new int[100010];
        cities = new City[30];

        int cost, citizen;
        for(int i = 0; i < N; i++) {
            st = new StringTokenizer(br.readLine());
            cost = Integer.parseInt(st.nextToken());
            citizen = Integer.parseInt(st.nextToken());
            cities[i] = new City(cost, citizen);
        }

    }
}

class City {
    private int cost;
    private int citizen;

    City(int cost, int citizen) {
        this.cost = cost;
        this.citizen = citizen;
    }

    int getCost() {
        return cost;
    }

    int getCitizen() {
        return citizen;
    }
}