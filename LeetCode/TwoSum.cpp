class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> answer;
        int left = 0;
        int right = nums.size() - 1;
        vector<pair<int, int>> copy;
        for (int pos = 0; pos < nums.size(); pos++) {
            copy.push_back({nums[pos], pos});
        }
        sort(copy.begin(), copy.end());
        while (left < right) {
            int sum = copy[left].first + copy[right].first;
            if (sum == target) {
                answer.push_back(copy[left].second);
                answer.push_back(copy[right].second);
                if (answer[0] > answer[1]) swap(answer[0], answer[1]);
                break;
            } else {
                if (sum > target) right--;
                else left++;
            }
        }
        return answer;
    }
};