//将n进制num转换为m进制Num
//思路:先将n进制num转为10进制new_num，然后再将new_num转为m进制Num
#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>

int main(){
    std::string num;
    int n, m;
    std::cin >> n >> num >> m;
    int new_num = 0;
    int point = num.find('.');
    std::string integer_part = num.substr(0, point);
    std::string decimal_part = num.substr(point+1);
    int interger_part_len = integer_part.size();
    int decimal_part_len = decimal_part.size();
    for(int i = 0; i < interger_part_len; i++){
        new_num += integer_part[i] * pow(10, interger_part_len-i-1);
    }
    

}