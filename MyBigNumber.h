//
// Created by Jahan on 5/20/2020.
//

#ifndef TA14_MYBIGNUMBER_H
#define TA14_MYBIGNUMBER_H

#include "BigNumber.h"
#include <string>

class MyBigNumber : public BigNumber{
    friend MyBigNumber operator*(MyBigNumber &myBigNum1 , MyBigNumber &myBigNum2);
private:
    BigNumber unsignedMultiplyOneDigit( int digit );

public:
    MyBigNumber():BigNumber(){};
    MyBigNumber( const std::string & str ):BigNumber( str ){};
    MyBigNumber( const char * myCharArray ) : BigNumber( myCharArray) {};
    MyBigNumber(const long & intNum ):BigNumber(intNum) {};
    MyBigNumber( const BigNumber & myBig ) :BigNumber(myBig) {};   // copy constructor
    MyBigNumber( BigNumber && myBig ) noexcept :BigNumber(myBig) {};  // move constructor
    MyBigNumber multyByOneDigit( int digit);
    MyBigNumber operator<<(unsigned int shift );
    MyBigNumber power( int digit );
    MyBigNumber operator()(unsigned int , unsigned int);

};


#endif //TA14_MYBIGNUMBER_H
