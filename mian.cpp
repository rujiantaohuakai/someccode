#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

// 定义LIMS结构体，表示图书信息
typedef struct LIMS
{
    char name[50];                // 书名
    char author[50];              // 作者
    char publication_time[50];    // 出版时间
    char publication_house[50];   // 出版商
    float price;                  // 价格
    struct LIMS* next;            // 指向下一本图书的指针
} L, * Llink;

// 插入图书信息函数
void insert_function(Llink& L1)
{
    system("cls");  // 清屏
    Llink p = L1;
    Llink new_node = new L;  // 使用new替代malloc，创建新的图书节点

    // 输入书籍信息
    printf("请输入书名: ");
    scanf_s("%s", new_node->name, (unsigned)sizeof(new_node->name));

    printf("请输入作者: ");
    scanf_s("%s", new_node->author, (unsigned)sizeof(new_node->author));

    printf("请输入出版时间: ");
    scanf_s("%s", new_node->publication_time, (unsigned)sizeof(new_node->publication_time));

    printf("请输入出版商: ");
    scanf_s("%s", new_node->publication_house, (unsigned)sizeof(new_node->publication_house));

    printf("请输入价格: ");
    scanf_s("%f", &new_node->price);

    new_node->next = NULL;  // 新节点的next指向NULL，表示它是链表的最后一个节点

    // 如果链表为空，插入新的图书作为第一个节点
    if (L1 == NULL) {
        L1 = new_node;
    }
    else {
        // 否则遍历链表，找到最后一个节点并插入新节点
        p = L1;
        while (p->next != NULL) {
            p = p->next;
        }
        p->next = new_node;
    }
    printf("\n添加成功！\n");
    system("pause");
}

// 查询图书信息函数
void search_function(Llink L1)
{
    system("cls");
    char search_name[50]; // 存储查询的书名
    printf("请输入要查询的书名: ");
    getchar();  // 清除输入缓存
    gets_s(search_name, sizeof(search_name)); // 输入书名

    Llink p = L1;
    bool found = false;

    // 如果链表为空，提示没有图书
    if (L1 == NULL)
        printf("！！！系统中没有书籍！！！\n");
    else
    {
        // 遍历链表查找匹配的书名
        while (p != NULL)
        {
            if (strcmp(p->name, search_name) == 0)
            {
                // 找到书籍后，输出书籍信息
                printf("\n找到了！%s的书籍信息如下：\n", p->name);
                printf("书名：%s\n作者：%s\n出版时间：%s\n出版商：%s\n价格：%.2f\n",
                    p->name, p->author, p->publication_time, p->publication_house, p->price);
                found = true;
                break;
            }
            p = p->next;
        }
        if (!found)
            printf("！！！未找到该书籍！！！\n");  // 如果没有找到
    }
    system("pause");
}

// 删除图书信息函数
void delete_function(Llink* L1)
{
    system("cls");
    // 如果链表为空，提示没有图书
    if (*L1 == NULL) {
        printf("！！！系统中没有书籍！！！\n");
        system("pause");
        return;
    }

    char delete_name[50];  // 存储要删除的书名
    printf("请输入要删除的书名: ");
    getchar();  // 清除输入缓存
    gets_s(delete_name, sizeof(delete_name));  // 输入书名

    Llink p = *L1, pr = NULL;
    bool found = false;

    // 遍历链表查找要删除的书籍
    while (p != NULL)
    {
        if (strcmp(p->name, delete_name) == 0)
        {
            // 如果找到，删除该节点
            if (pr == NULL)
                *L1 = p->next;  // 删除的是头节点，更新头指针
            else
                pr->next = p->next;  // 删除的是非头节点，更新前一个节点的next指针

            delete p;  // 释放内存
            printf("！！！书名 \"%s\" 已删除！！！\n", delete_name);
            found = true;
            break;
        }
        pr = p;
        p = p->next;
    }

    if (!found)
        printf("！！！未找到书名 \"%s\"！！！\n");  // 没有找到要删除的书籍
    system("pause");
}

// 打印所有图书信息函数
void print_function(Llink L1)
{
    system("cls");
    // 如果链表为空，提示没有图书
    if (L1 == NULL) {
        printf("！！！系统中没有书籍！！！\n");
        system("pause");
        return;
    }

    printf("==================== 图书列表 ====================\n");
    printf("%-20s%-20s%-20s%-20s%-10s\n", "书名", "作者", "出版时间", "出版商", "价格");
    printf("------------------------------------------------\n");

    Llink p = L1;
    // 遍历链表打印所有图书信息
    while (p != NULL)
    {
        printf("%-20s%-20s%-20s%-20s%.2f\n",
            p->name, p->author, p->publication_time, p->publication_house, p->price);
        p = p->next;
    }
    printf("================================================\n");
    system("pause");
}

// 修改图书信息函数
void change_function(Llink* L1)
{
    system("cls");
    // 如果链表为空，提示没有图书
    if (*L1 == NULL) {
        printf("！！！系统中没有书籍！！！\n");
        system("pause");
        return;
    }

    char change_name[50];  // 存储要修改的书名
    printf("请输入要修改的书名: ");
    getchar();  // 清除输入缓存
    gets_s(change_name, sizeof(change_name));  // 输入书名

    Llink p = *L1;
    bool found = false;

    // 遍历链表查找匹配的书籍
    while (p != NULL)
    {
        if (strcmp(p->name, change_name) == 0)
        {
            // 如果找到书籍，提示用户选择要修改的字段
            printf("\n请选择要修改的信息(1-5)：\n");
            printf("1. 书名\n");
            printf("2. 作者\n");
            printf("3. 出版时间\n");
            printf("4. 出版商\n");
            printf("5. 价格\n");
            printf("请选择: ");

            int choice;
            scanf_s("%d", &choice);
            getchar();  // 清除输入缓存

            char temp[50];
            // 根据用户选择修改相应字段
            switch (choice)
            {
            case 1:
                printf("请输入新的书名: ");
                gets_s(temp, sizeof(temp));
                strcpy_s(p->name, temp);  // 修改书名
                break;
            case 2:
                printf("请输入新的作者: ");
                gets_s(temp, sizeof(temp));
                strcpy_s(p->author, temp);  // 修改作者
                break;
            case 3:
                printf("请输入新的出版时间: ");
                gets_s(temp, sizeof(temp));
                strcpy_s(p->publication_time, temp);  // 修改出版时间
                break;
            case 4:
                printf("请输入新的出版商: ");
                gets_s(temp, sizeof(temp));
                strcpy_s(p->publication_house, temp);  // 修改出版商
                break;
            case 5:
                printf("请输入新的价格: ");
                scanf_s("%f", &p->price);  // 修改价格
                break;
            default:
                printf("无效的选择！\n");
                break;
            }
            found = true;
            printf("\n修改成功！\n");
            break;
        }
        p = p->next;
    }

    if (!found)
        printf("！！！未找到该书籍！！！\n");
    system("pause");
}

// 将图书信息保存到文件
void saveToFile(Llink L1) {
    FILE* fp;
    errno_t err = fopen_s(&fp, "books.txt", "w");
    if (err != 0) {
        printf("文件保存失败！\n");
        return;
    }

    Llink p = L1;
    // 遍历链表，将图书信息写入文件
    while (p != NULL) {
        fprintf(fp, "%s %s %s %s %.2f\n",
            p->name,
            p->author, p->publication_time,
            p->publication_house, p->price);
        p = p->next;
    }
    fclose(fp);  // 关闭文件
}

// 从文件中加载图书信息
void loadFromFile(Llink& L1) {
    FILE* fp;
    errno_t err = fopen_s(&fp, "books.txt", "r");
    if (err != 0) {
        return;  // 如果文件无法打开，则直接返回
    }

    char name[50], author[50], time[50], house[50];
    float price;

    // 逐行读取文件中的图书信息，并插入链表
    while (fscanf_s(fp, "%s %s %s %s %f",
        name, (unsigned)sizeof(name),
        author, (unsigned)sizeof(author),
        time, (unsigned)sizeof(time),
        house, (unsigned)sizeof(house),
        &price) == 5)
    {
        Llink new_node = new L;  // 创建新的节点
        strcpy_s(new_node->name, name);  // 复制书名
        strcpy_s(new_node->author, author);  // 复制作者
        strcpy_s(new_node->publication_time, time);  // 复制出版时间
        strcpy_s(new_node->publication_house, house);  // 复制出版商
        new_node->price = price;  // 设置价格
        new_node->next = NULL;  // 设置next为NULL，表示该节点是链表的末尾

        // 将新节点插入到链表的末尾
        if (L1 == NULL) {
            L1 = new_node;
        }
        else {
            Llink p = L1;
            while (p->next != NULL) {
                p = p->next;
            }
            p->next = new_node;
        }
    }
    fclose(fp);  // 关闭文件
}

// 显示主菜单
void menu()
{
    system("cls");
    printf("================== 图书管理系统 ==================\n");
    printf("1. 录入图书信息\n");
    printf("2. 查询图书信息\n");
    printf("3. 删除图书信息\n");
    printf("4. 显示所有图书\n");
    printf("5. 修改图书信息\n");
    printf("6. 退出系统\n");
    printf("================================================\n");
}

// 主函数
int main()
{
    SetConsoleOutputCP(936);  // 设置控制台输出为中文，确保中文显示正常
    int n;
    Llink L1 = NULL;  // 初始化链表为空

    // 从文件中加载图书信息
    loadFromFile(L1);

    // 无限循环，显示菜单并处理用户输入
    while (1)
    {
        menu();  // 显示主菜单
        printf("请选择操作(1-6): ");
        scanf_s("%d", &n);  // 获取用户输入的操作选择

        switch (n)
        {
        case 1:
            insert_function(L1);  // 录入图书信息
            saveToFile(L1);  // 保存图书信息到文件
            break;
        case 2:
            search_function(L1);  // 查询图书信息
            break;
        case 3:
            delete_function(&L1);  // 删除图书信息
            saveToFile(L1);  // 保存更改后的图书信息到文件
            break;
        case 4:
            print_function(L1);  // 显示所有图书
            break;
        case 5:
            change_function(&L1);  // 修改图书信息
            saveToFile(L1);  // 保存更改后的图书信息到文件
            break;
        case 6:
            printf("\n感谢使用，再见！\n");
            saveToFile(L1);  // 退出前保存图书信息到文件
            // 释放所有图书节点的内存
            while (L1 != NULL) {
                Llink temp = L1;
                L1 = L1->next;
                delete temp;
            }
            system("pause");
            return 0;  // 退出程序
        default:
            printf("\n！！！无效的选择！！！\n");
            system("pause");  // 如果输入无效的操作，提示并暂停
            break;
        }
    }
    return 0;
}
