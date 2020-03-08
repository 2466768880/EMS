/***
 ***    员工相关实现文件
 **     包含
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
***     的实现
***/
#include "employee.h"
#include <iostream>
#include <cstdlib>
#include <string>
#include <fstream>
using namespace std;

//Employee类无参构造函数
//作用：实例化Employee类时进行初始化，将类内成员置0
Employee::Employee()
{
    name = '0';
    job_number_interior = '0';
    job_number_external = '0';
    position = '0';
    rank = 0;
    base_pay = 6500;
    bonus = 0;
    whether_good = false;    //默认不是优秀员工，置false
    real_wages = 0;
}

//Employee类SetInformation方法
//作用：设置员工信息
void Employee::SetInformation()
{
    cout << "        请输入姓名： ";
    cin >> name;
    cout << "        请输入工号外码（六位数字或字母）： ";
    cin >> job_number_external;
    cout << "        请输入职务： ";
    cin >> position;
    cout << "        请输入职级： ";
    cin >> rank;
    cout << "        请输入所属部门： ";
    cin >> department;
    base_pay =6500 + (rank - 13) * 3500;    //基本工资为6500+(职级-13)x3500
    real_wages = base_pay;    //实际工资 = 基本工资
}

//Employee类DisplayInformation方法
//作用：显示员工信息
void Employee::DisplayInformation()
{
    cout << endl << "        >>>员工信息表<<<" << endl;
    cout << "    姓名： " << name << endl;
    cout << "    职务： " << position << endl;
    cout << "    职级： " << rank << endl;
    cout << "    所属部门： " << department << endl;
    cout << "    工号内码： " << job_number_interior << endl;
    cout << "    工号外码： " << job_number_external << endl;
    cout << "    基本工资： " << base_pay << endl;
    cout << "    实际收入（含奖金）： " << real_wages << endl;
    if (whether_good)    //如果weither_good为true，则显示优秀员工信息，否则不显示
        cout << "    >优秀员工<" << endl;
}

//EmpList类析构函数
//作用：在程序结束时自动调用，释放员工链表(EmpList)占用的内存空间
EmpList::~EmpList()
{
    for (EmpNode *p; !IsEmpty();)    //如果链表不为空（释放空间未完）
    {
        p = head->next;
        delete head;
        head = p;
    }
}

//EmpList类IsEmpty方法
//作用：判断员工链表(EmpList)是否为空，如果为空链表返回0，不为空返回1
int EmpList::IsEmpty()
{
    return head == 0;
}

//EmpList类AddToHead方法
//作用：使用头插法，将员工(Employee)对象el插入到员工链表(EmpList)中
void EmpList::AddToHead(Employee el)
{
    head = new EmpNode(el, head);
    if (tail == 0)
        tail = head;
}

//EmpList类SearchByJNI方法
//作用：在员工链表(EmpList)中查找工号内码(job_number_interior)为jni的员工，如果找到则返回此员工节点，未找到则返回空节点
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

//EmpList类DisplaySameGroup方法
//作用：在员工链表(EmpList)中查找所属部门(department)为dep的员工，并依次显示在屏幕上
void EmpList::DisplaySameGroup(string dep)
{
    string n_name[5000],s_name[5000],i_name[5000];    //存储被解雇员工与重复员工的姓名和工号
    int n = 0, s = 0, m = 0;
    int flagn = 0, flags = 0, flagi = 0;    //解雇判断器，重复判断器，工号判断器
    int count = 1;
    EmpNode *tmp;
    for (tmp = head; tmp != 0; tmp = tmp->next)
    {
        if (tmp->info.department == dep)
        {
            if (tmp->info.job_number_interior == "NNNNNN")    //将被解雇员工的姓名存至n_name
            {
                n_name[n] = tmp->info.name;
                n++;
            }
            for (int i = 0; i < m; i++)
            {
                if (tmp->info.job_number_interior == i_name[i])
                    flagi = 1;
            }
            for (int i = 0; i < n; i++)    //遍历n_name，如果查找到的员工是被解雇的员工，将判断器flagn置1
            {
                if (tmp->info.name == n_name[i])
                    flagn = 1;
            }
            for (int i = 0; i < s; i++)    //遍历s_name，如果查找到的员工已经显示过，将判断器flags置1
            {
                if (tmp->info.name == s_name[i])
                    flags = 1;
            }
            if (flagn == 0 && flags == 0 && flagi == 0)    //如果查找到的员工未被解雇也未显示过，则显示其信息
            {
                s_name[s] = tmp->info.name;    //将显示过的员工的姓名存至s_name中
                s++;
                i_name[m] = tmp->info.job_number_interior;
                m++;
                cout << "    " << count << ". " << tmp->info.name << "  " << tmp->info.job_number_interior << "  " << tmp->info.position << "  " << "职级：" << tmp->info.rank << "  " << tmp->info.department << endl;
                count++;
            }
            else    //将三个判断器置0，进行下一次循环查找
            {
                flagn = 0;
                flags = 0;
                flagi = 0;
            }
        }    
    }
}

//EmpList类SDByName方法
//作用：在员工链表(EmpList)中查找姓名为name的员工，如果找到则调用DisplayInformation方法显示员工信息
void EmpList::SDByName(string name)
{
    EmpNode *tmp;
    for (tmp = head; tmp != 0; tmp = tmp->next)
    {
        if (tmp->info.name == name)
        {
            if (tmp->info.job_number_interior == "NNNNNN")    //被解雇的员工，找到也不显示
                return;
            else
            {
                tmp->info.DisplayInformation();
                return;
            }
                
        }
    }
    //未找到
    cout << endl << "        >>>未找到此员工<<<" << endl << endl;
}

//EmpList类SDByJNI方法
//作用：在员工链表(EmpList)中查找工号内码为jni的员工，如果找到则调用DisplayInformation方法显示员工信息
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
    cout << endl << "        >>>未找到此员工<<<" << endl << endl;
}

//EmpList类Promotion方法
//作用：在员工链表(EmpList)中查找姓名为name且工号内码为jni的员工，如果找到则提高职级(rank)和工资
void EmpList::Promotion(string name, string jni)
{
    EmpNode *tmp;
    for (tmp = head; tmp != 0; tmp = tmp->next)
    {
        if (tmp->info.job_number_interior == jni && tmp->info.name == name)
        {
            tmp->info.bonus += 500;    //奖金+500
            if (tmp->info.rank != 25)
                tmp->info.rank += 1;    //如果不是最高职级(25)，职级+1
            tmp->info.base_pay += 3500;    //基本工资+3500
            tmp->info.real_wages = tmp->info.base_pay + tmp->info.bonus;    //重新计算实际工资
            AddToHead(tmp->info);    //将更改后的信息重写进链表
            //追加更新后的信息至文件
            ofstream fout;
            fout.open("Employee.txt", ios_base::app);    //以追加方式打开文件
            fout << tmp->info.name << " " << tmp->info.job_number_interior << " " << tmp->info.job_number_external << " " << tmp->info.position << " " << tmp->info.rank << " " << tmp->info.department << " " << tmp->info.base_pay << " " << tmp->info.bonus << " " << tmp->info.real_wages << " " << tmp->info.whether_good << endl;
            fout.close();
            cout << endl << "        >>>员工晋升成功<<<" << endl << endl;
            return;
        }
    }
    cout << endl << "        >>>员工姓名或工号内码输入错误，无法晋升<<<" << endl << endl;
}

//EmpList类Demotion方法
//作用：在员工链表(EmpList)中查找姓名为name且工号内码为jni的员工，如果找到则降低职级(rank)和工资
void EmpList::Demotion(string name, string jni)
{
    EmpNode *tmp;
    for (tmp = head; tmp != 0; tmp = tmp->next)
    {
        if (tmp->info.job_number_interior == jni && tmp->info.name == name)
        {
            //理解此部分请参照EmpList::Promotion方法的注释部分
            tmp->info.rank -= 1;
            tmp->info.base_pay -= 3500;
            tmp->info.real_wages = tmp->info.base_pay + tmp->info.bonus;
            AddToHead(tmp->info);
            ofstream fout;
            fout.open("Employee.txt", ios_base::app);    //以追加方式打开文件
            fout << tmp->info.name << " " << tmp->info.job_number_interior << " " << tmp->info.job_number_external << " " << tmp->info.position << " " << tmp->info.rank << " " << tmp->info.department << " " << tmp->info.base_pay << " " << tmp->info.bonus << " " << tmp->info.real_wages << " " << tmp->info.whether_good << endl;
            fout.close();
            cout << endl << "        >>>员工降级成功<<<" << endl << endl;
            return;
        }
    }
    cout << endl << "        >>>员工姓名或工号内码输入错误，无法降级<<<" << endl << endl;
}

//EmpList类Dismissal方法
//作用：在员工链表(EmpList)中查找姓名为name且工号内码为jni的员工，如果找到则解雇此员工（将工号内码置"NNNNNN"）
void EmpList::Dismissal(string name, string jni)
{
    EmpNode *tmp;
    for (tmp = head; tmp != 0; tmp = tmp->next)
    {
        if (tmp->info.job_number_interior == jni && tmp->info.name == name)
        {
            //理解此部分请参照EmpList::Promotion方法的注释部分
            tmp->info.job_number_interior = "NNNNNN";
            AddToHead(tmp->info);
            ofstream fout;
            fout.open("Employee.txt", ios_base::app);    //以追加方式打开文件
            fout << tmp->info.name << " " << tmp->info.job_number_interior << " " << tmp->info.job_number_external << " " << tmp->info.position << " " << tmp->info.rank << " " << tmp->info.department << " " << tmp->info.base_pay << " " << tmp->info.bonus << " " << tmp->info.real_wages << " " << tmp->info.whether_good << endl;
            fout.close();
            cout << endl << "        >>>已解雇员工<<<" << endl << endl;
        }
    }
    cout << endl << "        >>>员工姓名或工号内码输入错误，无法解雇<<<" << endl << endl;
}

//EmpList类Good方法
//作用：在员工链表(EmpList)中查找姓名为name且工号内码为jni的员工，如果找到则转置其优秀员工状态
void EmpList::Good(string name, string jni)
{
    EmpNode *tmp;
    for (tmp = head; tmp != 0; tmp = tmp->next)
    {
        if (tmp->info.job_number_interior == jni && tmp->info.name == name)
        {
            //如果是优秀员工，则转为普通员工
            //如果是普通员工，则转为优秀员工
            if (tmp->info.whether_good)
            {
                tmp->info.whether_good = false;
                cout << endl << "        >>>此员工为优秀员工，已调整为普通员工" << endl << endl;
            }
            else
            {
                tmp->info.whether_good = true;
                cout << endl << "        >>>此员工为普通员工，已调整为优秀员工" << endl << endl;
            }
            AddToHead(tmp->info);
            ofstream fout;
            fout.open("Employee.txt", ios_base::app);    //以追加方式打开文件
            fout << tmp->info.name << " " << tmp->info.job_number_interior << " " << tmp->info.job_number_external << " " << tmp->info.position << " " << tmp->info.rank << " " << tmp->info.department << " " << tmp->info.base_pay << " " << tmp->info.bonus << " " << tmp->info.real_wages << " " << tmp->info.whether_good << endl;
            fout.close();
            return;
        }
    }
    cout << endl << "        >>>员工姓名或工号内码输入错误，无法调整<<<" << endl << endl;
}

//EmpList类DisplayAll方法
//作用：显示员工链表(EmpList)中所有员工的基本数据
void EmpList::DisplayAll()
{
    string n_name[5000], s_name[5000], i_name[5000];    //存储被解雇员工与重复员工的姓名
    int n = 0, s = 0, m = 0;
    int flagn = 0, flags = 0, flagi = 0;    //解雇判断器，重复判断器
    int count = 1;
    EmpNode *tmp;
    for (tmp = head; tmp != 0; tmp = tmp->next)
    {
        if (tmp->info.job_number_interior == "NNNNNN")    //将被解雇员工的姓名存至n_name
        {
            n_name[n] = tmp->info.name;
            n++;
        }
        for (int i = 0; i < m; i++)
        {
            if (tmp->info.job_number_interior == i_name[i])
                flagi = 1;
        }
        for (int i = 0; i < n; i++)    //遍历n_name，如果查找到的员工是被解雇的员工，将判断器flagn置1
        {
            if (tmp->info.name == n_name[i])
                flagn = 1;
        }
        for (int i = 0; i < s; i++)    //遍历s_name，如果查找到的员工已经显示过，将判断器flags置1
        {
            if (tmp->info.name == s_name[i])
                flags = 1;
        }
        if (flagn == 0 && flags == 0 && flagi == 0)    //如果查找到的员工未被解雇也未显示过，则显示其信息
        {
            s_name[s] = tmp->info.name;    //将显示过的员工的姓名存至s_name中
            s++;
            i_name[m] = tmp->info.job_number_interior;
            m++;
            cout << "    " << count << ". " << tmp->info.name << "  " << tmp->info.job_number_interior << "  " << tmp->info.position << "  " << "职级：" << tmp->info.rank << "  " << tmp->info.department << endl;
            count++;
        }
        else    //将两个判断器置0，进行下一次循环查找
        {
            flagn = 0;
            flags = 0;
            flagi = 0;
        }
    }
}
