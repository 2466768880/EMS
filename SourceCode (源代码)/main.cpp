/***
 ***    员工管理系统  Employee_Management_System
 **     作者 湖南理工学院信息科学与工程学院 信工17-1BF 高楷修
 **     完成日期 2018年11月
 **     联系方式 QQ: 2701683381  Email: hnistgkx@vip.qq.com 或 1044888819@qq.com
 **     参考书籍
 **         C++ Primer Plus(第6版)    [美]Stephen Prata 著
 **         C++ 数据结构与算法(第4版)    [美]Adam Drozdek 著
 **
 **
***
***/
#include "EMS.h"    //员工管理系统相关头文件
#include <memory>

int main(int argc,char *argv[])    //主函数
{
    //将EMS类实例化，以得到一个员工管理系统
    //智能指针在本程序中相比普通指针并无特殊作用
    std::auto_ptr<EMS> employee_management_system(new EMS);
    //函数返回值为0
    return 0;
}