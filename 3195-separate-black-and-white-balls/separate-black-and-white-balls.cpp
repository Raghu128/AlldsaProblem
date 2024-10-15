class Solution {
public:
    long long left(string s) {
        int n = s.size();
        int oneIdx = 0;
        int i = 0;
        while(i < n && s[i] != '1') i++;
        oneIdx = i;
        i++;

        long long swapCnt = 0;
        while(i < n) {
            if(s[i] == '0') {
                swap(s[i], s[oneIdx]);
                swapCnt += i - oneIdx;

                while(oneIdx <= i && s[oneIdx] != '1') oneIdx++;
                // oneIdx = i;
            }

            i++;
        }
        cout << s << endl;

        return swapCnt;
    }

    
    long long minimumSteps(string s) {
        long long l = left(s);

        return l;
    }
};