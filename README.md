# 员工管理系统 (Employee Management System / EMS)

> 学校 - HNIST (湖南理工学院)  
> 作者 - Ling Gao (高楷修)  
> 许可证 - MIT License (麻省理工学院许可证)
---
<a href="https://996.icu"><img src="https://img.shields.io/badge/link-996.icu-red.svg" alt="996.icu"></a>
[![HitCount](http://hits.dwyl.com/lingggao/EMS.svg)](http://hits.dwyl.com/lingggao/EMS)

**这个是我在大学二年级时使用 C++ 写的一个控制台员工管理系统 (Employee management system)。虽然现在它看起来非常的简陋，但是在当时，我是花费了很多的时间与精力来认真完成的这个作品，这个作品可以代表我在大学二年级时的最高编程水平。**
---
## 主要功能与特性
**虽然程序比较简陋，不过基本的功能还是非常完备的 :satisfied:**

- **程序结束时数据不会丢失**
  - 所有的员工信息都存放在程序所在路径下的 Employee 文件中
  - 所有的账户密码信息都加密后存放在 AccPas 文件中
  - ~~表面加密，密码其实很容易破解~~
- **注册账户**
  - 注册账户时需要输入由企业发放的注册码 (可以避免非企业员工注册账户)
  - 密码必须为 8 位以上，否则不允许注册
  - 可以判断某个账户是否已经被注册
- **登录账户**
  - 注册账户后第一次登录时需要补全个人详细信息
- **快速的注销账户与退出程序**
- **虽然不算好看，但是也不是很丑的界面设计 (控制台程序，理解万岁)**
- **企业普通员工可以使用的功能**
  - 查看个人资料
  - 修改个人资料
  - 浏览本部门员工
  - 查看工资信息
  - 修改账户密码
 - **企业高级管理人员可以使用的功能**
    - 普通员工可以使用的所有功能
    - 浏览企业所有员工
    - 单独查询某个员工的详细信息
      - 通过姓名查询
      - 通过工号查询
    - 调整员工的晋升与降级
    - 任免优秀员工
    - 解雇员工
---
## 项目结构
**当时不知道是怎么想的，把完整的员工管理系统拆分成了 3 个头文件，分别进行了系统主体、账户密码、员工信息相关功能的实现，因此看起来非常混乱。还请大家理解 :satisfied:**

- **README.md (主文档)**
- **LICENSE (许可证)**
- **员工管理系统.exe (应用程序)**
- **ProgramScreenshot (程序截图)**
- **Precautions (注意事项)**
  - 关于账户与密码.md
  - 程序说明.md
- **SourceCode (源代码)**
  - main.cpp (主函数)
  - **EMS Class (系统类，是员工管理系统的框架)**
    - EMS.h
    - EMS.cpp
  - **employee Class (员工类，是员工管理系统的员工信息部分)**
    - employee.h
    - employee.cpp
  - **accpas Class (账户密码类，是员工管理系统的账号密码部分)**
    - accpas.h
    - accpas.cpp
  - **存储文件 (用于存储账户密码与员工信息)**
    - Employee.txt
    - AccPas.txt
---
## 程序说明文档 | 截图
1. [程序说明](https://github.com/Lingggao/EMS/blob/master/Precautions%20(%E6%B3%A8%E6%84%8F%E4%BA%8B%E9%A1%B9)/%E7%A8%8B%E5%BA%8F%E8%AF%B4%E6%98%8E.md)
2. [关于账户与密码](https://github.com/Lingggao/EMS/blob/master/Precautions%20(%E6%B3%A8%E6%84%8F%E4%BA%8B%E9%A1%B9)/%E5%85%B3%E4%BA%8E%E8%B4%A6%E6%88%B7%E4%B8%8E%E5%AF%86%E7%A0%81.md)
3. ### [程序截图](https://github.com/Lingggao/EMS/tree/master/ProgramScreenshot%20(%E7%A8%8B%E5%BA%8F%E6%88%AA%E5%9B%BE))

---
:star: **衷心感谢您的观看！**:heart:  
—— **Ling Gao (高楷修)**
