class Solution {
   public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if (hand.size() % groupSize != 0) return false;

        map<int, int> freq;
        for (int x : hand) freq[x]++;

        while (!freq.empty()) {
            int start = freq.begin()->first;

            for (int x = start; x < start + groupSize; x++) {
                if (freq.find(x) == freq.end()) return false;

                freq[x]--;
                if (freq[x] == 0) {
                    freq.erase(x);
                }
            }
        }

        return true;
    }
};
