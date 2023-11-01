/// Queue
#include <iostream>
#define MAX 10

struct  TNode  // 구조체 변수
{
    char    m_csName;
    int     m_iAge;
    float   m_fData;
};
TNode* g_pQuqueArray[MAX];// 구조체 배열 선언
int   g_iIn = 0;
int   g_iOut = 0;
void  Print()
{
    for (int i = 0; i < MAX; i++)
    {
        TNode* node = g_pQuqueArray[i];
        if (node == nullptr) break;
        std::cout << "Name=" << node->m_csName << " "
            << "Age=" << node->m_iAge << " "
            << "float=" << node->m_fData << std::endl;
    }
}
void  DeleteAll()
{
    for (int i = 0; i < MAX; i++)
    {
        
        delete g_pQuqueArray[i];// 동적할당된 메모리 소거
        g_pQuqueArray[i] = nullptr;
    }
}
void  push(TNode* t)
{
    // 항상 1개의 방은 나머지가 존재한다.
    if ((g_iIn + 1) % MAX == g_iOut)
    {
        std::cout << "Queue Overflow!\n";
        return;
    }
    g_pQuqueArray[g_iIn] = t;
    g_iIn = ++g_iIn % MAX;
}
TNode* pop()
{
    if (g_iIn == g_iOut)
    {
        std::cout << "Stack Underflow!\n";
        return nullptr;
    }
    TNode* pNode = g_pQuqueArray[g_iOut];
    g_iOut = ++g_iOut % MAX;
    return pNode;
}
int main()
{
    for (int i = 0; i < MAX - 1; i++)
    {
        TNode* node = new TNode;
        node->m_csName = 65 + i; // A=65, a=97
        node->m_iAge = i;
        node->m_fData = 3.14f * i;
        push(node);

        if (i == MAX - 1) delete node; //마지막 반복에서 i++로 인해 i<MAX -1이 거짓이 되었는데 이는 i == MAX -1이 되었기 때문이다. 그러므로 마지막 반복의 마지막 부분에서 동적 할당된 node를 해제시킬 수 있다.
    }

    TNode node;
    node.m_csName = 65 + 5; // A=65, a=97
    node.m_iAge = 5;
    node.m_fData = 3.14f * 5;
    push(&node);//"Stack Overflow!

    Print();

    for (int i = 0; i < MAX - 1; i++)
    {
        TNode* pNode = pop();
        if (pNode != nullptr)
        {
            std::cout << "Name=" << (*pNode).m_csName << " "
                << "Age=" << pNode->m_iAge << " "
                << "float=" << (*pNode).m_fData << std::endl;

        }
    }
    TNode* pNode = pop();//"Stack Underflow!


    DeleteAll();
    std::cout << "Hello World!\n";
}
