#include <iostream>

using namespace std;

int digitSquareSum(int n){
    int sum = 0;
    while(n != 0){
        n = n % 10;
        sum += n * n;
        n /= 10;
    }
    return sum;
}

bool isHappyNumber(int n){
    int slow = n;
    int fast = digitSquareSum(n);

    while(fast != 1){
        slow = digitSquareSum(slow);
        fast = digitSquareSum(digitSquareSum(fast));
    }

    if(fast == 1)
        return true;
    else
        return false;
}

int main(){
    int n;
    cin >> n;
    if(isHappyNumber(n)){
        cout << "Happy Number";
    } else {
        cout << "Not a Happy Number";
    }
    return 0;
}

