///  Queue
#include <iostream>
#define MAX 10
int   iQuqueArray[MAX];
int   In = 0;
int   Out = 0;
int   count = 0;

void  push(int t)
{
    // �׻� 1���� ���� �������� �����Ѵ�.
    if (count +1 >= MAX) //
    {
        std::cout << "Queue Overflow!\n";
        return;
    }
    iQuqueArray[In] = t;
    In = ++In % MAX;
    count++;
}


int   pop()
{
    if (count == 0)
    {
        std::cout << "Stack Underflow!\n";
        return -1;
    }
    int iData = iQuqueArray[Out];
    Out = ++Out % MAX;
    return iData;
    count--;
}
int main()
{
    for (int i = 0; i < MAX - 1; i++)
    {
        push(i);
    }
    push(10);//"Stack Overflow!

    for (int i = 0; i < MAX - 1; i++)
    {
        int iValue = pop();
        std::cout << iValue << " ";
    }
    pop();//"Stack Underflow!

    std::cout << "Hello World!\n";
}
