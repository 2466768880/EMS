/***
 ***    员工管理系统相关实现文件
 **     包含
 **       class EMS
 **           void EMS::InitialReadFile();
 **           void EMS::InitialInterface();
 **           void EMS::Login();
 **           void EMS::Register();
 **           void EMS::GeneralInterface(string jni);
 **           void EMS::AdministratorInterface(EmpNode *emp);
 **           string EMS::Caesar(string pas);
***     的实现
***/
#include "EMS.h"
#include "employee.h"
#include <cstdlib>
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

//EMS类InitialReadFile方法
//作用：每次启动程序时读取账号密码与员工文件，将文件中的内容插入到两链表中
void EMS::InitialReadFile()
{
    //读取acc_pas_list
    ifstream fin;
    fin.open("AccPas.txt", ios_base::app);    //以追加方式打开文件
    string account, password, jni;
    //从文件中读取账户密码数据，插入链表中
    while (fin >> account && fin >> password && fin >> jni)
        acc_pas_list.AddToHead(account, password, jni);
    fin.close();
    //读取emp_list
    fin.open("Employee.txt", ios_base::app);
    Employee emp;
    while (fin >> emp.name && fin >> emp.job_number_interior && fin >> emp.job_number_external && fin >> emp.position && fin >> emp.rank && fin >> emp.department && fin >> emp.base_pay && fin>>emp.bonus && fin >> emp.real_wages && fin >> emp.whether_good)
        emp_list.AddToHead(emp);
}

//EMS类InitialInterface方法
//作用：启动程序后的初始界面
void EMS::InitialInterface()
{
    system("cls");
    string choose;
    cout << "        ---------------------------------------------        " << endl;
    cout << "        |              员工管理系统                 |        " << endl;
    cout << "        |        Employee Management System         |        " << endl;
    cout << "        |                                           |        " << endl;
    cout << "        |             author:ling Gao               |        " << endl;
    cout << "        |         E-mail:1044888819@qq.com          |        " << endl;
    cout << "        | Hunan Institute of Science and Technology |        " << endl;
    cout << "        |                                           |        " << endl;
    cout << "        |     1->登录      2->注册      3-退出      |        " << endl;
    cout << "        ---------------------------------------------        " << endl << endl;
    cout << "     =======> ";
    cin >> choose;
    switch (choose[0])
    {
    case '1':Login(); break;    //登录
    case '2':Register(); break;    //注册
    case '3':exit(0);    //退出
    default:InitialInterface();    //什么都不做
    }
}

//EMS类Login方法
//作用：登录员工管理系统
void EMS::Login()
{
    string account, password,jni;
    system("cls");
    cout << endl << "        >>>员工管理系统(Employee Management System)<<<" << endl << endl;
    cout << "        登录" << endl;
    cout << "    账户： ";
    cin >> account;
    cout << "    密码： ";
    cin >> password;
    if (acc_pas_list.APComparison(account, Caesar(password), jni))    //账号密码比对
        GeneralInterface(jni);
    else
    {
        system("cls");
        cout << endl << "        >>>账户或密码错误<<<" << endl << endl;
        system("pause");
        InitialInterface();
    }
}

//EMS类Register方法
//作用：注册新账户
void EMS::Register()
{
    string registration, account, password, jni;
    system("cls");
    cout << endl << "        >>>员工管理系统(Employee Management System)<<<" << endl << endl;
    cout << "        注册" << endl;
    cout << "    注册码（公司内部发放）（hnist）： ";
    cin >> registration;
    if (registration != "hnist")
    {
        system("cls");
        cout << endl << "        >>>注册码错误，不能注册<<<" << endl << endl;
        system("pause");
        InitialInterface();
    }
    system("cls");
    cout << endl << "        >>>员工管理系统(Employee Management System)<<<" << endl << endl;
    cout << "        注册" << endl;
    cout << "    账户： ";
    cin >> account;
    if (acc_pas_list.AccRechecking(account))    //账号查重
    {
        cout << endl << "        >>>此账户名已被注册，注册失败<<<" << endl << endl;
        system("pause");
        InitialInterface();
    }
    cout << "    工号内码（六位数字）： ";
    cin >> jni;
    if (acc_pas_list.JNIRechecking(jni))    //工号
    {
        cout << endl << "        >>>此员工工号已被注册，注册失败<<<" << endl << endl;
        system("pause");
        InitialInterface();
    }
    cout << "    密码（八位及以上数字或字符）： ";
    cin >> password;
    if (password.size() < 8)    //判断密码位数是否小于8
    {
        cout << endl << "        >>>密码为八位以下，注册失败<<<" << endl << endl;
        system("pause");
        InitialInterface();
    }
    //注册成功
    password = Caesar(password);
    acc_pas_list.AddToHead(account, password, jni);
    ofstream fout;
    fout.open("AccPas.txt", ios_base::app);    //以追加方式打开文件
    fout << account << " " << password << " " << jni << endl;    //向文件中写入账号密码工号数据
    fout.close();
    cout << endl << "        >>>注册成功<<<" << endl << endl;
    system("pause");
    InitialInterface();
}

//EMS类GeneralInterface方法
//作用：员工登录成功后进入的界面
void EMS::GeneralInterface(string jni)
{
    system("cls");
    string choose;
    EmpNode *emp = emp_list.SearchByJNI(jni);
    if (emp == 0)
    {
        cout << endl << "        >>>员工管理系统(Employee Management System)<<<" << endl;
        cout << "        >>>欢迎新员工 " << jni << "<<<" << endl << endl;
        cout << "    请准确完善个人信息" << endl;
        Employee emp;
        emp.SetInformation();
        emp.job_number_interior = jni;
        emp_list.AddToHead(emp);
        //写入文件
        ofstream fout;
        fout.open("Employee.txt", ios_base::app);    //以追加方式打开文件
        fout << emp.name << " " << jni << " " << emp.job_number_external << " " << emp.position << " " << emp.rank << " " << emp.department << " " << emp.base_pay << " " << emp.bonus << " " << emp.real_wages << " " << emp.whether_good << endl;
        fout.close();
        GeneralInterface(jni);
    }
    while (true)
    {
        system("cls");
        cout << "        ---------------------------------------------        " << endl;
        cout << "        |              员工管理系统                 |        " << endl;
        cout << "        |        Employee Management System         |        " << endl;
        cout << "        |                                           |        " << endl;
        cout << "        |              欢迎您，" << emp->info.job_number_interior << "               |        " << endl;    //
        cout << "        |                                           |        " << endl;
        cout << "        |              A->管理员界面                |        " << endl;
        cout << "        |    1->查看基本信息     2->更改基本信息    |        " << endl;
        cout << "        |    3->查看部门员工     4->工资信息        |        " << endl;
        cout << "        |    5->修改密码         6->注销            |        " << endl;
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
            cout << endl << "        >>>更改个人信息<<<" << endl;
            cout << "        >>>请选择更改选项<<<" << endl << endl;
            cout << "    1->更改姓名" << endl << "    2->更改工号内码" << endl << "    3->更改工号外码" << endl;
            cout << "    4->更改职务" << endl << "    5->更改职级" << endl << "    6->更改所属部门" << endl;
            cout << "    7->全部更改" << endl << "    8->返回" << endl;
            cout << "     =======> ";
            cin >> choose;
            switch (choose[0])
            {
            case '1':
            {
                cout << "    请输入姓名： ";
                cin >> emp->info.name;
                cout << endl << "        >>>更改成功<<<" << endl << endl;
                system("pause");
                break;
            }
            case '2':
            {
                cout << "    请输入工号内码： ";
                cin >> emp->info.job_number_interior;
                cout << endl << "        >>>更改成功<<<" << endl << endl;
                system("pause");
                break;
            }
            case '3':
            {
                cout << "    请输入工号外码： ";
                cin >> emp->info.job_number_external;
                cout << endl << "        >>>更改成功<<<" << endl << endl;
                system("pause");
                break;
            }
            case '4':
            {
                cout << "    请输入职务： ";
                cin >> emp->info.position;
                cout << endl << "        >>>更改成功<<<" << endl << endl;
                system("pause");
                break;
            }
            case '5':
            {
                cout << "    请输入职级： ";
                cin >> emp->info.rank;
                cout << endl << "        >>>更改成功<<<" << endl << endl;
                system("pause");
                break;
            }
            case '6':
            {
                cout << "    请输入所属部门： ";
                cin >> emp->info.department;
                cout << endl << "        >>>更改成功<<<" << endl << endl;
                system("pause");
                break;
            }
            case '7':
            {
                cout << endl << "        >>>更改个人信息<<<" << endl;
                cout << "    请准确完善个人信息" << endl;
                emp->info.SetInformation();
                break;
            }
            default:GeneralInterface(emp->info.job_number_interior);
            }
            if (choose[0] != '8')
            {
                ofstream fout;
                fout.open("Employee.txt", ios_base::app);    //以追加方式打开文件
                fout << emp->info.name << " " << emp->info.job_number_interior << " " << emp->info.job_number_external << " " << emp->info.position << " " << emp->info.rank << " " << emp->info.department << " " << emp->info.base_pay << " " << emp->info.bonus << " " << emp->info.real_wages << " " << emp->info.whether_good << endl;
                fout.close();
            }
            break;
        }
        case '3':
        {
            cout << endl << "        >>>部门员工如下<<<" << endl;
            emp_list.DisplaySameGroup(emp->info.department);
            system("pause");
            break;
        }
        case '4':
        {
            cout << endl << "        >>>工资明细如下<<<" << endl;
            cout << "    基本工资： " << emp->info.base_pay << endl;
            cout << "    实际收入（含奖金）： " << emp->info.real_wages << endl << endl;
            system("pause");
            break;
        }
        case '5':
        {
            string acc, pas, jni;
            cout << endl << "        >>>修改密码<<<" << endl;
            cout << "    请输入账户名： ";
            cin >> acc;
            cout << "    请输入原密码： ";
            cin >> pas;
            if (acc_pas_list.APComparison(acc, Caesar(pas), jni))    //账号密码比对
            {
                string newpas;
                cout << endl << "        >>>可以修改密码<<<" << endl;
                cout << "    请输入新密码： ";
                cin >> newpas;
                acc_pas_list.ChangePassword(acc, newpas);
                cout << "        >>>密码修改成功<<<" << endl << endl;
                ofstream fout;
                fout.open("AccPas.txt", ios_base::app);    //以追加方式打开文件
                fout << acc << " " << Caesar(newpas) << " " << jni << endl;    //向文件中写入账号密码工号数据
                fout.close();
                acc_pas_list.AddToHead(acc, Caesar(newpas), jni);
                system("pause");
            }
            else
            {
                cout << "        >>>账户或密码错误，不能修改密码<<<" << endl;
                system("pause");
            }
            break;
        }
        case '6':InitialInterface();
        }
    }
}

//EMS类AdministratorInterface方法
//作用：管理员界面
void EMS::AdministratorInterface(EmpNode *emp)
{
    if (emp->info.rank != 25)
    {
        cout << endl << "        >>>您不是公司管理层员工，无法使用管理员功能<<<" << endl << endl;
        system("pause");
        GeneralInterface(emp->info.job_number_interior);
    }
    string choose;
    while (1)
    {
        system("cls");
        cout << "        ---------------------------------------------        " << endl;
        cout << "        |              员工管理系统                 |        " << endl;
        cout << "        |        Employee Management System         |        " << endl;
        cout << "        |                                           |        " << endl;
        cout << "        |               管理员界面                  |        " << endl;
        cout << "        |                                           |        " << endl;
        cout << "        |             A->查看所有员工               |        " << endl;
        cout << "        |    1->查询员工信息     2->员工晋升        |        " << endl;
        cout << "        |    3->任免优秀员工     4->员工降级        |        " << endl;
        cout << "        |    5->解雇员工         6->返回            |        " << endl;
        cout << "        ---------------------------------------------        " << endl << endl;
        cout << "     =======> ";
        cin >> choose;
        switch (choose[0])
        {
        case 'A':
        {
            cout << endl << "        >>>公司全部员工一览表<<<" << endl << endl;
            emp_list.DisplayAll();
            system("pause");
            AdministratorInterface(emp);
            break;
        }
        case '1':    //查询员工信息
        {
            string cho;
            system("cls");
            cout << endl << "        >>>查询员工信息<<<" << endl;
            cout << "        >>>请选择查找方式<<<" << endl << endl;
            cout << "    1->按姓名查找" << endl << "    2->按工号内码查找" << endl << "    3->返回" << endl << endl;
            cout << "     =======> ";
            cin >> cho;
            if (cho[0] == '1')
            {
                string namee;
                system("cls");
                cout << endl << "        >>>查询员工信息<<<" << endl;
                cout << "        >>>按姓名查找<<<" << endl << endl;
                cout << "    请输入要查找的员工姓名： ";
                cin >> namee;
                emp_list.SDByName(namee);
                system("pause");
                AdministratorInterface(emp);
            }
            if (cho[0] == '2')
            {
                string jnii;
                system("cls");
                cout << endl << "        >>>查询员工信息<<<" << endl;
                cout << "        >>>按工号内码查找<<<" << endl << endl;
                cout << "    请输入要查找的员工工号内码： ";
                cin >> jnii;
                emp_list.SDByJNI(jnii);
                system("pause");
                AdministratorInterface(emp);
            }
            if (cho[0] == '3')
                AdministratorInterface(emp);
            break;
        }
        case '2':    //员工晋升
        {
            string namee, jnii;
            system("cls");
            cout << endl << "        >>>员工晋升<<<" << endl;
            cout << "        >>>请输入晋升员工的姓名和工号内码<<<" << endl << endl;
            cout << "    请输入姓名： ";
            cin >> namee;
            cout << "    请输入员工内码： ";
            cin >> jnii;
            emp_list.Promotion(namee, jnii);
            system("pause");
            AdministratorInterface(emp);
            break;
        }
        case '3':    //任免优秀员工
        {
            string namee, jnii;
            system("cls");
            cout << endl << "        >>>任免优秀员工<<<" << endl;
            cout << "        >>>请输入员工的姓名和工号内码<<<" << endl << endl;
            cout << "    请输入姓名： ";
            cin >> namee;
            cout << "    请输入员工内码： ";
            cin >> jnii;
            emp_list.Good(namee, jnii);
            system("pause");
            AdministratorInterface(emp);
            break;
        }
        case '4':    //员工降级
        {
            string namee, jnii;
            system("cls");
            cout << endl << "        >>>员工降级<<<" << endl;
            cout << "        >>>请输入降级员工的姓名和工号内码<<<" << endl << endl;
            cout << "    请输入姓名： ";
            cin >> namee;
            cout << "    请输入员工内码： ";
            cin >> jnii;
            emp_list.Demotion(namee, jnii);
            system("pause");
            AdministratorInterface(emp);
            break;
        }
        case '5':    //解雇员工
        {
            //工号内码置NNNNNN
            string namee, jnii;
            system("cls");
            cout << endl << "        >>>员工解雇<<<" << endl;
            cout << "        >>>请输入解雇员工的姓名和工号内码<<<" << endl << endl;
            cout << "    请输入姓名： ";
            cin >> namee;
            cout << "    请输入员工内码： ";
            cin >> jnii;
            emp_list.Dismissal(namee, jnii);
            system("pause");
            AdministratorInterface(emp);
            break;
        }
        case '6':GeneralInterface(emp->info.job_number_interior);    //返回
        }
        break;
    }
}

//EMS类Caesar方法
//作用：将密码pas进行凯撒加密，并返回加密后的密文
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