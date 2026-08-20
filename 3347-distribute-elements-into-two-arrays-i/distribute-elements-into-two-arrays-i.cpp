class Solution {
public:
    vector<int> resultArray(vector<int>& nums) {

        int n = nums.size();

        vector<int> arr1;
        vector<int> arr2;

        arr1.push_back(nums[0]);
        arr2.push_back(nums[1]);

        // int i = 0;
        // int j =0 ;

        // for (int k = 2; k < n; k++) {
        //     if (arr1[i] > arr2[j]) {
        //         arr1.push_back(nums[k]);
        //         i++;
        //     }

        //     else {
        //         arr2.push_back(nums[k]);
        //         j++;
        //     }
        // }
        for (int k = 2; k < n; k++) {

            if (arr1.back() > arr2.back()) {
                arr1.push_back(nums[k]);
            } else {
                arr2.push_back(nums[k]);
            }
        }

        vector<int> ans;

        for (int x : arr1)
            ans.push_back(x);

        for (int x : arr2)
            ans.push_back(x);

        return ans;
    }
};