/*  
  First Solution
   Time Complexity : O(n)
   Space complexity :O(1)
*/

class Solution {
public:
    
    int maxofallnegative(vector<int> &nums)
    {
        int maxnum=INT_MIN;
        for(int i=0; i<nums.size(); i++)
        {
            if(nums[i]>maxnum)
                maxnum=nums[i];
        }
        return maxnum;
    }
    int maxSubArray(vector<int>& nums) 
    {
        int flag=0;
        for(auto x :nums)
        {
            if(x >0)
                flag++;
        }
        if(flag==0)
        {
            return maxofallnegative(nums);
        }
        else
        {
        int maxsum=INT_MIN;
        int currsum=0;
        for(int i=0; i<nums.size(); i++)
        {
            currsum += nums[i];
          //  cout<<"currsum = "<<currsum<<endl;
            if(currsum <0)
            {
                currsum=0;
            }
            if(currsum > maxsum)
                maxsum=currsum;
           // cout<<"maxsum = "<<maxsum<<endl;
              
        }
        return maxsum;
        }
    }
};


/*
    Second Solution
    Time Complexity : O(n)
    Space Complexity : O(1)
*/

class Solution {
public:
    int maxSubArray(vector<int>& nums) 
    {
        int currsum=nums[0];
        int maxsum=nums[0];
        
        for(int i=1; i<nums.size(); i++)
        {
            currsum =max(nums[i], currsum+nums[i]);
            maxsum = max(maxsum, currsum);
        }
        return maxsum;
    }
};

/*
   Third Solution uses Divide and Conquer approach
   Time Complexity : O(nlogn)
   Space COmplexity : O(1)
*/

class Solution {
public:
    
    int max(int a , int b)
    {
        return (a>b) ? a : b;
    }
        
    int max(int a, int b, int c)
    {
        return max(max(a,b),c); 
    }
       
    
    int crossarraysum(vector<int> & nums, int low, int mid, int high)
    {
        int leftsum=INT_MIN;
        int sum=0;
        for(int i=mid; i>=low; i--)
        {
            sum +=nums[i];
            if(sum>leftsum)
                leftsum=sum;
        }
        
        sum=0;
        int rightsum=INT_MIN;
        for(int i=mid+1; i<=high; i++)
        {
            sum+=nums[i];
            if(sum>rightsum)
                rightsum=sum;
        }
        
        return max(leftsum+rightsum, leftsum ,rightsum);
    }
    
    int helper(vector<int> &nums, int low, int high)
    {
        if(low == high)    //just one element
            return nums[low];
        
        int mid =low + (high -low)/2;
        return max(helper(nums, low, mid), 
                   helper(nums, mid+1, high),
                   crossarraysum(nums, low, mid, high));
    }
    int maxSubArray(vector<int>& nums)
    {
        int low=0;
        int high=nums.size()-1;
        return helper(nums, low, high);        
    }
};

/*
Time Complexity: maxSubArraySum() is a recursive method and time complexity can be expressed as following recurrence relation.
T(n) = 2T(n/2) + Θ(n)
The above recurrence is similar to Merge Sort and can be solved either using Recurrence Tree method or Master method. 
It falls in case II of Master Method and solution of the recurrence is Θ(nLogn).

The Kadane’s Algorithm for this problem takes O(n) time. 
Therefore the Kadane’s algorithm is better than the Divide and Conquer approach, but this problem can be considered as a good example to show power of Divide and Conquer.
The above simple approach where we divide the array in two halves, reduces the time complexity from O(n^2) to O(nLogn).
*/
