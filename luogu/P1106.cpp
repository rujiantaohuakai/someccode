#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

//新知识：string类型 str.erase()可以用于删除字符串中的某个字符

/*没有按照原来的顺序
int main()
{
    string number;
    vector<int> Num;
    int n;
    cin >> number;
    cin >> n;
    int len;
    len = number.size();
    //cout << len;
    for(int i = 0; i < len; i++)
    {
        Num.push_back(number[i] - '0');
    }

    // for(int i = 0; i < len; i++)
    // {
    //     cout << Num[i];
    // }

    // cout<<endl;

    for(int i = 1; i <= n; i++)
    {
        sort(Num.begin(), Num.end());
        Num.pop_back();
    }

    int k = 0;
    while(Num[k] == 0)
    {
        k++;
    }
    // if(k != 0)
    // {
    //     Num[0] = Num[k];
    //     Num[k] = 0;
    // }

    for(int i = k; i < Num.size(); i++)
    {
        cout << Num[i];
    }

    return 0;
}

*/

int main()
{
    string number;
    cin >> number;
    int n;
    cin >> n;
    while(n--)
    {   
        int len = number.size();
        for(int i = 0; i < len; i++)
        {
            while(number[0] == '0')
                number.erase(0, 1);
            if((number[i] > number[i+1]) || i == len-1)
            {
                number.erase(i, 1);
                //len--;
                break;
            }
        }
    }

    cout << number;



    return 0;
}
