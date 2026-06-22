class Solution {
public:
    int maxNumberOfBalloons(string text) {
        int n =text.size();

        unordered_map<char,int> mp;

        for(char ch : text){
            mp[ch]++;
        }
         unordered_map<char,int> mtp;
         mtp['b']=1;
         mtp['a']=1;
         mtp['l']=2;
         mtp['o']=2;
         mtp['n']=1;
        

         int ans = INT_MAX;

 for(auto it : mtp){

            char ch = it.first;

            int required = it.second;

            int available = mp[ch];

            ans = min(ans, available / required);
        }

        return ans;
    }
};