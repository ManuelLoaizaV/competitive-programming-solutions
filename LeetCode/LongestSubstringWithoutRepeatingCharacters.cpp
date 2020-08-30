class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        set<char> found;
        int left, right;
        left = right = 0;
        int result = 0;
        while (right < s.size()) {
            char current = s[right];
            if (found.count(current) > 0) {
                while (s[left] != current){
                    found.erase(s[left]);
                    left++;
                }
                left++;
            } else {
                found.insert(current);
            }
            int current_result = right - left + 1;
            result = max(result, current_result);
            right++;
        }
        return result;
    }
};