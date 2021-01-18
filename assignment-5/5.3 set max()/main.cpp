#define CATCH_CONFIG_MAIN
#include <iostream>
#include <string>

#include "set.hpp"
#include "catch.hpp"

//int main(){
//}
//


TEST_CASE( "MAX FUNCTION TEST" ){
	set< char, 8 > charSet;
	charSet.add('a');
	charSet.add('b');
	charSet.add('c');
	
	REQUIRE( charSet.max() == 'c' );
}