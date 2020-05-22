//
// Created by Jahan on 5/20/2020.
//

#include "MyBigNumber.h"

MyBigNumber MyBigNumber::multyByOneDigit(int digit) {
    MyBigNumber multy;
    if( sign == true && digit >= 0){
        multy = unsignedMultiplyOneDigit(digit);
    }
    if( sign == false && digit >= 0) {
        multy = unsignedMultiplyOneDigit( digit );
        multy.sign = false;
    }
    if( sign == true && digit < 0) {
        multy = unsignedMultiplyOneDigit( digit );
        multy.sign = false;
    }
    if( sign == false && digit < 0) {
        multy = unsignedMultiplyOneDigit( digit );
    }
    return multy;
}

MyBigNumber MyBigNumber::operator<<(unsigned int shift) {
    MyBigNumber power;
    if( shift == 0) {
        return *this
;    } else{
        power.sign = sign;
        power.numOfDigits = numOfDigits + shift;
        power.numArray = new int8_t[ power.numOfDigits];
        size_t i{0};
        for(; i < shift ; i++) {
            power[i] = 0;
        }
        size_t j{shift};
        for(; j < power.numOfDigits; j++){
            power[j] = numArray[j - shift];
        }
        return power;
    }
}
MyBigNumber MyBigNumber::power(int digit ) {
    if( digit < 0){
        throw std::invalid_argument("please enter a positive number!");
    }
    size_t i{1};
    MyBigNumber index = 1;
    for(; i <= digit; i++){
        index = index * (*this);
    }
    return index;
}

MyBigNumber operator*(MyBigNumber &myBigNum1, MyBigNumber &myBigNum2) {
    MyBigNumber multy ="0";
    if(myBigNum1=="0" || myBigNum2=="0") {
        multy = "0";
        multy.sign = true;
    }
    if(myBigNum1.sign == myBigNum2.sign ){
        unsigned int p = 0;
        for(; p < myBigNum2.numOfDigits ; p++) {
            multy = multy + (myBigNum1 << p).multyByOneDigit(myBigNum2[p]);
        }
        multy.sign = true;
    }
    if(myBigNum1.sign == true && myBigNum2.sign == false && myBigNum1 !="0" && myBigNum2 !="0") {
        unsigned int p=0;
        for(;p < myBigNum2.numOfDigits ;p++){
            multy = multy + (myBigNum1<<p).multyByOneDigit(myBigNum2[p]);
        }
        multy.sign = myBigNum2.sign;
    }
    if(myBigNum1.sign == false && myBigNum2.sign == true && myBigNum1 !="0" && myBigNum2 !="0") {
        unsigned int p=0;
        for(; p < myBigNum2.numOfDigits ; p++){
            multy = multy+(myBigNum1 <<p).multyByOneDigit( myBigNum2[p] );
        }
        multy.sign=myBigNum1.sign;
    }
    return multy;
}





