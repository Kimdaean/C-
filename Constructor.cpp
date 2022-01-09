#include<iostream>
#include<cstring>
#define LEN 16
using namespace std;
class CopyConstructor
{
private:
    char* str_s;
public:
    CopyConstructor(char* str_x) //생성자 생성
    {
        str_s = new char[strlen(str_x)+1]; //str_s 배열 생성
        strcpy(str_s,str_x); //str_s 배열에 str_x 저장
    }
    CopyConstructor(const CopyConstructor& origin) //복사 생성자 생성
    {
        str_s = new char[strlen(origin.str_s)+1]; //str_s 배열 생성
        strcpy(str_s,origin.str_s); //str_s 배열에 origin 저장
    }
    void concatenate(const char *str) //문자를 합치기 위한 함수 생성
    {
        strcat(str_s, str); //입력 받은 값과 str_s를 합치기
    }
    ~CopyConstructor() //소멸자 생성
    {
        delete []str_s; //변수 str_s에 저장된 값을 삭제

    }
     void ShowStr() //입력받은 값을 출력하기 위한 함수 생성
    {
        cout<<str_s<<endl; //str_s 출력
    }
};
int main()
{
    CopyConstructor c1("Copy"); //변수 c1에 "Copy" 저장
    CopyConstructor c2(c1); //c1의 값만을 저장
    c1.ShowStr(); //c1의 값을 출력
    c2.ShowStr(); //c2의 값을 출력
    c1.concatenate("Constructor"); //c1과 "Constructor"을 합치기
    c1.ShowStr(); //c1의 값을 출력
    c2.ShowStr(); //c2의 값을 출력
    return 0;
