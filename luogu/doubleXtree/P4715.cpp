#include<bits/stdc++.h>
using namespace std;

typedef struct node{
    int val;
    int id;
}node;

// int main()
// {
//     int a;
//     cin >> a;
//     int n = pow(2, a);
//     node *tree = new node[2*n - 1];
//     for(int i = 0; i < n; i++){
//         cin >> tree[i].val;
//         tree[i].id = i + 1;
//     }
//     int index = 0;
//     for(int i = n; i < 2*n - 1; i++){
//         tree[i].val = max(tree[index].val, tree[index + 1].val);
//         if(tree[i].val == tree[index].val){
//             tree[i].id = tree[index].id;
//             //cout << tree[i].id << endl;
//         }
//         else{
//             tree[i].id = tree[index + 1].id;
//            //cout << tree[i].id << endl;
//         }
            
//         index += 2;
//     }

//     //输出亚军的id
//     if(tree[2*n - 1 - 1 - 1].val > tree[2*n - 1 - 1 - 2].val){
//         cout << tree[2*n - 4].id << endl;
//     }
//     else{
//         cout << tree[2*n - 3].id << endl;
//     }

// // 2 4 6 8 10 12 14 16
// // 4 8 12 16
// // 8 16
// // 16
//     return 0;
// }
int main(){

    queue<node> q;
    int tem;
    cin >> tem;
    int n = pow(2, tem);
    for(int i = 0; i < n; i++){
        node country;
        cin >> country.val;
        country.id = i+1;
        q.push(country);
    }
    node t1, t2;
    while(q.size() > 1){
        t1 = q.front();
        q.pop();
        t2 = q.front();
        q.pop();
        q.push(t1.val > t2.val ? t1 : t2);
    }
    if(t1.val > t2.val)
        cout << t2.id << endl;
    else
        cout << t1.id << endl;

    return 0;
}