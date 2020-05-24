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

BigNumber MyBigNumber::unsignedMultiplyOneDigit(int digit) {
    MyBigNumber unMulty;
    unMulty.sign = true;
    unMulty.numOfDigits = numOfDigits + 1;
    unMulty.numArray = new int8_t [unMulty.numOfDigits];
    int8_t y = 0;
    int8_t multy;
    size_t i{0};
    for(; i < numOfDigits ; i++) {
        multy = digit * numArray[i] + y;
        unMulty[i] = multy % 10;
        y = multy /10;
    }
    if(y == 0) {
        unMulty.numOfDigits -= 1;
    }else if(y != 0) {
        unMulty[i] = y;
    }
    int numOfZeroesOnTheLeft = 0;
    size_t index{numOfDigits -1};
    while(unMulty[index] == 0 && index > 0){
        ++numOfZeroesOnTheLeft;
        --index;
    }
    MyBigNumber Multy;
    Multy.sign = true;
    Multy.numOfDigits = unMulty.numOfDigits - numOfZeroesOnTheLeft;
    Multy.numArray = new int8_t[Multy.numOfDigits];
    for(size_t i{0} ; i < Multy.numOfDigits; ++i){
        Multy[i] = unMulty[i];
    }
    return Multy;

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

MyBigNumber MyBigNumber::operator()(unsigned int x, unsigned int y) {
    if( x >= numOfDigits || x <= 0 || y-x > 1 || y <= 0) {
        throw std::out_of_range("enter x or y in range!");
    }
    MyBigNumber cut;
    cut.sign = sign;
    cut.numOfDigits = y;
    cut.numArray = new int8_t [cut.numOfDigits];
    size_t i{0};
    for(; i < y; i++){
        cut[i] = numArray[x - y + 1 + i];
    }
    return cut;
}






