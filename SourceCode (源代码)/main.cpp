/***
 ***    Ա������ϵͳ  Employee_Management_System
 **     ���� ������ѧԺ��Ϣ��ѧ�빤��ѧԺ �Ź�17-1BF �߿���
 **     ������� 2018��11��
 **     ��ϵ��ʽ QQ: 2701683381  Email: hnistgkx@vip.qq.com �� 1044888819@qq.com
 **     �ο��鼮
 **         C++ Primer Plus(��6��)    [��]Stephen Prata ��
 **         C++ ���ݽṹ���㷨(��4��)    [��]Adam Drozdek ��
 **
 **
***
***/
#include "EMS.h"    //Ա������ϵͳ���ͷ�ļ�
#include <memory>

int main(int argc,char *argv[])    //������
{
    //��EMS��ʵ�������Եõ�һ��Ա������ϵͳ
    //����ָ���ڱ������������ָͨ�벢����������
    std::auto_ptr<EMS> employee_management_system(new EMS);
    //��������ֵΪ0
    return 0;
}