/// Stack
#include <iostream>
#define MAX 1
// 구조체 변수 : 서로 다른 데이터형의 묶음으로 변수를 지정.
struct  TNode  // 구조체 변수
{//구조체에 여러 타입의 변수 선언 가능
    char    m_csName;
    int     m_iAge;
    float   m_fData;
};

TNode  g_NodeArray[MAX];// MAX크기의 구조체 배열 선언(전역변수)

int   g_iTop = 0;

bool  push(TNode t) // 구조체를 받아오며, 불리언 값을 반환한다
{
    if (g_iTop >= MAX)
    {
        return false;
    }
    g_NodeArray[g_iTop++] = t; //g_iTop에 1을 더하고(전위연산자) 그 번째의 g_NodeArray 내부에 받아온 구조체를 덮어쓴다
    return true;
}
TNode* pop() //구조체의 주소값을 반환한다, g_NodeArray의 g_iTop번째 주소값을 반환하고 g_iTop-1(후위연산자)
{
    if (g_iTop == 0)
    {
        return NULL;
    }
    return &g_NodeArray[--g_iTop];
}

/// <summary>
/// 값이 복사되어 반환된다.
/// 새로운 반환 변수가 생성되서 값이 복사되어 반환된다.
/// </summary>

//int g_iTemp = 1000;
//int Fun()
//{
//    return g_iTemp;
//}

/// <summary>
/// /
/// </summary>
/// <returns></returns>
int main()
{
    //int  iRet=Fun();

    for (int i = 0; i < MAX + 10; i++) //구조체 인스턴스를 만들고, i값에 따라 바뀐 값을 전역 구조체 인스턴스에 대입하려고 함. 조건 분기는 
    {
        TNode node; //해당 for문 내에서만 존재하는(스택) 구조체 인스턴스 node 생성
        node.m_csName = 65 + i; // A=65, a=97
        node.m_iAge = i;
        node.m_fData = 3.14f * i; // 값 넣고
        if (push(node) != true) //push 함수에 node 넣었을 때 flase 반환이면 중단(가득 채웠는지==넣을 수 있는 조건인가)
        {
            break;
        }
        std::cout << "Name=" << node.m_csName << " " //true 반환이면 node 인스턴스 내의 값들을 출력
            << "Age=" << node.m_iAge << " "
            << "float=" << node.m_fData << std::endl;
    }

    //std::cout << "새로운 node!" << std::endl;


    TNode node; //main 함수 내에서만 존재하는 구조체 인스턴스 node 생성, 해당 인스턴스 미선언시, 빌드 실패(for문에서 만든 node는 스택 메모리에서 없어지므로)
    node.m_iAge = 0;
    node.m_fData = 9.9f; //인스턴스 내의 변수들에 값 입력(초기화)

    if (push(node) == false) //"Stack Overflow!
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
    //TNode* nodeReturn = pop();//"Stack Underflow!...&g_NodeArray[g_iTop] 값으로 nodeReturn 값을 초기화 
    //if (nodeReturn == NULL) //&g_NodeArray[g_iTop]가 NULL값이면 언더플로우 출력
    //{
    //    std::cout << "Stack Underflow!(스택이 비어있음으로 확인됨)\n";
    //}
   // std::cout << "Hello World!\n"; //메인함수 끝
}
