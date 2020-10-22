#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define P pair<int,int>
const int mod=1e9+7;

int32_t main()
{
    vector<int> nums ={5, 4, 3, 2, 1, 6, 3, 5, 4, 2, 1 };
    int n=nums.size();
    int k=3;

    map<int, int> mp;          // {number, frequency};    ordered map maintains order, so insertion deletion becomes O(n)

    int l=0;      //  count the elements in map
    for(int i=0; i<n; i++)
    {
        l++;
        mp[nums[i]]++;

        if(l==k)     // when exactly k elements are inserted in map
        {
            // now find max and min in current sub array
            auto it1=mp.begin();
            auto it2=mp.end();
            it2--;

            cout<<"min = "<<it1->first<<"  ,  ";
            cout<<"max = "<<it2->first<<endl;


            mp[nums[i-k+1]]--;       // remove the first element to increase the window
            if(mp[nums[i-k+1]]==0)
                mp.erase(nums[i-k+1]);

            l--;   //  since one element is removed from the map so decrease count by 1

        }

    }

    return 0;
}
