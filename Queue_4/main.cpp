#include <iostream>
#include "queue.h"

int main()
{
    {
        TQueue queue1;
        TQueue queue(100);
        queue.Enqueue(9);
        queue.Enqueue(6);
        queue.Enqueue(5);
        queue.Enqueue(3);
        queue.Display();

        // ��������� ȣ��
        TQueue queueCopy = queue;
        std::cout << "Hello World!\n";
    }
    std::cout << "Hello World!\n";
}
