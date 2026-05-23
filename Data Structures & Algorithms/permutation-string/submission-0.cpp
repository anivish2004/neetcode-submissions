class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.size() > s2.size()){
            return false;
        }
        vector<int> freq1(26,0), freq2(26,0);
        for(char c : s1){
            freq1[c - 'a']++;
        }
        int left = 0;
        for(int right=0;right<s2.size();right++){
            freq2[s2[right]-'a']++;
            if(right-left+1>s1.size()){
                freq2[s2[left]-'a']--;
                left++;
            }
            if(freq1 == freq2){
                return true;
            }
        }
        return false;
    }
};
