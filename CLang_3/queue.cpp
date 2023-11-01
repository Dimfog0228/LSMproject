
#include <iostream>
#include <Windows.h>
#define MAX 4

int nowin = 0;
int nowout = 0;
int in = 0;
int queueArray[MAX];

void give() {
    if (in < MAX) {
        queueArray[nowin] = rand();
        nowin = ++nowin % MAX;
        ++in;
    }
    else {
        std::cout << "no" << std::endl;
    }
}

void take() {
    if (in > 0) {
        queueArray[nowout] = 0;
        nowout = ++nowout % MAX;
        --in;
    }
    else {
        std::cout << "nooo" << std::endl;
    }

}

int main()
{
    std::cout << "뽑은 숫자가 5보다 작으면 숫자를 넣고, 아니면 뺍니다" << std::endl;
    while (1) {
        std::cout << "=========================" << std::endl << std::endl;
        int x = rand()%8;
        std::cout << "뽑은 숫자 "<< x << std::endl;
        if (x < 5) {
            give();
            //Sleep(2000);
        }
        else {
            take();
            //Sleep(2000);
        }
        
    } 
}


