// class Solution {
// public:

// int commonPrefixLength(const string& str1, const string& str2) {

//       int length = 0;
//     while (length < str1.size() && length < str2.size() && str1[length] == str2[length]) {
//         length++;
//     }
//     return length;
// }

//     int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {

//         vector<string> combined;

//         for (auto num1 : arr1) {
//             combined.push_back(to_string(num1));
//         }
//         for (auto num2 : arr2) {
//             combined.push_back(to_string(num2));
//         }

//         sort(combined.begin(), combined.end());

//         int maxprefixlen = 0;

//         for (int i = 1; i < combined.size(); i++) {
//             int prefixLength = commonPrefixLength(combined[i - 1], combined[i]);
//         maxprefixlen= max(maxprefixlen, prefixLength);
//     }

//     return maxprefixlen ;

        
//     }
// };

class Solution {
public:

    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {

        unordered_set<string> st;

        // store all prefixes of arr1
        for (int num : arr1) {

            string s = to_string(num);

            string prefix = "";

            for (char ch : s) {
                prefix += ch;
                st.insert(prefix);
            }
        }

        int ans = 0;

        // check prefixes in arr2
        for (int num : arr2) {

            string s = to_string(num);

            string prefix = "";

            for (char ch : s) {

                prefix += ch;

                if (st.count(prefix)) {
                    ans = max(ans, (int)prefix.size());
                }
            }
        }

        return ans;
    }
};