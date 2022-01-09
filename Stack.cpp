#include <iostream>



using namespace std;



class Point //Point 클래스 생성

{

private:

    int xpos, ypos; //변수 xpos , ypos 생성

public:

    Point(int x=0, int y=0) : xpos(x), ypos(y) {} //생성자 호출

    void show()

    {

        cout << "( " << xpos << ", " << ypos << " )" << endl; //변수 xpos와 ypos를 출력하기 위한 함수 생성

    }

};



template <typename T, int len> //template 호출 , 변수 len 생성

class MyStack //MyStack

{

private:

    int tos; //변수 tos 생성

    T data[len]; //len 크기 만큼의 배열 data 생성

public:

    MyStack(); //생성자 호출

    void push(T element); //push 함수 생성

    T pop(); //pop 생성

};

template <typename T, int len>

MyStack<T, len>::MyStack()

{

    tos = -1; //tos를 -1로 초기화

}



template <typename T, int len>

void MyStack<T, len>::push(T element)

{

    if(tos==(len-1)) //data 배열이 꽉 찼다면

    {

        cout << "stack is full" << endl; //stack이 꽉 찼다는 문구 출력

        return;

    }

    tos++; //tos 증가

    data[tos] = element; //인덱스에 순서대로 element 삽입

}



template <typename T, int len>

T MyStack<T, len>::pop()
{

    if(tos==-1) //data 배열에 아무것도 들어있지 않으면

    {

        cout << "stack is empty" << endl; //스택이 비었다는 문구 출력

        return 0;

    }

    T retData = data[tos]; //배열의 인덱스 값을 변수 retData에 넣기

    tos--; //tos 감소

    return retData; //retData 반환

}



typedef Point* POINT_PTR; //Point의 포인터형 변수 POINT_PTR



int main(void)

{

    MyStack<POINT_PTR*, 100> ppStack; //POINT_PTR 포인터형의 크기 100인 배열 ppStack 생성

    POINT_PTR* pArr = new POINT_PTR[3]; //크기 3인 POINT_PTR 포인터형 pArr 배열 생성

    POINT_PTR* qArr; //POINT_PTR 포인터형 배열 qArr

    for(int i=0; i<3; i++){

        pArr[i] = new Point(i, i+1); //순서대로 배열 pArr에 넣기

    }

    ppStack.push(pArr); //배열 ppStack에 배열 pArr 넣기



    qArr = ppStack.pop(); //ppStack 배열의 값을 배열 qArr에 넣기

    for(int i=0; i<3; i++){

        qArr[i]->show(); //차례대로 배열 qArr 값 출력하기

    }



    delete [] pArr; //pArr 지우기

    return 0;

}
