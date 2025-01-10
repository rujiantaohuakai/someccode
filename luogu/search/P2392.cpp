#include<bits/stdc++.h>
using namespace std;


int main(){
    int s1,s2,s3,s4;
    cin >> s1 >> s2 >> s3 >> s4;
    vector<int> S1(s1);
    vector<int> S2(s2);
    vector<int> S3(s3);
    vector<int> S4(s4);
    for(int i = 0; i < s1; i++){
        cin >> S1[i];
    }
    for(int i = 0; i < s2; i++){
        cin >> S2[i];
    }
    for(int i = 0; i < s3; i++){
        cin >> S3[i];
    }
    for(int i = 0; i < s4; i++){
        cin >> S4[i];
    }
    int min_time = 0;
    for(int i = 1; i <=4; i++){
        if(i == 1){ //计算第一科所用最小时间
            sort(S1.begin(),S1.end());
            int pl = 0, pr = S1.size() - 1;
            while(pl < pr){
                if(S1[pr] > S1[pl]){
                    min_time += S1[pl];
                    S1[pr] -= S1[pl];
                    pl++;
                }
                else{
                    min_time += S1[pr];
                    S1[pl] -= S1[pr];
                    pr--;
                }
            }
            min_time += S1[pl];
        }
        else if(i == 2){
            sort(S2.begin(),S2.end());
            int pl = 0, pr = S2.size() - 1;
            while(pl < pr){
                if(S2[pr] > S2[pl]){
                    min_time += S2[pl];
                    S2[pr] -= S2[pl];
                    pl++;
                }
                else{
                    min_time += S2[pr];
                    S2[pl] -= S2[pr];
                    pr--;
                }
            }
            min_time += S2[pl];
        }
        else if(i == 3){
             sort(S3.begin(),S3.end());
            int pl = 0, pr = S3.size() - 1;
            while(pl < pr){
                if(S3[pr] > S3[pl]){
                    min_time += S3[pl];
                    S3[pr] -= S3[pl];
                    pl++;
                }
                else{
                    min_time += S3[pr];
                    S3[pl] -= S3[pr];
                    pr--;
                }
            }
            min_time += S3[pl];
        }
        else{
            sort(S4.begin(),S4.end());
            int pl = 0, pr = S4.size() - 1;
            while(pl < pr){
                if(S4[pr] > S4[pl]){
                    min_time += S4[pl];
                    S4[pr] -= S4[pl];
                    pl++;
                }
                else{
                    min_time += S4[pr];
                    S4[pl] -= S4[pr];
                    pr--;
                }
            }
            min_time += S4[pl];
        }

    }
    cout << min_time << endl;
    return 0;

}