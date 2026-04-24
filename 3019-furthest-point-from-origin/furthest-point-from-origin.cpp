class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        int n = moves.size();

        int left=0;
        int right=0;
        int dash=0;
        int ans=0;

        for(int i=0;i<n;i++){
            if(moves[i]=='L') left++;
            else if( moves[i]=='R') right++;
            else{
                dash++;
            }
            ans= abs(left-right) + dash;
        }

        

        return  ans;
        
    }
};