#include <iostream>
using namespace std;
bool average(int [], int, int&); //bool형 인자를 반환하기 위한 함수 생성
int main(void)
{
    int x[] = { 4, 8, 16, 32 };
	int avg = 0; //avg라는 변수 0값으로 초기화
	if (average(x, 4, avg)) //배열의 값이 양수인 경우 true를 반환받음
            cout << avg << endl; //true를 반환 받아서 평균값을 출력
        else
            cout << "매개변수 오류" << endl;
        if (average(x, -2, avg)) //배열의 값이 음수인 경우 false를 반환받음
            cout << avg << endl;
        else
	    cout << "매개변수 오류" << endl;//false를 반환받아 "매개변수 오류" 문구 출력
	    return 0;
}
bool average(int arr[], int len, int& avg) //main에 있는 avg를 참조
{
    int sum = 0; //총합 sum을 0으로 초기화
    if(len > 0) { //배열의 값이 양수인 경우
        for(int i=0; i<len; i++) //배열의 첫번째부터 배열의 끝까지
    {
        sum += arr[i]; //첫 배열의 수부터 더하여 총합을 구함
    }
    avg = sum / len; //총합에서 갯수를 나누어 평균을 구함
    return true; //배열의 값이 양수이므로 bool형 인자인 true 값을 받는다
    }else { //배열의 값이 음수인 경우
    return false;//배열의 값이 음수이므로 bool형 인자인 false 값을 받는다
    }
}
