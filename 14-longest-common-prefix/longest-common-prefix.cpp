class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {

        int n = strs.size();

        string ans = "";

        for (int i = 0; i < strs[0].size();
             i++) { // ye  1 comple word pr chlega

            char ch = strs[0][i];

            for (int j = 1; j < n; j++) { // ye 2nd word se baki words pr chelga

                if (i >= strs[j].size() || strs[j][i] != ch) {
                    return ans;
                }
                
            }
              ans.push_back(ch);
        }
        return  ans;
    }
};