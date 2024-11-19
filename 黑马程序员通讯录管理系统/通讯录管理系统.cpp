#include<iostream>
using namespace std;
#define MAX 1000 // �������
// ��װ������ʾ�ý��棬�� void showMenu()
// ��main�����е���showMenu()����
// �˵�����
void showMenu()
{
	cout << "***************************" << endl;
    cout << "*****  1. �����ϵ��  *****" << endl;
    cout << "*****  2. ��ʾ��ϵ��  *****" << endl;
    cout << "*****  3. ɾ����ϵ��  *****" << endl;
    cout << "*****  4. �޸���ϵ��  *****" << endl;
    cout << "*****  5. ������ϵ��  *****" << endl;
    cout << "*****  6. �����ϵ��  *****" << endl;
    cout << "*****  0. �˳�ͨѶ¼  *****" << endl;
    cout << "***************************" << endl;
}

// �����ϵ�˽ṹ��
struct Person
{
    string m_Name; // ����
    int m_Sex; // �Ա� 1�� 2Ů
    int m_Age; // ����
    string m_Phone; // �绰
    string m_Addr; // סַ
};
// ���ͨѶ¼�ṹ��
struct Addressbooks
{
    struct Person personArray[MAX]; // ����1000����ϵ����Ϣ
    int m_Size; // ������¼ͨѶ¼����Ա����
};


// �����ϵ�˺���
void addPerson(Addressbooks* abs)
{
    // �ж�ͨѶ¼�Ƿ�������������˾Ͳ������
    if (abs->m_Size == MAX)
    {
        cout << "ͨѶ¼�������޷���ӣ�" << endl;
    }
    else
    {
        // �����ϵ��
            // ��������
        string name;
        cout << "������������" << endl;
        cin >> name;
        abs->personArray[abs->m_Size].m_Name = name;
            // �����Ա�
        cout << "�������Ա�" << endl;
        cout << "1 -- ��" << endl;
        cout << "2 -- Ů" << endl;
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
                cout << "�����������������룡" << endl;
            }
        }

        // ��������
        cout << "���������䣺" << endl;
        int age = 0;
        cin >> age;
        abs->personArray[abs->m_Size].m_Age = age;

        // ����绰
        cout << "������绰��" << endl;
        string phone;
        cin >> phone;
        abs->personArray[abs->m_Size].m_Phone = phone;

        // ����סַ
        cout << "������סַ��" << endl;
        string addr;
        cin >> addr;
        abs->personArray[abs->m_Size].m_Addr = addr;

        // ������ӳɹ�����Ա����+1
        abs->m_Size++;
        cout << "��ӳɹ���" << endl;

        system("pause"); // ��ͣ,�ȴ��û���������������
        system("cls"); // ����

    }
}

// ��ʾ��ϵ�˺���
void showPerson(Addressbooks* abs)
{
    // �ж�ͨѶ¼���Ƿ�����ϵ��
    if (abs->m_Size == 0)
    {
        cout << "ͨѶ¼������ϵ�ˣ�" << endl;
    }
    else
    {
        // ��ʾͨѶ¼��������ϵ��
        for (int i = 0; i < abs->m_Size; i++)
        {
            cout << "������" << abs->personArray[i].m_Name << " ";
            cout << "�Ա�" << (abs->personArray[i].m_Sex == 1 ? "��" : "Ů") << " ";
            cout << "���䣺" << abs->personArray[i].m_Age << " ";
            cout << "�绰��" << abs->personArray[i].m_Phone << " ";
            cout << "סַ��" << abs->personArray[i].m_Addr << endl;
        }
    }
    system("pause"); // ��ͣ,�ȴ��û���������������
    system("cls"); // ����
    }

// �����ϵ���Ƿ����
// ������ڣ�������ϵ���±꣬�����ڷ���-1
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

// ɾ����ϵ�˺���
void deletePerson(Addressbooks* abs)
{
    string name;
    cout << "��������Ҫɾ������ϵ��������" << endl;
    cin >> name;
    int index = isExist(abs, name);
    if (index != -1)
    {
        // �ҵ����û��������ϵ��
        // Ҫɾ��һ���û������Խ����û��������ϵ��ȫ����ǰ�ƶ�һλ
        // ������һ
        
        // ����ǰ��
        for (int i = index; i < abs->m_Size - 1; i++)
        {
            abs->personArray[i] = abs->personArray[i + 1];
        }
        abs->m_Size--;
    }
    else
    {
        cout << "���޴��ˣ�" << endl;
    }
    system("pause"); // ��ͣ,�ȴ��û���������������
    system("cls"); // ����
}

void FindPerson(Addressbooks* abs)
{
    string name;
    cout << "��������Ҫ���ҵ���ϵ��������" << endl;
    cin >> name;
    int index = isExist(abs, name);
    if (index != -1)
    {
        // �ҵ����û��������ϵ��
        cout << "������" << abs->personArray[index].m_Name << " ";
        cout << "�Ա�" << (abs->personArray[index].m_Sex == 1 ? "��" : "Ů") << " ";
        cout << "���䣺" << abs->personArray[index].m_Age << " ";
        cout << "�绰��" << abs->personArray[index].m_Phone << " ";
        cout << "סַ��" << abs->personArray[index].m_Addr << endl;
    }
    else
    {
        cout << "���޴��ˣ�" << endl;
    }
    system("pause"); // ��ͣ,�ȴ��û���������������
    system("cls"); // ����
    }

void ModifyPerson(Addressbooks* abs)
{
    string name;
    cout << "��������Ҫ�޸ĵ���ϵ��������" << endl;
    cin >> name;
    int index = isExist(abs, name);
    if (index != -1)
    {
        // �ҵ����û��������ϵ��
        cout<<"�����������޸���Ϣ"<<endl;

        string name2;
        cout << "������������" << endl;
        cin >> name2;
        abs->personArray[index].m_Name = name2;

        int sex;
        cout << "�������Ա�" << endl;
        cin >> sex;
        while (sex != 1 && sex != 2)
        {
            cout << "�����������������룡" << endl;
            cin >> sex;
        }
        abs->personArray[index].m_Sex = sex;
       
        int age;
        cout << "���������䣺" << endl;
        cin >> age;
        abs->personArray[index].m_Age = age;

        string phone;
        cout << "������绰��" << endl;
        cin >> phone;
        abs->personArray[index].m_Phone = phone;

        string addr;
        cout << "������סַ��" << endl;
        cin >> addr;
        abs->personArray[index].m_Addr = addr;
    }
    else
    {
        cout << "���޴��ˣ�" << endl;
    }

    system("pause"); // ��ͣ,�ȴ��û���������������
    system("cls"); // ����
}

void clearPerson(Addressbooks* abs)
{
    abs->m_Size = 0;  //ֻ�����߼��ϵ����
    cout << "ͨѶ¼����գ�" << endl;
    system("pause"); // ��ͣ,�ȴ��û���������������
    system("cls"); // ����
}

int main()
{
    // �˳����ܣ��˳�ͨѶ¼����ϵͳ
    // �����û�����ĵ��ö�Ӧ���ܣ�����ѡ��switch���
    // ���û�����Ϊ0ʱ���˳�ͨѶ¼����ϵͳ
    int select = 0; //�û������ѡ��

    // ����ͨѶ¼�ṹ�����
    Addressbooks abs;
    // ��ʼ��ͨѶ¼������
    abs.m_Size = 0;

    while (true)
    {
        showMenu();
        cin >> select;
        switch (select)
        {
        case 1:  // �����ϵ��
         // ��ϵ����������Ϊ1000�ˣ�����ϵ�������ﵽ����ʱ����ʾ�û�ͨѶ¼����
         // �����ϵ�˹��ܣ��û�����  �������Ա����䡢�绰����ͥסַ    ������Ϣ���浽ͨѶ¼��
         // �����ϵ�˵����˼·
         // 1. �ȴ���һ����ϵ�˽ṹ����������������û��������Ϣ
         // 2. ����һ��ͨѶ¼�ṹ�������������������ϵ����Ϣ
         // 3. main�����ж���һ��ͨѶ¼�ṹ�������������������ϵ����Ϣ
         // 4. ��װ�����ϵ�˵ĺ������ں����������ϵ����Ϣ��¼��
         // 5. ��main�����е��������ϵ�˺���
        addPerson(&abs); // ָ�봫�ݣ������޸Ľṹ���е�ֵ
            break;

        case 2:  // ��ʾ��ϵ��
            // ��ʾͨѶ¼�����е���ϵ����Ϣ������˳���ӡ����
            // ���ͨѶ¼��û����ϵ�ˣ���ʾ�û�ͨѶ¼������ϵ��
        showPerson(&abs);
            break;

        case 3:  // ɾ����ϵ��
            // ɾ����ϵ�ˣ��û�������ϵ���������ҵ�����ϵ�ˣ�����ɾ������,�����������ʾ�û���ϵ�˲�����
            // ɾ����ϵ�����˼·
            // 1. ����ͨѶ¼���ҵ��û��������ϵ��
            // 2. ����ҵ���ִ��ɾ�����������������ϵ�����θ���ǰһ����ϵ�ˣ����һ����ϵ���ÿ�
            // 3. ���û���ҵ�����ʾ�û���ϵ�˲�����
        //{
            //int ret = isExist(&abs, name);
            //if (ret != -1)
            //{
            //    cout << "�Ҳ�����ϵ��" << endl;
            //}
            //else
            //{
            //    cout << "�ҵ���ϵ��" << endl;
            //}
            deletePerson(&abs);
            break;
        //}
        case 4:  // �޸���ϵ��
            // �޸���ϵ�ˣ��û�������ϵ���������ҵ�����ϵ�ˣ������û������޸���ϵ����Ϣ
            // ����Ҳ���������ʾ�û����޴���
            // �޸���ϵ�����˼·��
            // 1. ����ͨѶ¼���ҵ��û��������ϵ��
            // 2. ����ҵ�����ʾ�û������µ���ϵ����Ϣ����ɶ�ָ����ϵ�˵��޸�
            // 3. ���û���ҵ�����ʾ�û����޴���
            ModifyPerson(&abs);
            break;
        case 5:  // ������ϵ��
            // ������ϵ�ˣ��û�������ϵ���������ҵ���ϵ����Ϣ������ʾ����
            // ����Ҳ�������ʾ�û����޴���
            FindPerson(&abs);
            break;
        case 6:  // �����ϵ��
            // ���ͨѶ¼��������ϵ����Ϣ
            // ���ͨѶ¼���˼·
            // 1. ��ͨѶ¼����Ա��Ч��������
            // 2. ��ͨѶ¼��ÿ����ϵ����Ϣ���
            clearPerson(&abs);
            break;
        case 0:  // �˳�ͨѶ¼
            // �˳����ܣ��˳�ͨѶ¼����ϵͳ
            // �����û�����ĵ��ö�Ӧ���ܣ�����ѡ��switch���
            // ���û�����Ϊ0ʱ���˳�ͨѶ¼����ϵͳ��������������ʱ�������в���
            cout << "��ӭ�´�ʹ��" << endl;
            system("pause");
            return 0;
            break;
        default:
            cout << "������������������" << endl;
            break;
        }
    }

    system("pause");
    return 0;
}

