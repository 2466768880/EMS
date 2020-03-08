/***
 ***    员工相关头文件
 **     包含
 **         class Employee
 **         class EmpNode
 **         class EmpList
***     的声明
***/
#pragma once
#include <string>
using namespace std;

class Employee
{
public:
    string name;    //姓名
    string job_number_interior;    //工号内码
    string job_number_external;    //工号外码
    string position;    //员工职务
    int rank;    //职级
    string department;    //所属部门
    double base_pay;    //基本工资
    double bonus;    //奖金
    double real_wages;    //实际收入
    bool whether_good;    //是否为优秀员工
    Employee();    //初始化
    void SetInformation();    //设置员工信息
    void DisplayInformation();    //输出员工信息
};

class EmpNode    //员工节点
{
public:
    Employee info;    //数据域
    EmpNode *next;    //指针域
    //构造函数
    EmpNode() :next(0) {}
    EmpNode(Employee el, EmpNode *ptr = 0) :info(el), next(ptr) {}
};

class EmpList    //员工链表
{
private:
    EmpNode *head;    //头指针
    EmpNode *tail;    //尾指针
public:
    //具体说明见cpp文件
    EmpList() :head(0), tail(0) {}    //构造函数初始化
    ~EmpList();    //析构函数
    int IsEmpty();    //判断链表是否为空
    void AddToHead(Employee);    //头插法插入数据
    EmpNode * SearchByJNI(string);    //按工号内码查询
    void DisplaySameGroup(string);    //显示同部门员工
    void SDByName(string);    //按姓名查找输出
    void SDByJNI(string);    //按工号内码查找输出
    void Promotion(string, string);    //晋升
    void Demotion(string, string);    //降级
    void Dismissal(string, string);    //解雇
    void Good(string, string);    //优秀员工
    void DisplayAll();    //显示所有员工
};