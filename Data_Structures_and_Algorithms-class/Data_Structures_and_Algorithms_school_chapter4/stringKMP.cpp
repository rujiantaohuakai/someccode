//字符串模式匹配算法KMP算法实现
#include<iostream>
#include<string>

//KMP算法实现
//计算next数组
void getNext(std::string pattern_str, int next[]){
    int i = 0, j = 0
}

int main(){
     //定义主串和模式串
    std::string main_str, pattern_str;
    std::cout << "请输入主串：" << std::endl;
    std::cout << "main_str：";
    std::cin >> main_str;
    std::cout << "请输入模式串：" << std::endl;
    std::cout << "pattern_str：";
    std::cin >> pattern_str;

    //定义从主串的pos位置开始匹配模式串
    int pos = 0;
    std::cout << "模式串在主串中第pos个位置开始匹配" << std::endl;
    std::cout << "pos = ";
    std::cin >> pos;
    //定义next数组，用于记录模式串中每个字符的最长前缀与后缀的匹配长度
    int next[pattern_str.size()] = {0};
    //初始化next数组
}