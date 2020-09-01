#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'


int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);


     vector<int> arr={1,1,2,2,4,4,5};
      for(int x: arr)
            cout<<x<<"\t";
      cout<<endl;

      //Lower bound return greater than equal to '>='
      auto lb =lower_bound(arr.begin(), arr.end(), 3) -arr.begin();
      //upper bound return greater than '>'
      auto ub =upper_bound(arr.begin(), arr.end(), 3) -arr.begin();

      if(binary_search(arr.begin(), arr.end(), 6))
         cout<<"found"<<endl;
         else
            cout<<"sorry"<<endl;
            
      cout<<ub-lb<<endl;   // count of the number
      cout<<"Lower Bound = "<<lb<<endl<<"Upper Bound = "<<ub<<endl;

      //Note : When the number is not present in array then lower_bound and upper_bound are same.
      
      

    return 0;
}
