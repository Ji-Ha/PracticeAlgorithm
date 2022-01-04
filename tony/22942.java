package coding_test;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main {
    static int N;
    static ArrayList<Circle> circles = new ArrayList<>();
    static Deque<Circle> stack = new ArrayDeque<>();

    public static void main(String[] args) throws IOException {
        input();
        logic();
    }

    private static void logic() {
        for(Circle circle : circles) {
            while(!stack.isEmpty() && stack.peekFirst().right < circle.left) {
                stack.pop();
            }
            if(!stack.isEmpty() && circle.left <= stack.peekFirst().right && stack.peekFirst().right <= circle.right) {
                System.out.println("NO");
                return;
            }
            stack.push(circle);
        }
        System.out.println("YES");
        return;
    }

    private static void input() throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;

        N = Integer.parseInt(br.readLine());

        for(int i = 0; i < N; i++) {
            st = new StringTokenizer(br.readLine());
            int center = Integer.parseInt(st.nextToken());
            int radius = Integer.parseInt(st.nextToken());
            circles.add(new Circle(center-radius, center+radius));
        }

        Collections.sort(circles);
    }
}

class Circle implements Comparable{
    int left;
    int right;

    Circle(int left, int right) {
        this.left = left;
        this.right = right;
    }

    @Override
    public int compareTo(Object o) {
        Circle o1 = (Circle) o;
        return this.left < o1.left? -1 : 1;
    }
}