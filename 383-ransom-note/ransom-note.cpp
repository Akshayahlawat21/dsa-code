class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {

        int n = ransomNote.size();
        int m  = magazine.size();

        unordered_map<char,int> mp;
        unordered_map<char,int> mtp;

        for(char ch : ransomNote){
             mp[ch]++;
        }
        for(char cht : magazine){
             mtp[cht]++;
        }
        
        
for(auto it : mp){

    char ch = it.first;
    int freq = it.second;

    if(mtp[ch] < freq){
        return false;
    }
}
        return true;
    }
};