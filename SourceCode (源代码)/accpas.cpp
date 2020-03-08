/***
 ***    �˺��������ʵ���ļ�
 **     ����
 **       class AccPasList
 **           AccPasList::~AccPasList();
 **           int AccPasList::IsEmpty();
 **           void AccPasList::AddToHead(string acc, string pas_caesar, string jni);
 **           bool AccPasList::APComparison(string acc, string pas,string& jni);
 **           bool AccPasList::AccRechecking(string acc);
 **           bool AccPasList::JNIRechecking(string jni);
 **           void AccPasList::ChangePassword(string acc, string npw);
***     ��ʵ��
***/
#include "accpas.h"
#include <string>
using namespace std;

//AccPasList����������
//���ã��ڳ������ʱ�Զ����ã��ͷ��˺���������(AccPasList)ռ�õ��ڴ�ռ�
AccPasList::~AccPasList()
{
    for (AccPasNode *p; !IsEmpty();)
    {
        p = head->next;
        delete head;
        head = p;
    }
}

//AccPasList��IsEmpty����
//���ã��ж��˺���������(AccPasNode)�Ƿ�Ϊ�գ����Ϊ��������0����Ϊ�շ���1
int AccPasList::IsEmpty()
{
    return head == 0;
}

//AccPasList��AddToHead����
//���ã�ʹ��ͷ�巨�����˻�(acc)������Ŀ���ֵ(pas_caesar)��Ա����������(jni)���뵽�˺���������(AccPasList)��
void AccPasList::AddToHead(string acc, string pas_caesar, string jni)
{
    head = new AccPasNode(acc, pas_caesar, jni, head);
    if (tail == 0)
        tail = head;
}

//AccPasList��APComparison����
//���ã��ж��˻�(acc)������(pas)�Ƿ�ƥ�䣬�����ô˷����Ĵ�����д��뱾�������������ı���jni��Ϊƥ����Ա����������
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

//AccPasList��AccRechecking����
//���ã�ע��ʱ�ж�������˻���(acc)�Ƿ��ѱ�ע���������ѱ�ע����򷵻�true���������ע���򷵻�false
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

//AccPasList��JNIRechecking����
//���ã�ע��ʱ�ж�����Ĺ�������(jni)�Ƿ��ѱ�ע���������ѱ�ע����򷵻�true���������ע���򷵻�false
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

//AccPasList��ChangePassword����
//���ã����˺���������(AccPasList)���˻�acc������Ŀ���ֵ����Ϊnpw
void AccPasList::ChangePassword(string acc, string npw)
{
    AccPasNode *tmp;
    for (tmp = head; tmp != 0; tmp = tmp->next)
    {
        if (tmp->account == acc)
            tmp->password_caesar = npw;
    }
}
