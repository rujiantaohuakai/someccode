#include<iostream>
#include<fstream>
#include<cstring>
using namespace std;
#define MAXSIZE 2000

typedef struct
{   
   char *ch;				//若是非空串，则按串长分配存储区，否则ch为NULL   
   int length;				//串的当前长度   
}HString; 


void GetNext(HString T, int *next){
    //求next数组
    //abaabab len = 7
    //0112234
   //-1001123
    int i = 0, j = -1;
    next[0] = -1;
    while(i < T.length - 1){
        if(j == -1 || T.ch[i] == T.ch[j]){
            i++;
            j++;
            next[i] = j;
        }
        else j = next[j];
    }
}

int Index_KMP(HString S,HString T,int pos)
{//返回模式T在主串S中第pos个字符开始第一次出现的位置。若不存在，则返回值为0 
 //其中，T非空，1≤pos≤StrLength(S) 
    int *next = new int[T.length];
    GetNext(T, next);
    int i = pos - 1, j = 0;
    //cout << T.length << endl;
    while(i < S.length && j < T.length){//不要用strlen，因为这是c风格字符串，长度不一定是字符串的实际长度
        if(j == -1 || S.ch[i] == T.ch[j]){
            i++;
            j++;
        }
        else j = next[j];
    }
    delete[] next;
    
    if(j == T.length)
        return i - T.length + 1;    //返回在第几位
    else
        return 0;
} 
/*
baa cacdvcabacsd
*/
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
    int temp = 0;   //环状病毒从第几位的前面断裂
    while(temp < Virus.length){//找出每一种可能的病毒序列
        HString temp_virus;
        temp_virus.ch = new char[Virus.length + 1];  //分配内存,+1是为了存储结束符'\0'
        temp_virus.length = Virus.length;
        for(int i = 0; i < Virus.length; i++){
            temp_virus.ch[i] = Virus.ch[(temp + i) % Virus.length];
        };
        temp_virus.ch[Virus.length] = '\0';

        if(Index_KMP(Person, temp_virus, 1) > 0){
            delete[] temp_virus.ch;
            return true;
        }
        delete[] temp_virus.ch;
        temp++;
    }
    return false;
}

void InputHString(HString &S) {
    // 输入字符串
    char temp[2000]; // 临时字符串用于输入
    cin >> temp;
    
    // 为HString的ch分配内存
    S.length = strlen(temp); // 获取字符串长度
    S.ch = new char[S.length + 1]; // 分配内存，+1是为了存储结束符'\0'
    
    // 复制内容到HString
    strcpy(S.ch, temp);
}

int main(){
    // 输入病毒序列和人类序列
    HString Virus,Person;

    cout << "请输入病毒序列：";
    InputHString(Virus);
    cout << "请输入人类序列：";
    InputHString(Person);

    if(Virus_detection(Virus,Person))
        cout << "病毒序列在人类序列中存在！" << endl;
    else
        cout << "病毒序列不在人类序列中！" << endl;
    return 0;
}
