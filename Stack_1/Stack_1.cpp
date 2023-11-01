/// Stack, 기본적으로 전과 같지만, 포인터 배열 선언됨
#include <iostream>
#define MAX 4
// 구조체 변수 : 서로 다른 데이터형의 묶음으로 변수를 지정.
struct  TNode  // 구조체 변수
{
    char    m_csName;
    int     m_iAge;
    float   m_fData;
};

TNode* g_NodeArray[MAX];// 구조체 포인터 배열 선언

int   g_iTop = -1;
void  Print() // g_NodeArray의 값을 출력
{
    for (int i = 0; i < MAX; i++)
    {
        TNode* node = g_NodeArray[i];
        std::cout << "Name=" << node->m_csName << " "
            << "Age=" << node->m_iAge << " "
            << "float=" << node->m_fData << std::endl;
    }
}
void  DeleteAll() //동적 할당된 메모리 소거
{
    for (int i = 0; i < MAX; i++)
    {   
        delete g_NodeArray[i];
        g_NodeArray[i] = nullptr;
    }
}
bool  push(TNode* t) //구조체 포인터를 받아온다
{
    if (g_iTop >= MAX - 1) //오버플로우인가?
    {
        return false;
    }
    g_NodeArray[++g_iTop] = t;
    return true;
}
TNode* pop()
{
    if (g_iTop < 0)
    {
        return NULL;
    }
    return g_NodeArray[g_iTop--];
}


/// <summary>
/// /
/// </summary>
/// <returns></returns>
int main()
{
    for (int i = 0; i < MAX + 10; i++) //동적 할당 활성화
    {
        TNode* node = new TNode;// 동적할당 시에 언어,컴파일러가 힙 영역 내에서 주소 시작점을 할당함. 그렇지 않을 시에 해당node의 주소가 항상 초기화됨
        (*node).m_csName = 65 + i; // A=65, a=97 아스키코드
        (*node).m_iAge = i;
        (*node).m_fData = 3.14f * i;
        if (push(node) == false)
        {
            delete node;
            node = nullptr;
            break;
        }
    }
    Print();

    TNode node;
    node.m_iAge = 0;
    node.m_fData = 9.9f;
    if (push(&node) == false) //"Stack Overflow! //push함수는 구조체 포인터 변수를 받으므로 node >> &node로 바뀜
    {
        std::cout << "Stack Overflow!" << std::endl;
    }

    for (int i = 0; i < MAX + 10; i++)
    {
        TNode* pNode = pop();
        if (pNode == NULL)
        {
            std::cout << "Stack Underflow!" << std::endl;
            break;
        }
        std::cout << "Name=" << (*pNode).m_csName << " "
            << "Age=" << pNode->m_iAge << " "
            << "float=" << (*pNode).m_fData << std::endl;
    }
    //TNode* nodeReturn = pop();//"Stack Underflow!
    //if (nodeReturn == NULL)
    //{
    //    std::cout << "Stack Underflow!\n";
    //}

    DeleteAll(); //
    std::cout << "Hello World!\n";
}
