/***
 ***    员工管理系统相关头文件
 **     包含
 **         class EMS
***     的声明
***/
#pragma once
#include "accpas.h"    //账号密码相关头文件
#include "employee.h"    //员工相关头文件

class EMS    //员工管理系统
{
private:
    AccPasList acc_pas_list;    //账号密码链表
    EmpList emp_list;    //员工链表
public:
    EMS() { InitialReadFile(); InitialInterface(); }    //构造函数初始化
    void InitialReadFile();    //初始文件读取
    void InitialInterface();    //初始界面
    void Login();    //登录
    void Register();    //注册
    void GeneralInterface(string);    //员工界面
    void AdministratorInterface(EmpNode*);    //管理员界面 只能被LeadershipInterface方法调用
    string Caesar(string pas);    //凯撒加密
};