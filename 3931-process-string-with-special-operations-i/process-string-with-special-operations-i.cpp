class Solution {
public:
    string processStr(string s) {
        int n = s.size();

        string result;

        for (auto ch : s) {
            if (ch >= 'a' && ch <= 'z') {
                result.push_back(ch);
            }

            if (ch == '*') {
                if (!result.empty())
                    result.pop_back();
            } else if (ch == '#') {
                if (!result.empty())
                    result += result;
            }

            else if (ch == '%') {
                reverse(result.begin(), result.end());
            }
        }

        return result;
    }
};