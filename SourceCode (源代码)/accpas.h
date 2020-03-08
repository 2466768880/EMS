/***
 ***    账号密码相关头文件
 **     包含
 **         class AccPasNode
 **         class AccPasList
***     的声明
***/
#pragma once
#include <string>
using namespace std;

class AccPasNode    //账号密码节点
{
public:
    //数据域
    string account;    //账号
    string password_caesar;    //密码的加密值
    //指针域
    string job_number_interior;    //员工工号内码
    AccPasNode *next;    //next指针
    //构造函数初始化
    AccPasNode() :next(0) {}
    AccPasNode(string acc, string pas_caesar, string jni, AccPasNode *ptr = 0)
    {
        account = acc;
        password_caesar = pas_caesar;
        job_number_interior = jni;
        next = ptr;
    }
};

class AccPasList    //账号密码链表
{
private:
    AccPasNode *head;    //头指针
    AccPasNode *tail;    //尾指针
public:
    AccPasList() :head(0), tail(0) {}    //构造函数初始化
    ~AccPasList();    //析构函数释放内存空间
    int IsEmpty();    //判断链表是否为空
    void AddToHead(string, string, string);    //头插法插入账号密码
    bool APComparison(string, string, string&);    //账号密码比对
    bool AccRechecking(string);    //账号查重
    bool JNIRechecking(string);    //工号查重
    void ChangePassword(string, string);    //修改密码
};

