#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define P pair<int,int>
const int mod=1e9+7;


int maxsumsub(vector<int> arr, int n)
{
    vector<int> T =arr;
//    for(auto x: T)
//        cout<<x<<", ";
//    cout<<endl;
     vector<int> idx(n);   
        for(int i=0; i<n; i++)
            idx[i]=i;

     for(int i=1; i<n; i++)
     {
         for(int j=0; j<i; j++)
         {
             if(j+1 != i && arr[j]<arr[i])
             {
                 int flag1=T[i];
                 T[i]=max(T[i], T[j]+arr[i]);
                 int flag2=T[i];
                 if(flag1 != flag2)     // if T[i] is updated then change the index from where the max sum is coming i.e 'j'
                    idx[i]=j;
             }
         }
     }

    int maxsum =*max_element(T.begin(), T.end());
    //cout<<"maximum sum = "<<maxsum<<endl;

    return maxsum;
    // // to find actual sub sequence use idx array
    // int id1=0;
    // for(int i=0; i<T.size(); i++)
    // {
    //     if(T[i]==maxsum)
    //         id1=i;        // index of max sum
    // }
    // vector<int> res; // contains the maximum sub sequence
    // int sum=0;
    // while(true)
    // {
    //     if(sum == maxsum)
    //         break;
    //     res.push_back(arr[id1]);
    //     sum += arr[id1];
    //     id1= idx[id1];
    // }

    // reverse(res.begin(),res.end());
    // cout<<endl;
    // for(int x: res)
    //     cout<<x<<", ";
    // cout<<endl;


}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0; i<n; i++)
      cin>>arr[i];

     int ans = maxsumsub(arr,n);

     cout<<ans<<endl;

    return 0;
}
