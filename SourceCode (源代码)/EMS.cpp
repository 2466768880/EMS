/***
 ***    Ա������ϵͳ���ʵ���ļ�
 **     ����
 **       class EMS
 **           void EMS::InitialReadFile();
 **           void EMS::InitialInterface();
 **           void EMS::Login();
 **           void EMS::Register();
 **           void EMS::GeneralInterface(string jni);
 **           void EMS::AdministratorInterface(EmpNode *emp);
 **           string EMS::Caesar(string pas);
***     ��ʵ��
***/
#include "EMS.h"
#include "employee.h"
#include <cstdlib>
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

//EMS��InitialReadFile����
//���ã�ÿ����������ʱ��ȡ�˺�������Ա���ļ������ļ��е����ݲ��뵽��������
void EMS::InitialReadFile()
{
    //��ȡacc_pas_list
    ifstream fin;
    fin.open("AccPas.txt", ios_base::app);    //��׷�ӷ�ʽ���ļ�
    string account, password, jni;
    //���ļ��ж�ȡ�˻��������ݣ�����������
    while (fin >> account && fin >> password && fin >> jni)
        acc_pas_list.AddToHead(account, password, jni);
    fin.close();
    //��ȡemp_list
    fin.open("Employee.txt", ios_base::app);
    Employee emp;
    while (fin >> emp.name && fin >> emp.job_number_interior && fin >> emp.job_number_external && fin >> emp.position && fin >> emp.rank && fin >> emp.department && fin >> emp.base_pay && fin>>emp.bonus && fin >> emp.real_wages && fin >> emp.whether_good)
        emp_list.AddToHead(emp);
}

//EMS��InitialInterface����
//���ã����������ĳ�ʼ����
void EMS::InitialInterface()
{
    system("cls");
    string choose;
    cout << "        ---------------------------------------------        " << endl;
    cout << "        |              Ա������ϵͳ                 |        " << endl;
    cout << "        |        Employee Management System         |        " << endl;
    cout << "        |                                           |        " << endl;
    cout << "        |             author:ling Gao               |        " << endl;
    cout << "        |         E-mail:1044888819@qq.com          |        " << endl;
    cout << "        | Hunan Institute of Science and Technology |        " << endl;
    cout << "        |                                           |        " << endl;
    cout << "        |     1->��¼      2->ע��      3-�˳�      |        " << endl;
    cout << "        ---------------------------------------------        " << endl << endl;
    cout << "     =======> ";
    cin >> choose;
    switch (choose[0])
    {
    case '1':Login(); break;    //��¼
    case '2':Register(); break;    //ע��
    case '3':exit(0);    //�˳�
    default:InitialInterface();    //ʲô������
    }
}

//EMS��Login����
//���ã���¼Ա������ϵͳ
void EMS::Login()
{
    string account, password,jni;
    system("cls");
    cout << endl << "        >>>Ա������ϵͳ(Employee Management System)<<<" << endl << endl;
    cout << "        ��¼" << endl;
    cout << "    �˻��� ";
    cin >> account;
    cout << "    ���룺 ";
    cin >> password;
    if (acc_pas_list.APComparison(account, Caesar(password), jni))    //�˺�����ȶ�
        GeneralInterface(jni);
    else
    {
        system("cls");
        cout << endl << "        >>>�˻����������<<<" << endl << endl;
        system("pause");
        InitialInterface();
    }
}

//EMS��Register����
//���ã�ע�����˻�
void EMS::Register()
{
    string registration, account, password, jni;
    system("cls");
    cout << endl << "        >>>Ա������ϵͳ(Employee Management System)<<<" << endl << endl;
    cout << "        ע��" << endl;
    cout << "    ע���루��˾�ڲ����ţ���hnist���� ";
    cin >> registration;
    if (registration != "hnist")
    {
        system("cls");
        cout << endl << "        >>>ע������󣬲���ע��<<<" << endl << endl;
        system("pause");
        InitialInterface();
    }
    system("cls");
    cout << endl << "        >>>Ա������ϵͳ(Employee Management System)<<<" << endl << endl;
    cout << "        ע��" << endl;
    cout << "    �˻��� ";
    cin >> account;
    if (acc_pas_list.AccRechecking(account))    //�˺Ų���
    {
        cout << endl << "        >>>���˻����ѱ�ע�ᣬע��ʧ��<<<" << endl << endl;
        system("pause");
        InitialInterface();
    }
    cout << "    �������루��λ���֣��� ";
    cin >> jni;
    if (acc_pas_list.JNIRechecking(jni))    //����
    {
        cout << endl << "        >>>��Ա�������ѱ�ע�ᣬע��ʧ��<<<" << endl << endl;
        system("pause");
        InitialInterface();
    }
    cout << "    ���루��λ���������ֻ��ַ����� ";
    cin >> password;
    if (password.size() < 8)    //�ж�����λ���Ƿ�С��8
    {
        cout << endl << "        >>>����Ϊ��λ���£�ע��ʧ��<<<" << endl << endl;
        system("pause");
        InitialInterface();
    }
    //ע��ɹ�
    password = Caesar(password);
    acc_pas_list.AddToHead(account, password, jni);
    ofstream fout;
    fout.open("AccPas.txt", ios_base::app);    //��׷�ӷ�ʽ���ļ�
    fout << account << " " << password << " " << jni << endl;    //���ļ���д���˺����빤������
    fout.close();
    cout << endl << "        >>>ע��ɹ�<<<" << endl << endl;
    system("pause");
    InitialInterface();
}

//EMS��GeneralInterface����
//���ã�Ա����¼�ɹ������Ľ���
void EMS::GeneralInterface(string jni)
{
    system("cls");
    string choose;
    EmpNode *emp = emp_list.SearchByJNI(jni);
    if (emp == 0)
    {
        cout << endl << "        >>>Ա������ϵͳ(Employee Management System)<<<" << endl;
        cout << "        >>>��ӭ��Ա�� " << jni << "<<<" << endl << endl;
        cout << "    ��׼ȷ���Ƹ�����Ϣ" << endl;
        Employee emp;
        emp.SetInformation();
        emp.job_number_interior = jni;
        emp_list.AddToHead(emp);
        //д���ļ�
        ofstream fout;
        fout.open("Employee.txt", ios_base::app);    //��׷�ӷ�ʽ���ļ�
        fout << emp.name << " " << jni << " " << emp.job_number_external << " " << emp.position << " " << emp.rank << " " << emp.department << " " << emp.base_pay << " " << emp.bonus << " " << emp.real_wages << " " << emp.whether_good << endl;
        fout.close();
        GeneralInterface(jni);
    }
    while (true)
    {
        system("cls");
        cout << "        ---------------------------------------------        " << endl;
        cout << "        |              Ա������ϵͳ                 |        " << endl;
        cout << "        |        Employee Management System         |        " << endl;
        cout << "        |                                           |        " << endl;
        cout << "        |              ��ӭ����" << emp->info.job_number_interior << "               |        " << endl;    //
        cout << "        |                                           |        " << endl;
        cout << "        |              A->����Ա����                |        " << endl;
        cout << "        |    1->�鿴������Ϣ     2->���Ļ�����Ϣ    |        " << endl;
        cout << "        |    3->�鿴����Ա��     4->������Ϣ        |        " << endl;
        cout << "        |    5->�޸�����         6->ע��            |        " << endl;
        cout << "        ---------------------------------------------        " << endl << endl;
        cout << "     =======> ";
        cin >> choose;
        switch (choose[0])
        {
        case 'A':AdministratorInterface(emp); break;
        case '1':emp->info.DisplayInformation(); system("pause"); break;
        case '2':
        {
            string choose;
            system("cls");
            cout << endl << "        >>>���ĸ�����Ϣ<<<" << endl;
            cout << "        >>>��ѡ�����ѡ��<<<" << endl << endl;
            cout << "    1->��������" << endl << "    2->���Ĺ�������" << endl << "    3->���Ĺ�������" << endl;
            cout << "    4->����ְ��" << endl << "    5->����ְ��" << endl << "    6->������������" << endl;
            cout << "    7->ȫ������" << endl << "    8->����" << endl;
            cout << "     =======> ";
            cin >> choose;
            switch (choose[0])
            {
            case '1':
            {
                cout << "    ������������ ";
                cin >> emp->info.name;
                cout << endl << "        >>>���ĳɹ�<<<" << endl << endl;
                system("pause");
                break;
            }
            case '2':
            {
                cout << "    �����빤�����룺 ";
                cin >> emp->info.job_number_interior;
                cout << endl << "        >>>���ĳɹ�<<<" << endl << endl;
                system("pause");
                break;
            }
            case '3':
            {
                cout << "    �����빤�����룺 ";
                cin >> emp->info.job_number_external;
                cout << endl << "        >>>���ĳɹ�<<<" << endl << endl;
                system("pause");
                break;
            }
            case '4':
            {
                cout << "    ������ְ�� ";
                cin >> emp->info.position;
                cout << endl << "        >>>���ĳɹ�<<<" << endl << endl;
                system("pause");
                break;
            }
            case '5':
            {
                cout << "    ������ְ���� ";
                cin >> emp->info.rank;
                cout << endl << "        >>>���ĳɹ�<<<" << endl << endl;
                system("pause");
                break;
            }
            case '6':
            {
                cout << "    �������������ţ� ";
                cin >> emp->info.department;
                cout << endl << "        >>>���ĳɹ�<<<" << endl << endl;
                system("pause");
                break;
            }
            case '7':
            {
                cout << endl << "        >>>���ĸ�����Ϣ<<<" << endl;
                cout << "    ��׼ȷ���Ƹ�����Ϣ" << endl;
                emp->info.SetInformation();
                break;
            }
            default:GeneralInterface(emp->info.job_number_interior);
            }
            if (choose[0] != '8')
            {
                ofstream fout;
                fout.open("Employee.txt", ios_base::app);    //��׷�ӷ�ʽ���ļ�
                fout << emp->info.name << " " << emp->info.job_number_interior << " " << emp->info.job_number_external << " " << emp->info.position << " " << emp->info.rank << " " << emp->info.department << " " << emp->info.base_pay << " " << emp->info.bonus << " " << emp->info.real_wages << " " << emp->info.whether_good << endl;
                fout.close();
            }
            break;
        }
        case '3':
        {
            cout << endl << "        >>>����Ա������<<<" << endl;
            emp_list.DisplaySameGroup(emp->info.department);
            system("pause");
            break;
        }
        case '4':
        {
            cout << endl << "        >>>������ϸ����<<<" << endl;
            cout << "    �������ʣ� " << emp->info.base_pay << endl;
            cout << "    ʵ�����루�����𣩣� " << emp->info.real_wages << endl << endl;
            system("pause");
            break;
        }
        case '5':
        {
            string acc, pas, jni;
            cout << endl << "        >>>�޸�����<<<" << endl;
            cout << "    �������˻����� ";
            cin >> acc;
            cout << "    ������ԭ���룺 ";
            cin >> pas;
            if (acc_pas_list.APComparison(acc, Caesar(pas), jni))    //�˺�����ȶ�
            {
                string newpas;
                cout << endl << "        >>>�����޸�����<<<" << endl;
                cout << "    �����������룺 ";
                cin >> newpas;
                acc_pas_list.ChangePassword(acc, newpas);
                cout << "        >>>�����޸ĳɹ�<<<" << endl << endl;
                ofstream fout;
                fout.open("AccPas.txt", ios_base::app);    //��׷�ӷ�ʽ���ļ�
                fout << acc << " " << Caesar(newpas) << " " << jni << endl;    //���ļ���д���˺����빤������
                fout.close();
                acc_pas_list.AddToHead(acc, Caesar(newpas), jni);
                system("pause");
            }
            else
            {
                cout << "        >>>�˻���������󣬲����޸�����<<<" << endl;
                system("pause");
            }
            break;
        }
        case '6':InitialInterface();
        }
    }
}

//EMS��AdministratorInterface����
//���ã�����Ա����
void EMS::AdministratorInterface(EmpNode *emp)
{
    if (emp->info.rank != 25)
    {
        cout << endl << "        >>>�����ǹ�˾�����Ա�����޷�ʹ�ù���Ա����<<<" << endl << endl;
        system("pause");
        GeneralInterface(emp->info.job_number_interior);
    }
    string choose;
    while (1)
    {
        system("cls");
        cout << "        ---------------------------------------------        " << endl;
        cout << "        |              Ա������ϵͳ                 |        " << endl;
        cout << "        |        Employee Management System         |        " << endl;
        cout << "        |                                           |        " << endl;
        cout << "        |               ����Ա����                  |        " << endl;
        cout << "        |                                           |        " << endl;
        cout << "        |             A->�鿴����Ա��               |        " << endl;
        cout << "        |    1->��ѯԱ����Ϣ     2->Ա������        |        " << endl;
        cout << "        |    3->��������Ա��     4->Ա������        |        " << endl;
        cout << "        |    5->���Ա��         6->����            |        " << endl;
        cout << "        ---------------------------------------------        " << endl << endl;
        cout << "     =======> ";
        cin >> choose;
        switch (choose[0])
        {
        case 'A':
        {
            cout << endl << "        >>>��˾ȫ��Ա��һ����<<<" << endl << endl;
            emp_list.DisplayAll();
            system("pause");
            AdministratorInterface(emp);
            break;
        }
        case '1':    //��ѯԱ����Ϣ
        {
            string cho;
            system("cls");
            cout << endl << "        >>>��ѯԱ����Ϣ<<<" << endl;
            cout << "        >>>��ѡ����ҷ�ʽ<<<" << endl << endl;
            cout << "    1->����������" << endl << "    2->�������������" << endl << "    3->����" << endl << endl;
            cout << "     =======> ";
            cin >> cho;
            if (cho[0] == '1')
            {
                string namee;
                system("cls");
                cout << endl << "        >>>��ѯԱ����Ϣ<<<" << endl;
                cout << "        >>>����������<<<" << endl << endl;
                cout << "    ������Ҫ���ҵ�Ա�������� ";
                cin >> namee;
                emp_list.SDByName(namee);
                system("pause");
                AdministratorInterface(emp);
            }
            if (cho[0] == '2')
            {
                string jnii;
                system("cls");
                cout << endl << "        >>>��ѯԱ����Ϣ<<<" << endl;
                cout << "        >>>�������������<<<" << endl << endl;
                cout << "    ������Ҫ���ҵ�Ա���������룺 ";
                cin >> jnii;
                emp_list.SDByJNI(jnii);
                system("pause");
                AdministratorInterface(emp);
            }
            if (cho[0] == '3')
                AdministratorInterface(emp);
            break;
        }
        case '2':    //Ա������
        {
            string namee, jnii;
            system("cls");
            cout << endl << "        >>>Ա������<<<" << endl;
            cout << "        >>>���������Ա���������͹�������<<<" << endl << endl;
            cout << "    ������������ ";
            cin >> namee;
            cout << "    ������Ա�����룺 ";
            cin >> jnii;
            emp_list.Promotion(namee, jnii);
            system("pause");
            AdministratorInterface(emp);
            break;
        }
        case '3':    //��������Ա��
        {
            string namee, jnii;
            system("cls");
            cout << endl << "        >>>��������Ա��<<<" << endl;
            cout << "        >>>������Ա���������͹�������<<<" << endl << endl;
            cout << "    ������������ ";
            cin >> namee;
            cout << "    ������Ա�����룺 ";
            cin >> jnii;
            emp_list.Good(namee, jnii);
            system("pause");
            AdministratorInterface(emp);
            break;
        }
        case '4':    //Ա������
        {
            string namee, jnii;
            system("cls");
            cout << endl << "        >>>Ա������<<<" << endl;
            cout << "        >>>�����뽵��Ա���������͹�������<<<" << endl << endl;
            cout << "    ������������ ";
            cin >> namee;
            cout << "    ������Ա�����룺 ";
            cin >> jnii;
            emp_list.Demotion(namee, jnii);
            system("pause");
            AdministratorInterface(emp);
            break;
        }
        case '5':    //���Ա��
        {
            //����������NNNNNN
            string namee, jnii;
            system("cls");
            cout << endl << "        >>>Ա�����<<<" << endl;
            cout << "        >>>��������Ա���������͹�������<<<" << endl << endl;
            cout << "    ������������ ";
            cin >> namee;
            cout << "    ������Ա�����룺 ";
            cin >> jnii;
            emp_list.Dismissal(namee, jnii);
            system("pause");
            AdministratorInterface(emp);
            break;
        }
        case '6':GeneralInterface(emp->info.job_number_interior);    //����
        }
        break;
    }
}

//EMS��Caesar����
//���ã�������pas���п������ܣ������ؼ��ܺ������
string EMS::Caesar(string pas)
{
    for (int i = 0; i < pas.size(); i++)
    {
        if (pas[i] >= 'A' && pas[i] <= 'Z')
            pas[i] = ((pas[i] - 'A') + 6) % 26 + pas[i];
        else if (pas[i] >= 'a' && pas[i] <= 'z')
            pas[i] = ((pas[i] - 'a') + 6) % 26 + pas[i];
        else if (pas[i] >= '0' && pas[i] <= '9')
            pas[i] = ((pas[i] - '0') + 6) % 26 + pas[i];
    }
    return pas;
}