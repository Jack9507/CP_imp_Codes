#include<bits/stdc++.h>
using namespace std;
#define ll long long


int fact(int n)
{
    if(n==0 || n==1)
        return 1;
    return n*fact(n-1);
}

void sub_sequences(string str, string res)
{
    if(str.length() == 0)
    {
        cout<<res<<endl;
        return;
    }
    char ch=str[0];
    string ros =str.substr(1);
    // including first char
     sub_sequences(ros, res+ch);
    // excluding first char
     sub_sequences(ros, res);
}

void print_permutations(string str, string res)
{
    if(str.length() ==0 )
    {
        cout<<res<<endl;
        return;
    }

    for(int i=0; i<str.length(); i++)
    {
        char ch=str[i];

        string ros =str.substr(0,i)+ str.substr(i+1);
        print_permutations(ros, res+ch);
    }

}

string removeDuplicates(string str)
{
    if(str.length()==0)
    {
        return str;
    }

    char ch=str[0];
    string ros =str.substr(1);
    string recursion_result = removeDuplicates(ros);
    if(recursion_result[0] == ch)
        return recursion_result;
    else
        return ch + recursion_result;

}


string addStarBetweenDuplicates(string str)
{
    if(str.length() ==0)
    {
        return str;
    }

    char ch=str[0];
    string ros =str.substr(1);
    string recursion_result = addStarBetweenDuplicates(ros);

    if(recursion_result[0] == ch )
        {
           recursion_result = "*" + recursion_result;
            return ch  + recursion_result;
            // or return ch + string("*")+ recursion_result;
        }
    else
        return ch+recursion_result;

}


string moveXToEnd(string str)
{
    if(str.length() ==0)
        return str;

    char ch=str[0];
    string ros =str.substr(1);

    string rec_result = moveXToEnd(ros);

    if(ch == 'x')
    {
        return rec_result +ch;
    }
    else
        return ch +rec_result;

}



string replacePi(string str)
{
    if(str.length() ==0)
        return str;

    char ch=str[0];
    string ros =str.substr(1);

    string rec_result =replacePi(ros);

    if(ch=='p'&& rec_result[0]=='i')
    {
        rec_result = rec_result.substr(1);
        rec_result = "3.14" + rec_result;
        return rec_result;
    }
    else
        return ch +rec_result;

}


void prefix_sum(int arr[], int n)
{
    vector<int> res(n);
    res[0] =arr[0];

    for(int i=1; i<n; i++)
        res[i] =res[i-1] + arr[i];

    for(auto x: res)
        cout<<x<<"  ";
}

int sum_till_n(int n)
{
    if(n==1)
        return 1;
    return n+sum_till_n(n-1);
}

int power(int n, int p)
{
    if(p == 0)
        return 1;

    int tmp =power(n, p-1);

    return n *tmp;

}


int count_maze_path(int sr, int sc, int er, int ec)
{
    if(sr==er && sc ==ec)
        return 1;
    if(sr >er || sc >ec)
        return 0;

    int right = count_maze_path(sr, sc+1, er,ec);
    int down =  count_maze_path(sr+1, sc, er,ec);
    //int diagonal =count_maze_path(sr+1, sc+1, er, ec);
    return right +down ;

}


int main()
{
    //   print all subsequences of a string
//    string str="abcd";
//    string res="";
//    sub_sequences(str, res);


    //  print permutations
//    string str ="123";
//    string res="";
//    print_permutations(str, res);

    //   cout << removeDuplicates("abbccdggfffjjjkkl") << endl;

   //    cout << addStarBetweenDuplicates("hhelloow") << endl;

    //   cout << moveXToEnd("xabcxxyx") << endl;

    //   cout << replacePi("xxpiipixxppix") << endl;
                    // ans =   xx 3.14 i 3.14 xx p 3.14 x

//        int arr[]={1,2,3,4,5};
//        int n=sizeof(arr)/sizeof(arr[0]);
//        prefix_sum(arr,n);

    //  cout<<sum_till_n(10);

    //   cout<<power(2, 10)<<endl;

      cout<<count_maze_path(0,0, 3,3);   //4x4 matrix


    return 0;
}
