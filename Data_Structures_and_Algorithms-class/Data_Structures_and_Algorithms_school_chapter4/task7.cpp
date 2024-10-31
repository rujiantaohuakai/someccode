//求字符出现的频度
#include <iostream>
#include <string>
using namespace std;

int main(){
    string str;
    while(cin >> str){
        //定义统计数组
        int count[36] = {0}; //0-9存储0-9的频度，10-36存储A-Z的频度
        if(str == "0") break;
        for(int i = 0; i < str.size(); i++){
            if(str[i] >= '0' && str[i] <= '9'){
                count[str[i] - '0']++;
            }
            else if(str[i] >= 'A' && str[i] <= 'Z'){
                count[str[i] - 'A' + 10]++;
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

    return 0;
}