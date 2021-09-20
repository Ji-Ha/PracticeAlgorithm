class Solution {
    static int answer;
    public int solution(int[] numbers, int target) {
        DFS(numbers, 0, 0, target);
        return answer;
    }

    void DFS(int[] nums, int p, int sum, int target) {
        if(p == nums.length) {
            if(sum == target)
                answer += 1;
            return ;
        }

        DFS(nums, p + 1, sum + nums[p], target);
        DFS(nums, p + 1, sum - nums[p], target);
    }
}