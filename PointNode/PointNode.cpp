#include <iostream>
int   Fun1(int pData) //정수 데이터를 받아옴
{
    return 0;
}
int   Fun1(int* pData) //포인터 데이터를 받아옴
{
    if (pData == nullptr) return -999999; //받아온 포인터의 값이 nullptr이면 -999999를 반환함

    int iSum = *pData + 100; //nullprt이 아니면 받아온 포인터(주소)가 가리키는 값에 100을 더함
    return iSum; //그리고 iSum을 반환함
}
// int a = 100;  Fun1(&a)
int* Fun2(int* pData) //위의 Fun1*와 같음
{
    *pData += 100;
    return pData;
}
// int a = 100;  int*c = Fun2(&a)

/// <summary>
/// 값이 복사되어 반환된다.
/// 새로운 반환 변수가 생성되서 값이 복사되어 반환된다.
/// </summary>
int g_iTemp = 1000;
int Fun()
{
    return g_iTemp; //전역변수 g_iTemp를 반환한다
}

int main()
{
    int aa = 0; //전역변수와
    {
        int aa = 1;
        {
            int aa = 2;
        }
        int bb = aa;
    }
    int bb = aa; ////지역변수의 차이

    int  iRet = Fun();
    Fun1(NULL);
    Fun1(nullptr); //함수의 이름은 같으나, 받아오는 값의 타입으로 구분된다

    int a = 100;
    Fun1(&a); //주소에 접근 = 포인터 변수 Fun1로 이동
    int* c = Fun2(&a); //마찬가지


    int* p1 = &a; //포인터 변수 p1의 값은 int 변수 a의 주소값을 가짐
    int* p2 = nullptr; //권장됨
    int* p3 = NULL; //권장하지 않음
    int* p4 = NULL; //않음
    int* link = p1; // 포인터 변수 link의 값은 p1의 값을 가짐, p1의 값은 &a, link == p1 == &a가 된다

    if (p1 == link && link == &a)
        std::cout << "ㅇ"; //참임을 알 수 있음
}
