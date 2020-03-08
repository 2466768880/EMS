/***
 ***    �˺��������ͷ�ļ�
 **     ����
 **         class AccPasNode
 **         class AccPasList
***     ������
***/
#pragma once
#include <string>
using namespace std;

class AccPasNode    //�˺�����ڵ�
{
public:
    //������
    string account;    //�˺�
    string password_caesar;    //����ļ���ֵ
    //ָ����
    string job_number_interior;    //Ա����������
    AccPasNode *next;    //nextָ��
    //���캯����ʼ��
    AccPasNode() :next(0) {}
    AccPasNode(string acc, string pas_caesar, string jni, AccPasNode *ptr = 0)
    {
        account = acc;
        password_caesar = pas_caesar;
        job_number_interior = jni;
        next = ptr;
    }
};

class AccPasList    //�˺���������
{
private:
    AccPasNode *head;    //ͷָ��
    AccPasNode *tail;    //βָ��
public:
    AccPasList() :head(0), tail(0) {}    //���캯����ʼ��
    ~AccPasList();    //���������ͷ��ڴ�ռ�
    int IsEmpty();    //�ж������Ƿ�Ϊ��
    void AddToHead(string, string, string);    //ͷ�巨�����˺�����
    bool APComparison(string, string, string&);    //�˺�����ȶ�
    bool AccRechecking(string);    //�˺Ų���
    bool JNIRechecking(string);    //���Ų���
    void ChangePassword(string, string);    //�޸�����
};

