class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if(nums1.size() > nums2.size())
            return findMedianSortedArrays(nums2, nums1);
        
        int m = nums1.size(), n = nums2.size(), mid1, mid2, actual_mid = (m+n+1)/2, l=0, h=nums1.size();
        
        while(l<=h)
        {
            mid1 = (h+l)/2;
            mid2 = actual_mid-mid1;
            
            int leftA, rightA, leftB, rightB;
            leftA = mid1>0? nums1[mid1-1]:INT_MIN;
            rightA = mid1<m? nums1[mid1]:INT_MAX;
            
            leftB =mid2>0? nums2[mid2-1]:INT_MIN;
            rightB = mid2<n? nums2[mid2]:INT_MAX;
            
            if(leftA<=rightB && leftB<=rightA)
            {
                if((m+n)%2==0)
                {
                    // cout<<" from here"<<max(leftA, leftB)<<" "<<min(rightA, rightB);
                    return (max(leftA, leftB) + min(rightA, rightB))/2.0;
                }
                return max(leftA, leftB);
            }
            
            else if(leftA>rightB)
                h = mid1-1;
            
            else
                l = mid1+1;
                
        }
        return 0.0;
            
    }
};