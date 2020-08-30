class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> numbers;
        for (int i = 0; i < nums1.size(); i++) numbers.push_back(nums1[i]);
        for (int i = 0; i < nums2.size(); i++) numbers.push_back(nums2[i]);
        sort(numbers.begin(), numbers.end());
        int size = numbers.size();
        double result = (double) numbers[size / 2];
        if (size % 2 == 0) {
            result = (result + numbers[size / 2 - 1]) / 2.0;
        }
        return result;
    }
};