#include <iostream>
using namespace std;
class FruitSeller
{
private:
    int APPLE_PRICE; //FruitSeller클래스에서 사용할 사과 가격을 나타내기 위한 APPLE_PRICE 변수 생성
    int numOfApples; //FruitSeller클래스에서 사용할 사과 개수를 나타내기 위한 numOfApples 변수 생성
    int myMoney; //FruitSeller클래스에서 사용할 판매자의 돈을 나타내기 위한 myMoney 변수 생성
public:
    int SaleApples(int money)
    {
        int num = money/APPLE_PRICE; //손님이 주신 금액을 사과 가격으로 나눈 만큼 사과를 팜
        numOfApples-=num; //사과를 팔았으니 원래 있던 사과 개수에서 판 만큼의 개수 num을 뺌
        myMoney+=money; //사과를 팔았으니 손님이 주신 만큼의 돈 money를 얻음
        return num; //남은 사과의 개수를 반환 받음
    }
void InitMembers(int price, int num, int money)
{
    APPLE_PRICE = price; //price 값을 변수 APPLE_PRICE에 넣기
    numOfApples = num; //num 값을 변수 numOfApples에 넣기
    myMoney = money; //money 값을 변수 myMoney에 넣기
}
void ShowSalesResult() //판매 결과를 알려주기 위한 함수 생성
{
    cout<<"남은 사과: "<<numOfApples<<endl; //남은 사과의 개수 출력
    cout<<"판매 수익: "<<myMoney<<endl; //판매 수익을 출력
}
};
class FruitBuyer
{
    int myMoney; //소비자의 돈을 표현하기 위한 변수 myMoney 생성
    int numOfApples; //소비자가 구매한 사과의 개수를 표현하기 위한 변수 numOfApples 생성
public:
    void InitMembers(int money)
    {
        myMoney = money; //money 값을 변수 myMoney에 넣기
        numOfApples = 0; //numOfApples 변수를 0으로 초기화
    }
    void BuyApples(FruitSeller &seller, int money)
    {
        numOfApples+=seller.SaleApples(money); //판 사과의 수를 소비자가 구매한 사과의 개수에 넣기
        myMoney-=money; //구매를 했으니 보유한 돈에서 쓴 만큼의 돈을 뺌
    }
    void ShowBuyResult()
    {
        cout<<"현재 잔액: "<<myMoney<<endl; //사과를 사고 나서 난 잔액을 출력
        cout<<"사과 개수: "<<numOfApples<<endl; //사과를 산 개수 출력
    }
};
int main(void)
{
    FruitSeller * seller = new FruitSeller; //FruitSeller 클래스에서 seller 객체 생성
    seller->InitMembers(1000,20,0); //사과 하나의 가격을 1000원, 사과의 총 개수를 20개, 수익 0으로 설정
    FruitBuyer * buyer = new FruitBuyer; //FruitBuyer 클래스에서 buyer 객체 생성
    buyer->InitMembers(5000); //소비자의 현재 잔액을 5000원으로 설정
    buyer->BuyApples(*seller,2000); //소비자가 2000원어치 사과 구매
    cout<<"과일 판매자의 현황"<<endl; //과일 판매자의 현황을 출력
    seller->ShowSalesResult(); //손님이 사과를 산 후 남은 사과와 판매 수익을 출력
    delete seller;  //할당 받은 메모리를 반납
    cout<<"과일 구매자의 현황"<<endl; //과일 구매자의 현황을 출력
    buyer->ShowBuyResult(); //사과를 산 후 구매자의 잔액과 보유한 사과 개수 출력
    delete buyer; //할당 받은 메모리를 반납
    return 0;
}
