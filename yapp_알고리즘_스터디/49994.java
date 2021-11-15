class Solution {
    public int solution(String dirs) {
        int answer = 0;
        int x = 5;
        int y = 5;
        int nx = 5;
        int ny = 5;
        boolean[][][][] visited = new boolean[11][11][11][11];

        for(char next : dirs.toCharArray()) {
            x = nx;
            y = ny;
            if(next == 'U') ny--;
            else if(next == 'D') ny++;
            else if(next == 'L') nx--;
            else nx++;

            if(!boundCheck(nx, ny)) {
                nx = x;
                ny = y;
                continue;
            }

            if(!visited[x][y][nx][ny]) {
                visited[x][y][nx][ny] = true;
                visited[nx][ny][x][y] = true;
                answer++;
            }
        }
        return answer;
    }

    private boolean boundCheck(int x, int y) {
        if(x < 0 || y < 0 || x > 10 || y > 10) return false;
        return true;
    }
}