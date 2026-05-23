class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int>& A = nums1;
        vector<int>& B = nums2;
        int total = A.size() + B.size();
        int half = (total + 1) / 2;

        if (B.size() < A.size()) {
            swap(A, B);
        }

        int l = 0;
        int r = A.size();
        while (l <= r) {
            int i = (l + r) / 2;
            int j = half - i;

            int Aleft = i > 0 ? A[i - 1] : INT_MIN;
            int Aright = i < A.size() ? A[i] : INT_MAX;
            int Bleft = j > 0 ? B[j - 1] : INT_MIN;
            int Bright = j < B.size() ? B[j] : INT_MAX;

            if (Aleft <= Bright && Bleft <= Aright) {
                if (total % 2 != 0) {
                    return max(Aleft, Bleft);
                }
                return (max(Aleft, Bleft) + min(Aright, Bright)) / 2.0;
            } else if (Aleft > Bright) {
                r = i - 1;
            } else {
                l = i + 1;
            }
        }
        return -1;
    }
};

/*
Given two sorted arrays, we binary search for the correct place to cut both arrays simultaneously. 
Everything on the left of both cuts will make up the left partiion and everything on the right of
the cuts will make up the right partition. Only the smaller array needs to be binary searched because
the second array's cut position can be found by subtracting the first array's cut from the desired 
half-size.Once the correct boundaries are found where no left boundary exceeds any right boundary,
return the largest left boundary for odd totals, or the average of the largest left and smallest right
boundary for even totals. 
*/