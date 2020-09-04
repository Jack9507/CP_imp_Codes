class Solution {
public:
    
    void helper(int si, vector<int> nums, vector<int> ans, vector<vector<int>> &res)
    {
        if(si == nums.size())   // base case
        {
           /* for(auto x :ans)
                cout<<x;
            cout<<endl;*/
            res.push_back(ans);
            return;
        }
        
        int ch =nums[si];        
        // including current char
        ans.push_back(ch);           
        helper(si+1, nums, ans, res);
        ans.pop_back();
        
        //excluding current char
        helper(si+1, nums, ans, res);

    }
    vector<vector<int>> subsets(vector<int>& nums) 
    {
        vector<vector<int>> res;
        
        vector<int> ans;
        helper(0, nums, ans, res);
        
        return res;
    }
};
