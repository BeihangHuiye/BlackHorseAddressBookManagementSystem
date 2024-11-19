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


// 添加联系人函数
void addPerson(Addressbooks* abs)
{
    // 判断通讯录是否已满，如果满了就不再添加
    if (abs->m_Size == MAX)
    {
        cout << "通讯录已满，无法添加！" << endl;
    }
    else
    {
        // 添加联系人
            // 输入姓名
        string name;
        cout << "请输入姓名：" << endl;
        cin >> name;
        abs->personArray[abs->m_Size].m_Name = name;
            // 输入性别
        cout << "请输入性别：" << endl;
        cout << "1 -- 男" << endl;
        cout << "2 -- 女" << endl;
        int sex = 0;
        cin >> sex;
        while (sex != 1 && sex != 2)
        {
            if (sex == 1 || sex == 2)
            {
                abs->personArray[abs->m_Size].m_Sex = sex;
                break;
            }
            else
            {
                cout << "输入有误，请重新输入！" << endl;
            }
        }

        // 输入年龄
        cout << "请输入年龄：" << endl;
        int age = 0;
        cin >> age;
        abs->personArray[abs->m_Size].m_Age = age;

        // 输入电话
        cout << "请输入电话：" << endl;
        string phone;
        cin >> phone;
        abs->personArray[abs->m_Size].m_Phone = phone;

        // 输入住址
        cout << "请输入住址：" << endl;
        string addr;
        cin >> addr;
        abs->personArray[abs->m_Size].m_Addr = addr;

        // 更新添加成功，人员个数+1
        abs->m_Size++;
        cout << "添加成功！" << endl;

        system("pause"); // 暂停,等待用户按下任意键后继续
        system("cls"); // 清屏

    }
}

// 显示联系人函数
void showPerson(Addressbooks* abs)
{
    // 判断通讯录中是否有联系人
    if (abs->m_Size == 0)
    {
        cout << "通讯录中无联系人！" << endl;
    }
    else
    {
        // 显示通讯录中所有联系人
        for (int i = 0; i < abs->m_Size; i++)
        {
            cout << "姓名：" << abs->personArray[i].m_Name << " ";
            cout << "性别：" << (abs->personArray[i].m_Sex == 1 ? "男" : "女") << " ";
            cout << "年龄：" << abs->personArray[i].m_Age << " ";
            cout << "电话：" << abs->personArray[i].m_Phone << " ";
            cout << "住址：" << abs->personArray[i].m_Addr << endl;
        }
    }
    system("pause"); // 暂停,等待用户按下任意键后继续
    system("cls"); // 清屏
    }

// 检测联系人是否存在
// 如果存在，返回联系人下标，不存在返回-1
int isExist(Addressbooks* abs, string name)
{
    for (int i = 0; i < abs->m_Size; i++)
    {
        if (abs->personArray[i].m_Name == name)
        {
            return i;
        }
    }
    return -1;
}

// 删除联系人函数
void deletePerson(Addressbooks* abs)
{
    string name;
    cout << "请输入您要删除的联系人姓名：" << endl;
    cin >> name;
    int index = isExist(abs, name);
    if (index != -1)
    {
        // 找到了用户输入的联系人
        // 要删除一个用户，可以将该用户后面的联系人全部向前移动一位
        // 数量减一
        
        // 数据前移
        for (int i = index; i < abs->m_Size - 1; i++)
        {
            abs->personArray[i] = abs->personArray[i + 1];
        }
        abs->m_Size--;
    }
    else
    {
        cout << "查无此人！" << endl;
    }
    system("pause"); // 暂停,等待用户按下任意键后继续
    system("cls"); // 清屏
}

void FindPerson(Addressbooks* abs)
{
    string name;
    cout << "请输入您要查找的联系人姓名：" << endl;
    cin >> name;
    int index = isExist(abs, name);
    if (index != -1)
    {
        // 找到了用户输入的联系人
        cout << "姓名：" << abs->personArray[index].m_Name << " ";
        cout << "性别：" << (abs->personArray[index].m_Sex == 1 ? "男" : "女") << " ";
        cout << "年龄：" << abs->personArray[index].m_Age << " ";
        cout << "电话：" << abs->personArray[index].m_Phone << " ";
        cout << "住址：" << abs->personArray[index].m_Addr << endl;
    }
    else
    {
        cout << "查无此人！" << endl;
    }
    system("pause"); // 暂停,等待用户按下任意键后继续
    system("cls"); // 清屏
    }

void ModifyPerson(Addressbooks* abs)
{
    string name;
    cout << "请输入您要修改的联系人姓名：" << endl;
    cin >> name;
    int index = isExist(abs, name);
    if (index != -1)
    {
        // 找到了用户输入的联系人
        cout<<"下面请依次修改信息"<<endl;

        string name2;
        cout << "请输入姓名：" << endl;
        cin >> name2;
        abs->personArray[index].m_Name = name2;

        int sex;
        cout << "请输入性别：" << endl;
        cin >> sex;
        while (sex != 1 && sex != 2)
        {
            cout << "输入有误，请重新输入！" << endl;
            cin >> sex;
        }
        abs->personArray[index].m_Sex = sex;
       
        int age;
        cout << "请输入年龄：" << endl;
        cin >> age;
        abs->personArray[index].m_Age = age;

        string phone;
        cout << "请输入电话：" << endl;
        cin >> phone;
        abs->personArray[index].m_Phone = phone;

        string addr;
        cout << "请输入住址：" << endl;
        cin >> addr;
        abs->personArray[index].m_Addr = addr;
    }
    else
    {
        cout << "查无此人！" << endl;
    }

    system("pause"); // 暂停,等待用户按下任意键后继续
    system("cls"); // 清屏
}

void clearPerson(Addressbooks* abs)
{
    abs->m_Size = 0;  //只是做逻辑上的清空
    cout << "通讯录已清空！" << endl;
    system("pause"); // 暂停,等待用户按下任意键后继续
    system("cls"); // 清屏
}

int main()
{
    // 退出功能，退出通讯录管理系统
    // 根据用户输入的调用对应功能，可以选择switch语句
    // 当用户输入为0时，退出通讯录管理系统
    int select = 0; //用户输入的选项

    // 创建通讯录结构体变量
    Addressbooks abs;
    // 初始化通讯录中人数
    abs.m_Size = 0;

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
         // 5. 在main函数中调用添加联系人函数
        addPerson(&abs); // 指针传递，可以修改结构体中的值
            break;

        case 2:  // 显示联系人
            // 显示通讯录中已有的联系人信息，按照顺序打印出来
            // 如果通讯录中没有联系人，提示用户通讯录中无联系人
        showPerson(&abs);
            break;

        case 3:  // 删除联系人
            // 删除联系人，用户输入联系人姓名，找到该联系人，进行删除操作,如果不存在提示用户联系人不存在
            // 删除联系人设计思路
            // 1. 遍历通讯录，找到用户输入的联系人
            // 2. 如果找到，执行删除操作，将后面的联系人依次覆盖前一个联系人，最后一个联系人置空
            // 3. 如果没有找到，提示用户联系人不存在
        //{
            //int ret = isExist(&abs, name);
            //if (ret != -1)
            //{
            //    cout << "找不到联系人" << endl;
            //}
            //else
            //{
            //    cout << "找到联系人" << endl;
            //}
            deletePerson(&abs);
            break;
        //}
        case 4:  // 修改联系人
            // 修改联系人，用户输入联系人姓名，找到该联系人，根据用户输入修改联系人信息
            // 如果找不到，则提示用户查无此人
            // 修改联系人设计思路：
            // 1. 遍历通讯录，找到用户输入的联系人
            // 2. 如果找到，提示用户输入新的联系人信息，完成对指定联系人的修改
            // 3. 如果没有找到，提示用户查无此人
            ModifyPerson(&abs);
            break;
        case 5:  // 查找联系人
            // 查找联系人，用户输入联系人姓名，找到联系人信息，并显示出来
            // 如果找不到，提示用户查无此人
            FindPerson(&abs);
            break;
        case 6:  // 清空联系人
            // 清空通讯录中所有联系人信息
            // 清空通讯录设计思路
            // 1. 将通讯录中人员有效人数清零
            // 2. 将通讯录中每个联系人信息清空
            clearPerson(&abs);
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

