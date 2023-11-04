/// Quque
#include <windows.h>
#include <iostream>
#define MAX 3
int   iQuqueArray[MAX];
int   In;
int   Out;
int   count;

void  InitQuque() //ť�� �ʱ�ȭ��ŵ�ϴ�.
{
    In = Out = count = 0; 
    memset(iQuqueArray, 0, sizeof(int) * MAX); //Ÿ���� ������ * ������ŭ �迭�� �޸𸮸� �����մϴ�. �޸� ���� �� ���� 0�Դϴ�.
}

int  push(int t)
{
    // �׻� 1���� ���� �������� �����Ѵ�.
    if (count +1 >= MAX)
    {
        return -1;
    }
    iQuqueArray[In] = t;
    In = ++In % MAX;
    count++;
    return t;
}
int   pop()
{
    if (count == 0)
    {
        return -1;
    }
    int iData = iQuqueArray[Out];
    Out = ++Out % MAX;
    count--;
    return iData;
}



int main()
{
    InitQuque();

    int iWorkCounter = 10; //�ݺ��� Ƚ��
    int iWork = 0; //������ ������ ���ϱ� ���� ����
    srand(time(NULL));// ����(��������) �߻� �ʱ�ȭ
    while (iWorkCounter-- > 0)
    {
        iWork = rand() % 3; //0~2 �� 1���� ������ ��

        if (iWork == 0 || iWork == 1) // input
        {
            std::cout << "input ->";
            int iData = rand() % 100;// 0 ~ 99 �� ������ ����
            int iRet = push(iData); //�Լ��� �̵�, �迭�� ������ return���� iRet�� �ְ�
            if (iRet == -1) //push���� �����÷ο� �����ϸ�
            {
                std::cout << "Stack Overflow!\n";
            }
            else //�����÷ο� �ƴϸ� ���� �� ���
            {
                std::cout << iData << " Input in="
                    << In << " "
                    << " out=" << Out << std::endl;
            }
        }

        else  // output
        {
            std::cout << "output ->";
            int iRet = pop();
            if (iRet == -1)
            {
                std::cout << "Stack Underflow!\n";
            }
            else
            {
                std::cout << iRet << " output in="
                    << In << " "
                    << " out=" << Out << std::endl;
            }
        }
        Sleep(1000); //  1�� ����
    }
    std::cout << "Hello World!\n";
}
