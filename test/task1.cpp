#include<iostream>
#include<fstream>
#include<string.h>
using namespace std;
#define MAXSIZE 2000

//- - - - - 串的堆式顺序存储结构- - - - - 
typedef struct
{   
   char *ch;				//若是非空串，则按串长分配存储区，否则ch为NULL   
   int length;			//串的当前长度   
}HString; 

int Index_BF(HString S,HString T,int pos)
{//返回模式T在主串S中第pos个字符开始第一次出现的位置。若不存在，则返回值为0 
 //其中，T非空，1≤pos≤StrLength(S) 
    if(strlen(T.ch) > strlen(S.ch)) return 0; //模式长度大于主串长度，肯定不匹配
    int i = pos - 1, j = 0;
    while(i < strlen(S.ch) && j < strlen(T.ch)){
        if(S.ch[i] == T.ch[j]){i++; j++;}
        else{
            i = i - j + 1;
            j = 0;
        }
    }
    if(j >= T.length) return i - T.length + 1;
    else return 0; 
} 


bool Virus_detection(HString Virus,HString Person)
{//判断是否匹配，如果可以，返回true，否则返回false 
//模式匹配算法调用Index_BF函数 
    //病毒是环状病毒，需要检查所有可能序列
    /*
    abcd环状病毒可能序列：
    abcd
    bcda
    cdba
    dabc
    */
    Virus.length = strlen(Virus.ch);    //病毒序列长度
    int temp = 0;   //环状病毒从第几位的前面断裂
    while(temp < Virus.length){//找出每一种可能的病毒序列
        HString temp_virus;
        temp_virus.ch = new char[Virus.length + 1];  //分配内存,+1是为了存储结束符'\0'
        for(int i = 0; i < Virus.length; i++){
            temp_virus.ch[i] = Virus.ch[(temp + i) % Virus.length];
        }
        temp_virus.length = Virus.length;
        temp_virus.ch[Virus.length] = '\0';
        if(Index_BF(Person, temp_virus, 1)){
            return true;
        }
        delete[] temp_virus.ch;
        temp++;
    }
    return false;

}