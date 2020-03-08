/***
 ***    Ա������ϵͳ���ͷ�ļ�
 **     ����
 **         class EMS
***     ������
***/
#pragma once
#include "accpas.h"    //�˺��������ͷ�ļ�
#include "employee.h"    //Ա�����ͷ�ļ�

class EMS    //Ա������ϵͳ
{
private:
    AccPasList acc_pas_list;    //�˺���������
    EmpList emp_list;    //Ա������
public:
    EMS() { InitialReadFile(); InitialInterface(); }    //���캯����ʼ��
    void InitialReadFile();    //��ʼ�ļ���ȡ
    void InitialInterface();    //��ʼ����
    void Login();    //��¼
    void Register();    //ע��
    void GeneralInterface(string);    //Ա������
    void AdministratorInterface(EmpNode*);    //����Ա���� ֻ�ܱ�LeadershipInterface��������
    string Caesar(string pas);    //��������
};