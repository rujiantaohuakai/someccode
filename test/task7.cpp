#include<iostream>
#include<cstring>
using namespace std;
void Count(string c,int b[])
{//统计字符出现的频度
    //定义统计数组
    int count[36] = {0};    //0-9存储0-9的频度，10-36存储A-Z的频度
    for(int i = 0; i < c.size(); i++){
        if(c[i] >= '0' && c[i] <= '9'){
            count[c[i] - '0']++;
        }
        else if(c[i] >= 'A' && c[i] <= 'Z'){
            count[c[i] - 'A' + 10]++;
        }
    }
    //输出统计结果
    for(int i = 0; i < 36; i++){
        if(count[i] > 0 && i <= 9){
            cout << i << ":" << count[i] << endl;
        }
        else if(count[i] > 0 && i > 9){
            cout << char('A' + i - 10) << ":" << count[i] << endl;
        }
    }
}
