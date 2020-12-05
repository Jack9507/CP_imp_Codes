
//Ques. Maximum sum subsequence such that no two elements are adjacent

// Algorithm:
// Loop for all elements in arr[] and maintain two sums incl and excl where incl = Max sum including the previous element and excl = Max sum excluding the previous element.

// Max sum excluding the current element will be max(incl, excl) and max sum including the current element will be excl + current element (Note that only excl is considered because elements cannot be adjacent).

// At the end of the loop return max of incl and excl.

#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define P pair<int,int>
const int mod=1e9+7;


int max(int x, int y)
{
	return (x>y) ? x:y;
}
void max_sum_sub(vector<int> &arr, int n)
{
	int incl=arr[0];   //  sum including the prev element i.e 1st element
	int excl= 0;       //  sum excluding the prev element
	int excl_new;

	// now start the traversal from index 1
	for(int i=1; i<n; i++)
	{
		excl_new = (incl > excl)? incl: excl; 
  
     incl = excl + arr[i]; 
     excl = excl_new; 
	}

   // cout<<"max sum ="<<max(incl,excl)
	return max(incl,excl);
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);


      vector<int> arr ={5, 5, 10, 100, 10, 5};
      int n=arr.size();

     int ans = max_sum_sub(arr,n);
     cout<<ans<<endl;


    return 0;
}

