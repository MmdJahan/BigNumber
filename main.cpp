#include <iostream>
#include <cstdint>

#include "BigNumber.h"
#include "MyBigNumber.h"

using namespace std;

int main() {
    cout << boolalpha<< endl;

    MyBigNumber myBigNum1 = -17319;
    MyBigNumber myBigNum2 = "0000173";


    try {
        cout << myBigNum2.power(-1) << endl;
    }
    catch (invalid_argument e) {
        cout << e.what() << endl;
    }

    cout << myBigNum2 - myBigNum1 << endl;
    cout << myBigNum1 + myBigNum2 << endl;
    cout << myBigNum1 * myBigNum2 << endl;
    cout << myBigNum1.multyByOneDigit(4) << endl;
    cout << (myBigNum2<<3) << endl;

    try{
        cout << myBigNum1(2,3)<<endl;
    }
    catch( out_of_range e){
        cout << e.what() << endl;
    }

    cout << "the following outputs are related to class bigNumber" << endl;
    cout << myBigNum2<< endl;
    cout << ++myBigNum2<< endl;
    cout << myBigNum1++<< endl;
    cout << myBigNum1<< endl;
    cout << --myBigNum1<< endl;
    cout << myBigNum1--<< endl;
    cout << myBigNum1<< endl;
    cout << (myBigNum1 < myBigNum2)<< endl;
    cout << (myBigNum1 > myBigNum2)<< endl;
    cout << (myBigNum2 <= myBigNum1)<< endl;
    cout << (myBigNum1 >= myBigNum2)<< endl;
    cout << (myBigNum2 != myBigNum1)<< endl;
    cout << (myBigNum1 = myBigNum2)<< endl;
    cout << (myBigNum1 == myBigNum2)<< endl;
    return 0;
}
