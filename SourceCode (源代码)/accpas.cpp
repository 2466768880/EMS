/***
 ***    账号密码相关实现文件
 **     包含
 **       class AccPasList
 **           AccPasList::~AccPasList();
 **           int AccPasList::IsEmpty();
 **           void AccPasList::AddToHead(string acc, string pas_caesar, string jni);
 **           bool AccPasList::APComparison(string acc, string pas,string& jni);
 **           bool AccPasList::AccRechecking(string acc);
 **           bool AccPasList::JNIRechecking(string jni);
 **           void AccPasList::ChangePassword(string acc, string npw);
***     的实现
***/
#include "accpas.h"
#include <string>
using namespace std;

//AccPasList类析构函数
//作用：在程序结束时自动调用，释放账号密码链表(AccPasList)占用的内存空间
AccPasList::~AccPasList()
{
    for (AccPasNode *p; !IsEmpty();)
    {
        p = head->next;
        delete head;
        head = p;
    }
}

//AccPasList类IsEmpty方法
//作用：判断账号密码链表(AccPasNode)是否为空，如果为空链表返回0，不为空返回1
int AccPasList::IsEmpty()
{
    return head == 0;
}

//AccPasList类AddToHead方法
//作用：使用头插法，将账户(acc)、密码的凯撒值(pas_caesar)和员工工号内码(jni)插入到账号密码链表(AccPasList)中
void AccPasList::AddToHead(string acc, string pas_caesar, string jni)
{
    head = new AccPasNode(acc, pas_caesar, jni, head);
    if (tail == 0)
        tail = head;
}

//AccPasList类APComparison方法
//作用：判断账户(acc)和密码(pas)是否匹配，将调用此方法的代码块中传入本方法第三参数的变量jni改为匹配后的员工工号内码
bool AccPasList::APComparison(string acc, string pas,string& jni)
{
    AccPasNode *tmp;
    for (tmp = head; tmp != 0; tmp = tmp->next)
    {
        if ((tmp->account == acc) && (tmp->password_caesar == pas))
        {
            jni = tmp->job_number_interior;
            return true;
        }  
    }
    return false;
}

//AccPasList类AccRechecking方法
//作用：注册时判断输入的账户名(acc)是否已被注册过，如果已被注册过则返回true，如果可以注册则返回false
bool AccPasList::AccRechecking(string acc)
{
    AccPasNode *tmp;
    for (tmp = head; tmp != 0; tmp = tmp->next)
    {
        if (tmp->account == acc)
            return true;
    }
    return false;
}

//AccPasList类JNIRechecking方法
//作用：注册时判断输入的工号内码(jni)是否已被注册过，如果已被注册过则返回true，如果可以注册则返回false
bool AccPasList::JNIRechecking(string jni)
{
    AccPasNode *tmp;
    for (tmp = head; tmp != 0; tmp = tmp->next)
    {
        if (tmp->job_number_interior==jni)
            return true;
    }
    return false;
}

//AccPasList类ChangePassword方法
//作用：将账号密码链表(AccPasList)中账户acc的密码的凯撒值更改为npw
void AccPasList::ChangePassword(string acc, string npw)
{
    AccPasNode *tmp;
    for (tmp = head; tmp != 0; tmp = tmp->next)
    {
        if (tmp->account == acc)
            tmp->password_caesar = npw;
    }
}
