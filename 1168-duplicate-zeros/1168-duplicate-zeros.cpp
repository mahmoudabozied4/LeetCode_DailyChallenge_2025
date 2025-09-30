class Solution {
public:
    void duplicateZeros(vector<int>& arr) {
        int zeros = 0, n = arr.size();
        for (int i = 0; i < n; ++i)
            if (arr[i] == 0)
                ++zeros;
        for (int i = n - 1; i >= 0; --i) {
            if (i + zeros < n)
                arr[i + zeros] = arr[i];
            if (arr[i] == 0) {
                --zeros;
                if (i + zeros < n)
                    arr[i + zeros] = 0;
            }
        }
    }
};
