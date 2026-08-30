// class Solution {
// public:
//     string shortestBeautifulSubstring(string s, int k) {

//         vector<string> ans;

//         // Generate all substrings
//         for (int i = 0; i < s.length(); i++) {

//             string temp = "";

//             for (int j = i; j < s.length(); j++) {

//                 temp += s[j];

//                 ans.push_back(temp);
//             }
//         }

//         // Keep only strings having exactly k ones
//         vector<string> result;

//         for (string str : ans) {

//             int count = 0;

//             for (char ch : str) {

//                 if (ch == '1') {
//                     count++;
//                 }
//             }

//             if (count == k) {
//                 result.push_back(str);
//             }
//         }

//         // No beautiful substring
//         if (result.empty()) {
//             return "";
//         }

//         // Find shortest, and if same length,
//         // lexicographically smallest
//         string smallest = result[0];

//         for (string str : result) {

//             if (str.length() < smallest.length()) {

//                 smallest = str;
//             }
//             else if (str.length() == smallest.length() && str < smallest) {

//                 smallest = str;
//             }
//         }

//         return smallest;
//     }
// };


class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {

        string smallest = "";

        for (int i = 0; i < s.length(); i++) {

            string temp = "";
            int count = 0;

            for (int j = i; j < s.length(); j++) {

                temp += s[j];

                if (s[j] == '1') {
                    count++;
                }

                if (count == k) {

                    if (smallest == "" ||
                        temp.length() < smallest.length() ||
                        (temp.length() == smallest.length() && temp < smallest)) {

                        smallest = temp;
                    }
                }
            }
        }

        return smallest;
    }
};