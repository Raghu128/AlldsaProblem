class Solution {
public:
    bool isCircularSentence(string sentence) {
        int n = sentence.size();

        for(int i = 0; i < n; i++) {
            if(sentence[i] == ' ') {
                if(sentence[i-1] != sentence[i+1]) return false;
            }
        }
        if(sentence[0] != sentence[n-1]) return false;
        return true;
    }
};