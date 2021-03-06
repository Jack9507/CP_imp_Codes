#include<bits/stdc++.h>
using namespace std;
#define mod 1e9
#define int long long
#define endl '\n'


// Time Complexity to get all sub arrays in brute force is O(n^3).
// Total sub arrays possible in an array of size 'n' is n*(n+1)/2
void subarray(vector<int> arr)
{
    int n=arr.size();

    for(int start=0; start<arr.size(); start++)
    {
        for(int end=start; end<arr.size(); end++)
        {
            for(int i=start; i<=end; i++)
            {
                cout<<arr[i]<<" ";
            }
            cout<<endl;
        }
    }

      return;
}


// Time Complexity to get all sub_sequences in brute force is O(2^n).
// Total subsequences possible with arr of size 'n' is 2^n -1;
//1,2,3,4
void sub_sequences(string str, string ans)
{
    if(str.length() ==0)           // base case
    {
        cout<<ans<<endl;
        return;
    }

    char ch=str[0];
    string ros= str.substr(1);

    // including first char into subsequence
    sub_sequences(ros, ans+ch);

    // excluding first char
    sub_sequences(ros, ans);

}

// Subsets ans subsequences are same the only difference is that subsets have empty set
// {a b c} -set
// all possible subsets are '2^n' :- 
// {} - empty set 
// a
// b
// c
// a b
// a c
// b c
// a b c

// Time Complexity - O(2^n)  function grows exponentially
void subsets_powerset(vector<char> &nums, int n)
{
	// in a set has 'n' elements then its power set will have 2^n elements
	unsigned int size=pow(2,n);  
	for (int counter = 0; counter <size; counter++)
	{
		for (int j = 0; j <n; j++)
		{
			// check if the j^th bit is set in counter or not
            if(counter & (1<<j))
            {
            	//bit is set
            	cout<<nums[j]<<" ";
            }
		}
		cout<<endl;
	}

}

void print_all_substrings(string str)
{
    int n=str.length();

    for(int i=0; i<n; i++)
    {
        for(int len=1; len<=n-i; len++)
        {
            string ros= str.substr(i, len);
            cout<<ros<<endl;
        }
    }
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<int> arr={1,2,3,4};

    // printing all possible sub array
    subarray(arr);

    cout<<endl<<endl;

    string str="1234";
    //printing all possible subsequences
    sub_sequences(str, "");
    
    string s1="jatin";
    cout<<print_all_substrings(s1);



    return 0;
}

