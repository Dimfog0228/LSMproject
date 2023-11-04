/// Quque
#include <windows.h>
#include <iostream>
#define MAX 3
int   iQuqueArray[MAX];
int   In;
int   Out;
int   count;

void  InitQuque() //큐를 초기화시킵니다.
{
    In = Out = count = 0; 
    memset(iQuqueArray, 0, sizeof(int) * MAX); //타입의 사이즈 * 개수만큼 배열의 메모리를 설정합니다. 메모리 내에 들어갈 값은 0입니다.
}

int  push(int t)
{
    // 항상 1개의 방은 나머지가 존재한다.
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

    int iWorkCounter = 10; //반복할 횟수
    int iWork = 0; //넣을지 꺼낼지 정하기 위한 변수
    srand(time(NULL));// 난수(무작위수) 발생 초기화
    while (iWorkCounter-- > 0)
    {
        iWork = rand() % 3; //0~2 중 1개가 값으로 들어감

        if (iWork == 0 || iWork == 1) // input
        {
            std::cout << "input ->";
            int iData = rand() % 100;// 0 ~ 99 중 임의의 값을
            int iRet = push(iData); //함수로 이동, 배열에 넣은뒤 return값을 iRet에 넣고
            if (iRet == -1) //push에서 오버플로우 감지하면
            {
                std::cout << "Stack Overflow!\n";
            }
            else //오버플로우 아니면 넣은 값 출력
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
        Sleep(1000); //  1초 마다
    }
    std::cout << "Hello World!\n";
}
