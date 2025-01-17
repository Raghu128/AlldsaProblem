class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {
        int n = derived.size();
        if(n == 1) return !derived[0];
        if(n == 2) return derived[0] == derived[1];

        vector<int> arr(n, 0);
        bool flag = true;
        for(int i = 0; i < n; i++) {
            int nxtIdx = (i+1)%n;
            int curr = arr[i];
            int wants = derived[i];

            if(nxtIdx == 0 && (curr ^ arr[0]) != wants) {
                flag = false;
                break;
            }
            else if(curr^1 == wants) arr[nxtIdx] = 1;
            else if(curr^0 == wants) arr[nxtIdx] = 0;
            else {
                flag = false;
                break;
            }
        }

        if(!flag) {
            arr[0] = 1;
            for(int i = 0; i < n; i++) {
                int nxtIdx = (i+1)%n;
                int curr = arr[i];
                int wants = derived[i];

                if(nxtIdx == 0 ) {
                    if( (curr ^ arr[0]) != wants) return false;
                    else return true;
                }

                if(curr^1 == wants) arr[nxtIdx] = 1;
                else if(curr^0 == wants) arr[nxtIdx] = 0;
                else {
                    return false;
                }

            }
        }
        
        return true;

    }
};