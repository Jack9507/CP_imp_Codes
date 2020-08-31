#include<bits/stdc++.h>
using namespace std;
#define mod 1e9
#define int long long
#define endl '\n'


int string_to_int(string str)
{
    stringstream ss;
    ss<< str;
    int num;
    ss>>num;

    return num;
}
string int_to_string(int n)
{
    stringstream ss;
    ss<<n;
    string str;
    ss>>str;

    return str;

}
string array_to_string(vector<int> nums)
{
    stringstream ss;
    for(int x: nums)
        ss<<x;

    string str;
    ss>>str;

    return str;
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

     int n=4989;
     string str="102030";
     vector<int> nums={9,7,8,1,6,3};

     cout<<string_to_int(str)<<endl;

     cout<<int_to_string(n)<<endl;

     cout<<array_to_string(nums)<<endl;




    return 0;
}
