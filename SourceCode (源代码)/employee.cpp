/***
 ***    Ա�����ʵ���ļ�
 **     ����
 **       class Employee
 **           Employee::Employee();
 **           void Employee::SetInformation();
 **           void Employee::DisplayInformation();
 **       class EmpList
 **           EmpList::~EmpList();
 **           int EmpList::IsEmpty();
 **           void EmpList::AddToHead(Employee el);
 **           EmpNode* EmpList::SearchByJNI(string jni);
 **           void EmpList::DisplaySameGroup(string dep);
 **           void EmpList::SDByName(string name);
 **           void EmpList::SDByJNI(string jni);
 **           void EmpList::Promotion(string name, string jni);
 **           void EmpList::Demotion(string name, string jni);
 **           void EmpList::Dismissal(string name, string jni);
 **           void EmpList::Good(string name, string jni);
 **           void EmpList::DisplayAll();
***     ��ʵ��
***/
#include "employee.h"
#include <iostream>
#include <cstdlib>
#include <string>
#include <fstream>
using namespace std;

//Employee���޲ι��캯��
//���ã�ʵ����Employee��ʱ���г�ʼ���������ڳ�Ա��0
Employee::Employee()
{
    name = '0';
    job_number_interior = '0';
    job_number_external = '0';
    position = '0';
    rank = 0;
    base_pay = 6500;
    bonus = 0;
    whether_good = false;    //Ĭ�ϲ�������Ա������false
    real_wages = 0;
}

//Employee��SetInformation����
//���ã�����Ա����Ϣ
void Employee::SetInformation()
{
    cout << "        ������������ ";
    cin >> name;
    cout << "        �����빤�����루��λ���ֻ���ĸ���� ";
    cin >> job_number_external;
    cout << "        ������ְ�� ";
    cin >> position;
    cout << "        ������ְ���� ";
    cin >> rank;
    cout << "        �������������ţ� ";
    cin >> department;
    base_pay =6500 + (rank - 13) * 3500;    //��������Ϊ6500+(ְ��-13)x3500
    real_wages = base_pay;    //ʵ�ʹ��� = ��������
}

//Employee��DisplayInformation����
//���ã���ʾԱ����Ϣ
void Employee::DisplayInformation()
{
    cout << endl << "        >>>Ա����Ϣ��<<<" << endl;
    cout << "    ������ " << name << endl;
    cout << "    ְ�� " << position << endl;
    cout << "    ְ���� " << rank << endl;
    cout << "    �������ţ� " << department << endl;
    cout << "    �������룺 " << job_number_interior << endl;
    cout << "    �������룺 " << job_number_external << endl;
    cout << "    �������ʣ� " << base_pay << endl;
    cout << "    ʵ�����루�����𣩣� " << real_wages << endl;
    if (whether_good)    //���weither_goodΪtrue������ʾ����Ա����Ϣ��������ʾ
        cout << "    >����Ա��<" << endl;
}

//EmpList����������
//���ã��ڳ������ʱ�Զ����ã��ͷ�Ա������(EmpList)ռ�õ��ڴ�ռ�
EmpList::~EmpList()
{
    for (EmpNode *p; !IsEmpty();)    //�������Ϊ�գ��ͷſռ�δ�꣩
    {
        p = head->next;
        delete head;
        head = p;
    }
}

//EmpList��IsEmpty����
//���ã��ж�Ա������(EmpList)�Ƿ�Ϊ�գ����Ϊ��������0����Ϊ�շ���1
int EmpList::IsEmpty()
{
    return head == 0;
}

//EmpList��AddToHead����
//���ã�ʹ��ͷ�巨����Ա��(Employee)����el���뵽Ա������(EmpList)��
void EmpList::AddToHead(Employee el)
{
    head = new EmpNode(el, head);
    if (tail == 0)
        tail = head;
}

//EmpList��SearchByJNI����
//���ã���Ա������(EmpList)�в��ҹ�������(job_number_interior)Ϊjni��Ա��������ҵ��򷵻ش�Ա���ڵ㣬δ�ҵ��򷵻ؿսڵ�
EmpNode * EmpList::SearchByJNI(string jni)
{
    EmpNode *tmp;
    for (tmp = head; tmp != 0; tmp = tmp->next)
    {
        if (tmp->info.job_number_interior == jni)
            return tmp;
    }
    return tmp;
}

//EmpList��DisplaySameGroup����
//���ã���Ա������(EmpList)�в�����������(department)Ϊdep��Ա������������ʾ����Ļ��
void EmpList::DisplaySameGroup(string dep)
{
    string n_name[5000],s_name[5000],i_name[5000];    //�洢�����Ա�����ظ�Ա���������͹���
    int n = 0, s = 0, m = 0;
    int flagn = 0, flags = 0, flagi = 0;    //����ж������ظ��ж����������ж���
    int count = 1;
    EmpNode *tmp;
    for (tmp = head; tmp != 0; tmp = tmp->next)
    {
        if (tmp->info.department == dep)
        {
            if (tmp->info.job_number_interior == "NNNNNN")    //�������Ա������������n_name
            {
                n_name[n] = tmp->info.name;
                n++;
            }
            for (int i = 0; i < m; i++)
            {
                if (tmp->info.job_number_interior == i_name[i])
                    flagi = 1;
            }
            for (int i = 0; i < n; i++)    //����n_name��������ҵ���Ա���Ǳ���͵�Ա�������ж���flagn��1
            {
                if (tmp->info.name == n_name[i])
                    flagn = 1;
            }
            for (int i = 0; i < s; i++)    //����s_name��������ҵ���Ա���Ѿ���ʾ�������ж���flags��1
            {
                if (tmp->info.name == s_name[i])
                    flags = 1;
            }
            if (flagn == 0 && flags == 0 && flagi == 0)    //������ҵ���Ա��δ�����Ҳδ��ʾ��������ʾ����Ϣ
            {
                s_name[s] = tmp->info.name;    //����ʾ����Ա������������s_name��
                s++;
                i_name[m] = tmp->info.job_number_interior;
                m++;
                cout << "    " << count << ". " << tmp->info.name << "  " << tmp->info.job_number_interior << "  " << tmp->info.position << "  " << "ְ����" << tmp->info.rank << "  " << tmp->info.department << endl;
                count++;
            }
            else    //�������ж�����0��������һ��ѭ������
            {
                flagn = 0;
                flags = 0;
                flagi = 0;
            }
        }    
    }
}

//EmpList��SDByName����
//���ã���Ա������(EmpList)�в�������Ϊname��Ա��������ҵ������DisplayInformation������ʾԱ����Ϣ
void EmpList::SDByName(string name)
{
    EmpNode *tmp;
    for (tmp = head; tmp != 0; tmp = tmp->next)
    {
        if (tmp->info.name == name)
        {
            if (tmp->info.job_number_interior == "NNNNNN")    //����͵�Ա�����ҵ�Ҳ����ʾ
                return;
            else
            {
                tmp->info.DisplayInformation();
                return;
            }
                
        }
    }
    //δ�ҵ�
    cout << endl << "        >>>δ�ҵ���Ա��<<<" << endl << endl;
}

//EmpList��SDByJNI����
//���ã���Ա������(EmpList)�в��ҹ�������Ϊjni��Ա��������ҵ������DisplayInformation������ʾԱ����Ϣ
void EmpList::SDByJNI(string jni)
{
    EmpNode *tmp;
    for (tmp = head; tmp != 0; tmp = tmp->next)
    {
        if (tmp->info.job_number_interior == jni)
        {
            tmp->info.DisplayInformation();
            return;
        }
    }
    cout << endl << "        >>>δ�ҵ���Ա��<<<" << endl << endl;
}

//EmpList��Promotion����
//���ã���Ա������(EmpList)�в�������Ϊname�ҹ�������Ϊjni��Ա��������ҵ������ְ��(rank)�͹���
void EmpList::Promotion(string name, string jni)
{
    EmpNode *tmp;
    for (tmp = head; tmp != 0; tmp = tmp->next)
    {
        if (tmp->info.job_number_interior == jni && tmp->info.name == name)
        {
            tmp->info.bonus += 500;    //����+500
            if (tmp->info.rank != 25)
                tmp->info.rank += 1;    //����������ְ��(25)��ְ��+1
            tmp->info.base_pay += 3500;    //��������+3500
            tmp->info.real_wages = tmp->info.base_pay + tmp->info.bonus;    //���¼���ʵ�ʹ���
            AddToHead(tmp->info);    //�����ĺ����Ϣ��д������
            //׷�Ӹ��º����Ϣ���ļ�
            ofstream fout;
            fout.open("Employee.txt", ios_base::app);    //��׷�ӷ�ʽ���ļ�
            fout << tmp->info.name << " " << tmp->info.job_number_interior << " " << tmp->info.job_number_external << " " << tmp->info.position << " " << tmp->info.rank << " " << tmp->info.department << " " << tmp->info.base_pay << " " << tmp->info.bonus << " " << tmp->info.real_wages << " " << tmp->info.whether_good << endl;
            fout.close();
            cout << endl << "        >>>Ա�������ɹ�<<<" << endl << endl;
            return;
        }
    }
    cout << endl << "        >>>Ա�������򹤺�������������޷�����<<<" << endl << endl;
}

//EmpList��Demotion����
//���ã���Ա������(EmpList)�в�������Ϊname�ҹ�������Ϊjni��Ա��������ҵ��򽵵�ְ��(rank)�͹���
void EmpList::Demotion(string name, string jni)
{
    EmpNode *tmp;
    for (tmp = head; tmp != 0; tmp = tmp->next)
    {
        if (tmp->info.job_number_interior == jni && tmp->info.name == name)
        {
            //���˲��������EmpList::Promotion������ע�Ͳ���
            tmp->info.rank -= 1;
            tmp->info.base_pay -= 3500;
            tmp->info.real_wages = tmp->info.base_pay + tmp->info.bonus;
            AddToHead(tmp->info);
            ofstream fout;
            fout.open("Employee.txt", ios_base::app);    //��׷�ӷ�ʽ���ļ�
            fout << tmp->info.name << " " << tmp->info.job_number_interior << " " << tmp->info.job_number_external << " " << tmp->info.position << " " << tmp->info.rank << " " << tmp->info.department << " " << tmp->info.base_pay << " " << tmp->info.bonus << " " << tmp->info.real_wages << " " << tmp->info.whether_good << endl;
            fout.close();
            cout << endl << "        >>>Ա�������ɹ�<<<" << endl << endl;
            return;
        }
    }
    cout << endl << "        >>>Ա�������򹤺�������������޷�����<<<" << endl << endl;
}

//EmpList��Dismissal����
//���ã���Ա������(EmpList)�в�������Ϊname�ҹ�������Ϊjni��Ա��������ҵ����ʹ�Ա����������������"NNNNNN"��
void EmpList::Dismissal(string name, string jni)
{
    EmpNode *tmp;
    for (tmp = head; tmp != 0; tmp = tmp->next)
    {
        if (tmp->info.job_number_interior == jni && tmp->info.name == name)
        {
            //���˲��������EmpList::Promotion������ע�Ͳ���
            tmp->info.job_number_interior = "NNNNNN";
            AddToHead(tmp->info);
            ofstream fout;
            fout.open("Employee.txt", ios_base::app);    //��׷�ӷ�ʽ���ļ�
            fout << tmp->info.name << " " << tmp->info.job_number_interior << " " << tmp->info.job_number_external << " " << tmp->info.position << " " << tmp->info.rank << " " << tmp->info.department << " " << tmp->info.base_pay << " " << tmp->info.bonus << " " << tmp->info.real_wages << " " << tmp->info.whether_good << endl;
            fout.close();
            cout << endl << "        >>>�ѽ��Ա��<<<" << endl << endl;
        }
    }
    cout << endl << "        >>>Ա�������򹤺�������������޷����<<<" << endl << endl;
}

//EmpList��Good����
//���ã���Ա������(EmpList)�в�������Ϊname�ҹ�������Ϊjni��Ա��������ҵ���ת��������Ա��״̬
void EmpList::Good(string name, string jni)
{
    EmpNode *tmp;
    for (tmp = head; tmp != 0; tmp = tmp->next)
    {
        if (tmp->info.job_number_interior == jni && tmp->info.name == name)
        {
            //���������Ա������תΪ��ͨԱ��
            //�������ͨԱ������תΪ����Ա��
            if (tmp->info.whether_good)
            {
                tmp->info.whether_good = false;
                cout << endl << "        >>>��Ա��Ϊ����Ա�����ѵ���Ϊ��ͨԱ��" << endl << endl;
            }
            else
            {
                tmp->info.whether_good = true;
                cout << endl << "        >>>��Ա��Ϊ��ͨԱ�����ѵ���Ϊ����Ա��" << endl << endl;
            }
            AddToHead(tmp->info);
            ofstream fout;
            fout.open("Employee.txt", ios_base::app);    //��׷�ӷ�ʽ���ļ�
            fout << tmp->info.name << " " << tmp->info.job_number_interior << " " << tmp->info.job_number_external << " " << tmp->info.position << " " << tmp->info.rank << " " << tmp->info.department << " " << tmp->info.base_pay << " " << tmp->info.bonus << " " << tmp->info.real_wages << " " << tmp->info.whether_good << endl;
            fout.close();
            return;
        }
    }
    cout << endl << "        >>>Ա�������򹤺�������������޷�����<<<" << endl << endl;
}

//EmpList��DisplayAll����
//���ã���ʾԱ������(EmpList)������Ա���Ļ�������
void EmpList::DisplayAll()
{
    string n_name[5000], s_name[5000], i_name[5000];    //�洢�����Ա�����ظ�Ա��������
    int n = 0, s = 0, m = 0;
    int flagn = 0, flags = 0, flagi = 0;    //����ж������ظ��ж���
    int count = 1;
    EmpNode *tmp;
    for (tmp = head; tmp != 0; tmp = tmp->next)
    {
        if (tmp->info.job_number_interior == "NNNNNN")    //�������Ա������������n_name
        {
            n_name[n] = tmp->info.name;
            n++;
        }
        for (int i = 0; i < m; i++)
        {
            if (tmp->info.job_number_interior == i_name[i])
                flagi = 1;
        }
        for (int i = 0; i < n; i++)    //����n_name��������ҵ���Ա���Ǳ���͵�Ա�������ж���flagn��1
        {
            if (tmp->info.name == n_name[i])
                flagn = 1;
        }
        for (int i = 0; i < s; i++)    //����s_name��������ҵ���Ա���Ѿ���ʾ�������ж���flags��1
        {
            if (tmp->info.name == s_name[i])
                flags = 1;
        }
        if (flagn == 0 && flags == 0 && flagi == 0)    //������ҵ���Ա��δ�����Ҳδ��ʾ��������ʾ����Ϣ
        {
            s_name[s] = tmp->info.name;    //����ʾ����Ա������������s_name��
            s++;
            i_name[m] = tmp->info.job_number_interior;
            m++;
            cout << "    " << count << ". " << tmp->info.name << "  " << tmp->info.job_number_interior << "  " << tmp->info.position << "  " << "ְ����" << tmp->info.rank << "  " << tmp->info.department << endl;
            count++;
        }
        else    //�������ж�����0��������һ��ѭ������
        {
            flagn = 0;
            flags = 0;
            flagi = 0;
        }
    }
}
