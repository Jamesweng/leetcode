class Solution {
private:
    double binSearch(vector<int>& nums1, vector<int>& nums2, bool& found) {
        found = false;
        int expected_rank = (nums1.size() + nums2.size()) / 2;
        int odd = ((nums1.size() + nums2.size()) % 2 == 0) ? 0 : 1;
        if (!odd) {
            expected_rank--;
        }
        
        if (nums2.size() == 0) {
            found = true;
            if (odd) {
                return nums1[nums1.size() / 2] * 1.0;
            } else {
                return (nums1[nums1.size() / 2 - 1] + nums1[nums1.size() / 2]) * 0.5;
            }
        }
        
        int low = 0, high = nums1.size() - 1;
        while (low <= high) {
            int mid = (low + high) / 2;
            
            int guess = nums1[mid];
            if (mid > expected_rank) {
                high = mid - 1;
            } else {
                int gap = expected_rank - mid;  // 1=1-0
                
                if (gap > nums2.size()) {
                    low = mid + 1;
                } else if (gap == nums2.size()) {
                    if (nums2[gap - 1] > guess) {
                        low = mid + 1;
                    } else {
                        found = true;
                        if (odd) {
                            return guess * 1.0;
                        } else {
                            return (guess + nums1[mid + 1]) * 0.5;
                        }
                    }
                } else {
                    if (gap > 0 && nums2[gap - 1] > guess) {
                        low = mid + 1;
                    } else if (gap > 0 && nums2[gap - 1] <= guess) {
                        if (gap < nums2.size() && nums2[gap] >= guess || gap == nums2.size()) {
                            found = true;
                            if (odd) {
                                return guess * 1.0;
                            } else {
                                
                                if (mid + 1 < nums1.size() && nums1[mid + 1] < nums2[gap]) {
                                    return (guess + nums1[mid + 1]) * 0.5;
                                    
                                } else {
                                    return (guess + nums2[gap]) * 0.5;
                                    
                                }
                            }
                        } else {
                            high = mid - 1;
                        }
                    } else {
                         if (nums2[gap] >= guess) {
                            found = true;
                            if (odd) {
                                return guess * 1.0;
                            } else {
                                if (mid + 1 < nums1.size() && nums1[mid + 1] < nums2[gap]) {
                                    return (guess + nums1[mid + 1]) * 0.5;
                                } else {
                                    
                                return (guess + nums2[gap]) * 0.5;
                                }
                            }
                        } else {
                            high = mid - 1;
                        }
                    }
                }
            }
        }
        
        return 0;
    }
    
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        bool found = false;
        double ans = binSearch(nums1, nums2, found);
        if (!found) {
            ans = binSearch(nums2, nums1, found);
        }
        
        return ans;
    }
};
