#include <iostream>
using namespace std;
class Circle {
public:
    int radius; //반지름을 받기 위한 변수 radius 생성
    double getArea(); // 원의 넓이를 받기 위한 변수 getArea 생성
};
double Circle::getArea(){ //Circle 클래스에서 getArea객체 생성
    return 3.14 * radius * radius; //원의 넓이를 구한 후 값을 반환
}
int main()
{
    Circle *donut = new Circle; //Circle 클래스에서 donut 객체 생성
    donut->radius = 1; //반지름을 1로 설정하고 radius에 donut 변수 넣기
    double area = donut->getArea(); //donut으로 구한 원의 넓이를 객체 getArea에 넣기
    cout << "donut area is " << area << endl; //도넛의 넓이를 출력
    delete donut; //할당 받은 메모리를 반납

    Circle *pizza = new Circle; //Circle 클래스에서 pizza 객체 생성
    pizza->radius = 30; //반지름을 30으로 설정하고 radius에 pizza 변수 넣기
    area = pizza->getArea(); //pizza로 구한 원의 넓이를 객체 getArea에 넣기
    cout << "pizza area is " << area << endl; //피자의 넓이를 출력
    delete pizza; //할당 받은 메모리를 반납

    return 0;
}
