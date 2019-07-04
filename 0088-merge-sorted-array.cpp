class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int j = 0;
        for (int i = 0; i < n; ) {
            int b = nums2[i];
            //printf("i=%d, b=%d,j=%d\n", i,b,j);
            if (j >= m) {
                nums1[j++] = b;
                ++i;
            } else { 
                int a = nums1[j];
                if (a <= b) {
                    ++j;
                } else {
                    nums1[j++] = b;
                    nums2[i] = a;
                    for (int k = i; k + 1 < nums2.size() && nums2[k] > nums2[k + 1]; ++k) {
                        swap(nums2[k], nums2[k + 1]);
                    }
                }
            }
        }
    }
};
