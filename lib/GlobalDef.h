/*
 * GlobalDef.h
 *
 *  Created on: 7 oct. 2011
 *      Author: mobilette
 */

#ifndef GLOBALDEF_H_
#define GLOBALDEF_H_
#include <sstream>
#include <iostream>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
using namespace std;


template<typename T>
string to_string( const T & Value ){
    ostringstream oss;
    oss << Value;
    return oss.str();
}

#endif /* GLOBALDEF_H_ */
