#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define P pair<int,int>

//    Question : -   Split the string and check how many palindrome words are there.

bool isplaindrome(string str)
{
    string tmp =str;
    reverse(tmp.begin(), tmp.end());

    return tmp ==str;
}
int32_t main()
{
    string str;
    getline(cin, str);
    cout<<str;
    cout<<endl;
    stringstream ss(str);
    int cnt=0;

    for(string word; ss>>word;)
    {
        cout<<word<<endl;
//        transform(word.begin(), word.end(),word.begin(), ::toupper);
//        cout<<word<<endl;

        if(isplaindrome(word))
            cnt++;
    }

    cout<<endl<<"ans = "<<cnt<<endl;


    return 0;
}
