#include<iostream>
using namespace std;
#define MAX 1000 // 最大人数
// 封装函数显示该界面，如 void showMenu()
// 在main函数中调用showMenu()函数
// 菜单界面
void showMenu()
{
	cout << "***************************" << endl;
    cout << "*****  1. 添加联系人  *****" << endl;
    cout << "*****  2. 显示联系人  *****" << endl;
    cout << "*****  3. 删除联系人  *****" << endl;
    cout << "*****  4. 修改联系人  *****" << endl;
    cout << "*****  5. 查找联系人  *****" << endl;
    cout << "*****  6. 清空联系人  *****" << endl;
    cout << "*****  0. 退出通讯录  *****" << endl;
    cout << "***************************" << endl;
}


// 设计联系人结构体
struct Person
{
    string m_Name; // 姓名
    int m_Sex; // 性别 1男 2女
    int m_Age; // 年龄
    string m_Phone; // 电话
    string m_Addr; // 住址
};
// 设计通讯录结构体
struct Addressbooks
{
    struct Person personArray[MAX]; // 保存1000个联系人信息
    int m_Size; // 用来记录通讯录中人员个数
};




int main()
{
    // 退出功能，退出通讯录管理系统
    // 根据用户输入的调用对应功能，可以选择switch语句
    // 当用户输入为0时，退出通讯录管理系统
    int select = 0; //用户输入的选项
    while (true)
    {
        showMenu();
        cin >> select;
        switch (select)
        {
        case 1:  // 添加联系人
         // 联系人数量上限为1000人，当联系人数量达到上限时，提示用户通讯录已满
         // 添加联系人功能，用户输入  姓名、性别、年龄、电话、家庭住址    ，将信息保存到通讯录中
         // 添加联系人的设计思路
         // 1. 先创建一个联系人结构体变量，用来保存用户输入的信息
         // 2. 定义一个通讯录结构体变量，用来保存多个联系人信息
         // 3. main函数中定义一个通讯录结构体变量，用来保存多个联系人信息
         // 4. 封装添加联系人的函数，在函数中完成联系人信息的录入
         // 5. 在main函数中调用添加联系人函数、


            break;
        case 2:  // 显示联系人
            break;
        case 3:  // 删除联系人
            break;
        case 4:  // 修改联系人
            break;
        case 5:  // 查找联系人
            break;
        case 6:  // 清空联系人
            break;
        case 0:  // 退出通讯录
            // 退出功能，退出通讯录管理系统
            // 根据用户输入的调用对应功能，可以选择switch语句
            // 当用户输入为0时，退出通讯录管理系统，输入其他数字时，不进行操作
            cout << "欢迎下次使用" << endl;
            system("pause");
            return 0;
            break;
        default:
            cout << "输入有误，请重新输入" << endl;
            break;
        }
    }

    system("pause");
    return 0;
}

