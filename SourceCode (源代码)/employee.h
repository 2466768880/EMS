/***
 ***    Ա�����ͷ�ļ�
 **     ����
 **         class Employee
 **         class EmpNode
 **         class EmpList
***     ������
***/
#pragma once
#include <string>
using namespace std;

class Employee
{
public:
    string name;    //����
    string job_number_interior;    //��������
    string job_number_external;    //��������
    string position;    //Ա��ְ��
    int rank;    //ְ��
    string department;    //��������
    double base_pay;    //��������
    double bonus;    //����
    double real_wages;    //ʵ������
    bool whether_good;    //�Ƿ�Ϊ����Ա��
    Employee();    //��ʼ��
    void SetInformation();    //����Ա����Ϣ
    void DisplayInformation();    //���Ա����Ϣ
};

class EmpNode    //Ա���ڵ�
{
public:
    Employee info;    //������
    EmpNode *next;    //ָ����
    //���캯��
    EmpNode() :next(0) {}
    EmpNode(Employee el, EmpNode *ptr = 0) :info(el), next(ptr) {}
};

class EmpList    //Ա������
{
private:
    EmpNode *head;    //ͷָ��
    EmpNode *tail;    //βָ��
public:
    //����˵����cpp�ļ�
    EmpList() :head(0), tail(0) {}    //���캯����ʼ��
    ~EmpList();    //��������
    int IsEmpty();    //�ж������Ƿ�Ϊ��
    void AddToHead(Employee);    //ͷ�巨��������
    EmpNode * SearchByJNI(string);    //�����������ѯ
    void DisplaySameGroup(string);    //��ʾͬ����Ա��
    void SDByName(string);    //�������������
    void SDByJNI(string);    //����������������
    void Promotion(string, string);    //����
    void Demotion(string, string);    //����
    void Dismissal(string, string);    //���
    void Good(string, string);    //����Ա��
    void DisplayAll();    //��ʾ����Ա��
};