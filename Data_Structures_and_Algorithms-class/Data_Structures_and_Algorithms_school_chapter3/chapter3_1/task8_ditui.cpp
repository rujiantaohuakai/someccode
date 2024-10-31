#include<iostream>
using namespace std;
#define MAXSIZE 22
//没做对
int Ack(int m,int n)
{//Ackermann函数的非递归求值
/**************begin************/
    //递推求解 m+1行,n+1列的矩阵
    // A[i][j]表示第i行第j列的元素值
    int A[MAXSIZE][MAXSIZE] = {{0}};
    //初始化第一行
    for(int j = 0; j <= 20; j++)
        A[0][j] = j + 1;//第一行的第j+1个元素等于j+1
    
    for(int i = 1; i <=20; i++){
        A[i][0] = A[i-1][1];//第i+1行第一个元素等于第i行第二个元素
        for(int j = 1; j <=20; j++){
            A[i][j] = A[i-1][A[i][j-1]];
            //其他元素等于上一行的A[i][j-1]下标位置的(当前元素的上一个元素)元素的值
        }
    }

    for(int i = 0; i <= 20; i++){
        for(int j = 0; j <= 20; j++){
            cout << A[i][j] << " ";
        }
        cout << endl;
    }
    
    return A[m][n];
    /**************end************/
}
int main()
{
	int m,n;
	while(cin>>m>>n)
    {
        if(m==0&&n==0) break;
        cout<<Ack(m,n)<<endl;
    }
	return 0;
}

