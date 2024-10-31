//模式匹配算法的BP算法实现
#include<iostream>
#include<string>

//BP算法函数
int Index_BP(std::string m_str, std::string p_str, int pos){
    int m_len = m_str.size() - 1;
    int p_len = p_str.size() - 1;
    //如果模式串为空，则返回主串的起始位置
    if(p_len == 0) return 0;
    //如果模式串长度大于主串长度，则返回-1
    if(p_len > m_len) return -1;
    int i = pos;
    int j = 1;
    while(i <= m_len && j <= p_len){
        if(m_str[i] == p_str[j]){++i;++j;}
        else{
            i = i - j + 2;
            j = 1;
        }
    }
    std::cout << "i = " << i << std::endl;
    std::cout << "j = " << j << std::endl;
    std::cout << "m_len = " << m_len << std::endl;
    std::cout << "p_len = " << p_len << std::endl;
    if(j > p_len) return i - p_len;
    else return -1;
    
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
    //在主串和模式串第一个位置插入#，让下标从1开始
    main_str.insert(0, "#");
    pattern_str.insert(0, "#");
    std::cout << "主串：" << main_str << std::endl;
    std::cout << "模式串：" << pattern_str << std::endl;
    //定义从主串的pos位置开始匹配模式串
    int pos = 1;
    std::cout << "模式串在主串中第pos个位置开始匹配" << std::endl;
    std::cout << "pos = ";
    std::cin >> pos;
    //调用BP算法函数
    int index = Index_BP(main_str, pattern_str, pos);
    if(index == -1) std::cout << "不存在匹配" << std::endl;
    else if(index == 0) std::cout << "模式串为空" << std::endl;
    else std::cout << "模式串在主串中第" << index << "个位置开始匹配" << std::endl;
    return 0;
}